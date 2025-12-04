#include "../models/aeroport.h"
#include "../models/avion.h"
#include <stdio.h>
#include <stdlib.h>

avion *creerAvion(Aeroport *airport) {
  avion *newAvion = malloc(sizeof(avion));
  if (!newAvion)
    return NULL;
  newAvion->id = airport->total_avions++;
  newAvion->categorie = (CATEGORIE_AVION)(rand() % 3);
  newAvion->etat = 0;
  newAvion->nombre_de_passagers = 0;
  newAvion->heure = 0;
  newAvion->next = NULL;
  newAvion->prev = NULL;
  return newAvion;
}

avion *rechercherAvion(AvionFile *file, int id) {
  if (!file)
    return NULL;
  avion *current = file->premier;
  while (current != NULL) {
    if (current->id == id) {
      return current;
    }
    current = current->next;
  }
  return NULL;
}

void retirerAvion(AvionFile *file, int id) {
  if (!file) {
    printf("\n file attendue en entrée vide dans la fonction retirerAvion "
           "(avionController)\n");
    return;
  }

  /* On parcourt la file en mémorisant le précédent pour être sûr
   * d'utiliser les bons pointeurs, même si l'avion a été réutilisé
   * dans une autre file entre-temps. */
  avion *current = file->premier;
  avion *prev = NULL;
  while (current && current->id != id) {
    prev = current;
    current = current->next;
  }

  if (!current) {
    printf("\n avion rechercher pas trouvé dans la fonction fonction "
           "retirerAvion (avionController)\n");
    return;
  }

  /* Mise à jour des extrémités de la file si besoin. */
  if (current == file->premier) {
    file->premier = current->next;
  }
  if (current == file->dernier) {
    file->dernier = prev;
  }

  /* Rechaînage local dans la file concernée. */
  if (prev) {
    prev->next = current->next;
  }
  if (current->next) {
    current->next->prev = prev;
  }

  /* L'avion est détaché de cette file : on nettoie ses pointeurs,
   * mais on ne le libère pas, car il peut être réutilisé ailleurs. */
  file->nbElement--;
  current->next = current->prev = NULL;
  return;
}
