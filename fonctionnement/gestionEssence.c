#include "gestionEssence.h"
#include "aeroport.h"
#include "avion.h"
#include "avionController.h"
#include <stdio.h>
#include <stdlib.h>

int fuel_check(avion *plane) {
  if (plane->carburant <= 0) {
    return 0;
  }
  return 1;
}

void remplir_carburant(avion *plane) { plane->carburant = 100; }

void consume_carburant_vol(Aeroport *airport) {
  if (!airport || !airport->liste_avions_en_vol)
    return;

  avion *current = airport->liste_avions_en_vol->premier;
  while (current) {
    avion *next = current->next;
    current->carburant -= 5; /* Perte de 5 unités par cycle en vol */

    /* Alerte carburant faible */
    if (current->carburant <= 20 && current->carburant > 0) {
      printf("ALERTE CARBURANT: L'avion %d a moins de 20 unités! (Carburant: "
             "%d)\n",
             current->id, current->carburant);
    }

    /* Crash si carburant épuisé */
    if (current->carburant <= 0) {
      printf("CRASH! L'avion %d s'est écrasé par manque de carburant!\n",
             current->id);
      avion *toFree = current;
      int idToRemove = current->id;
      retirerAvion(airport->liste_avions_en_vol, idToRemove);
      if (toFree) {
        free(toFree);
      }
    }
    current = next;
  }
}