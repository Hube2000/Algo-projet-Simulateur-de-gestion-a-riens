#include "aeroport.h"
#include "avion.h"
#include "avionController.h"
#include <stdio.h>
#include <stdlib.h>
#include "../UI/events_ui.h"
#include "../UI/logs_ui.h"

/* EVENT DISPONIBLES
- Météo -> Decale le temps de décollage + random (selon gravite )->
(pluie,orage,neige)
- Attaque terroriste -> Detruit un avion en vol

*/

void MeteoEvent(Aeroport *aeroport) {
  int meteo = rand() % 3; // 0: pluie, 1: orage, 2: neige
  int decalage;

  switch (meteo) {
  case 0:
    decalage =
        (2 + rand() % 3) * 5; // Décalage entre 10 et 15 minutes (multiple de 5)
    printf("Météo : Pluie Décalage des décollages de %d minutes.\n", decalage);
    ecrire_event_UI("METEO", "Pluie - Decalage des decollages");
    ecrire_log_activite("EVENEMENT", "Pluie - Decollages decales");
    break;
  case 1:
    decalage =
        (4 + rand() % 3) * 5; // Décalage entre 20 et 25 minutes (multiple de 5)
    printf("Météo : Orage Décalage des décollages de %d minutes.\n", decalage);
    ecrire_event_UI("METEO", "Orage - Decalage des decollages");
    ecrire_log_activite("EVENEMENT", "Orage - Decollages decales");
    break;
  case 2:
    decalage =
        (6 + rand() % 3) * 5; // Décalage entre 30 et 35 minutes (multiple de 5)
    printf("Météo : Neige Décalage des décollages de %d minutes.\n", decalage);
    ecrire_event_UI("METEO", "Neige - Decalage des decollages");
    ecrire_log_activite("EVENEMENT", "Neige - Decollages decales");
    break;
  default:
    decalage = 0;
    break;
  }

  for (int i = 0; i < 3; i++) {
    PISTE *piste = aeroport->pistes[i];
    if (piste && piste->liste_avions_attente) {
      avion *current = piste->liste_avions_attente->premier;
      while (current) {
        current->heure += decalage;
        current = current->next;
      }
    }
  }
}

void AttaqueTerroristeEvent(Aeroport *aeroport) {
  if (aeroport->liste_avions_en_vol->nbElement == 0) {
    printf("Aucun avion en vol pour être ciblé.\n");
    return;
  }
  int randomIndex = rand() % aeroport->liste_avions_en_vol->nbElement;
  avion *current = aeroport->liste_avions_en_vol->premier;
  for (int i = 0; i < randomIndex; i++) {
    current = current->next;
  }
  printf("L'avion ID %d a été ciblé et s'est écrasé.\n", current->id);
  ecrire_event_UI("ATTAQUE", "Attaque terroriste - Avion crash");
  char log_msg[100];
  sprintf(log_msg, "CRASH - Avion ID %d détruit", current->id);
  ecrire_log_activite("EVENEMENT", log_msg);
  retirerAvion(aeroport->liste_avions_en_vol, current->id);
}

void triggerRandomEvent(Aeroport *airport) {
  if (!airport) {
    return;
  }
  int random = rand() % 100;
  if (random < 3) {
    MeteoEvent(airport);
  } else if (random >= 3 && random < 5) {
    AttaqueTerroristeEvent(airport);
  }
}