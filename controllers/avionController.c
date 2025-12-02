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

avion *retirerAvion(AvionFile *file, int id) {
  if (!file)
    return NULL;
  avion *aSupprimer = rechercherAvion(file, id);
  if (!aSupprimer)
    return NULL;

  if (file->nbElement == 1) {
    /* seul élément */
    file->premier = NULL;
    file->dernier = NULL;
  } else if (aSupprimer == file->premier) {
    /* tête */
    file->premier = aSupprimer->next;
    if (file->premier)
      file->premier->prev = NULL;
  } else if (aSupprimer == file->dernier) {
    /* queue */
    file->dernier = aSupprimer->prev;
    if (file->dernier)
      file->dernier->next = NULL;
  } else {
    /* milieu */
    if (aSupprimer->prev)
      aSupprimer->prev->next = aSupprimer->next;
    if (aSupprimer->next)
      aSupprimer->next->prev = aSupprimer->prev;
  }

  file->nbElement--;
  aSupprimer->next = aSupprimer->prev = NULL;
  return aSupprimer;
}
