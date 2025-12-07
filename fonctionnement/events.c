#include "aeroport.h"
#include "avion.h"
#include "avionController.h"
#include <stdio.h>
#include <stdlib.h>
#include "../UI/events_ui.h"
#include "../UI/logs_ui.h"

void MeteoEvent(Aeroport *aeroport) {
  int meteo = rand() % 3; // 0: pluie, 1: orage, 2: neige
  int decalage;

  switch (meteo) {
  case 0:
    decalage = (2 + rand() % 3) * 5;
    printf("Météo : Pluie Décalage des décollages de %d minutes.\n", decalage);
    ecrire_event_UI("METEO", "Pluie - Decalage des decollages");
    ecrire_log_activite("EVENEMENT", "Pluie - Decollages decales");
    break;
    
  case 1:
    decalage = (4 + rand() % 3) * 5;
    printf("Météo : Orage Décalage des décollages de %d minutes.\n", decalage);
    ecrire_event_UI("METEO", "Orage - Decalage des decollages");
    ecrire_log_activite("EVENEMENT", "Orage - Decollages decales");
    break;
    
  case 2:
    decalage = (6 + rand() % 3) * 5;
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
  ecrire_event_UI("CRASH", "Avion crash");

  char log_msg[100];
  sprintf(log_msg, "CRASH - Avion ID %d détruit", current->id);
  ecrire_log_activite("EVENEMENT", log_msg);

  retirerAvion(aeroport->liste_avions_en_vol, current->id);
}

void HackEvent(Aeroport *aeroport) {
  if (!aeroport) {
    return;
  }

  printf("Systèmes de l'aéroport piratés !\n");
//j'ai peur boooh fais le hack et paff ca fait des chocapicks 
ecrire_event_UI("HACK", "Systemes pirates - Perturbations");
  ecrire_log_activite("EVENEMENT", "HACK - Systemes de l'aeroport pirates");
  
  int perturbation = rand() % 3;

  switch (perturbation) {
  case 0:
    printf("Les communications sont perturbées.\n");
    ecrire_log_activite("HACK", "Communications perturbees");
    break;
    
  case 1:
    printf("Les systèmes de navigation sont compromis.\n");
    ecrire_log_activite("HACK", "Navigation compromise");
    break;

  case 2:
    printf("Les données de vol ont été altérées.\n");
    ecrire_log_activite("HACK", "Donnees de vol alterees");
    break;
  }
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
  } else if (random >= 5 && random < 7) {
    HackEvent(airport);
  }
}