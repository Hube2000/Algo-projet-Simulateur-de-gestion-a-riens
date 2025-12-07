#include "avionController.h"
#include "aeroport.h"
#include "avion.h"
#include <stdio.h>
#include <stdlib.h>

avion *creerAvion(Aeroport *airport) {
  avion *newAvion = malloc(sizeof(avion));
  if (!newAvion)
    return NULL;
  newAvion->id = airport->total_avions++;
  newAvion->categorie = (CATEGORIE_AVION)(rand() % 3);
  newAvion->etat = 0;
  newAvion->nombre_de_passagers = rand() % 200 + 1;
  newAvion->heure = 0;
  newAvion->carburant = 100;
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

  // Mettre à jour les pointeurs de la liste
  if (current == file->premier) {
    // C'est le premier élément
    file->premier = current->next;
    if (file->premier) {
      file->premier->prev = NULL;
    }
  } else {
    // Ce n'est pas le premier élément, donc prev ne devrait jamais être NULL
    if (!prev) {
      printf("\n [ERREUR] prev est NULL mais current n'est pas le premier!\n");
      return;
    }
    prev->next = current->next;
  }

  if (current == file->dernier || current->next == NULL) {
    // C'est le dernier élément
    file->dernier = prev;
  } else {
    // Ce n'est pas le dernier élément
    if (current->next) {
      current->next->prev = prev;
    }
  }

  file->nbElement--;

  if (file->nbElement == 0) {
    file->premier = NULL;
    file->dernier = NULL;
  }

  // Nettoyer les pointeurs de l'avion retiré
  current->next = NULL;
  current->prev = NULL;
  return;
}
