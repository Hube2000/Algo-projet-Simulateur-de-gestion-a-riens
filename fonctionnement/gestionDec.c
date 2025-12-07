#include "gestionDec.h"
#include "aeroport.h"
#include "avion.h"
#include "avionController.h"
#include "file.h"
#include "gestion.h"
#include "gestionAtt.h"
#include "piste.h"
#include "verif.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../UI/events_ui.h"
#include "../UI/logs_ui.h"

void decollage(Aeroport *airport, PISTE *piste);
void demander_decollage(Aeroport *airport, PISTE *piste, avion *plane);
void force_action(Aeroport *airport, PISTE *piste, avion *plane);

void demander_decollage(Aeroport *airport, PISTE *piste, avion *plane) {
  if (!airport || !plane || !airport->parking || !piste) {
    printf("Problème d'INIT");
    return;
  }
  retirerAvion(airport->parking, plane->id);
  ajoutHeure(airport, piste, plane);
  int indexPiste = piste->numero_de_piste - 1;
  airport->places_reservees--;
  ajouter_bonne_place(airport, plane, indexPiste);
  return;
}

void force_action(Aeroport *airport, PISTE *piste, avion *plane) {
  if (!airport || !plane || !airport->parking || !piste) {
    printf("Problème d'INIT");
    return;
  }
  if (plane->etat == 0) {
    printf("Forcage du décollage de l'avion %d sur la piste %d", plane->id,
           piste->numero_de_piste);
    decollage(airport, piste);
    demander_decollage(airport, piste, plane);
    return;
  } else if (plane->etat == 1) {
    printf("Forcage de l'atterrissage de l'avion %d sur la piste %d", plane->id,
           piste->numero_de_piste);
    atterissage(airport, piste);
    demander_atterissage(airport, piste, plane);
    return;
  }
  return;
}

void decollage(Aeroport *airport, PISTE *piste) {
  if (!airport || !airport->parking || !piste ||
      !airport->liste_avions_en_vol || !piste->liste_avions_attente) {
    return;
  }
  avion *avionActif = piste->liste_avions_attente->premier;
  if (!avionActif) {
    printf("Aucun avion présent dans la piste");
    return;
  } else {
    int idAvion = avionActif->id;
    int nbAvant = piste->liste_avions_attente->nbElement;

    avionActif->etat = 1;
    retirerAvion(piste->liste_avions_attente, avionActif->id);

    if (piste->liste_avions_attente->nbElement != nbAvant - 1) {
      printf("\n [ERREUR] Le nombre d'avions n'a pas diminue correctement lors "
             "du decollage de l'avion %d (piste %d)\n",
             idAvion, piste->numero_de_piste);
    }

    avion *check = piste->liste_avions_attente->premier;
    while (check) {
      if (check->id == idAvion) {
        printf("\n [ERREUR] L'avion %d est toujours dans la piste %d apres "
               "retrait!\n",
               idAvion, piste->numero_de_piste);
        break;
      }
      check = check->next;
    }

    ajouterFinFile(airport->liste_avions_en_vol, avionActif);
    airport->departs++;
    airport->passagers += avionActif->nombre_de_passagers;
    ecrire_event_UI("DECOLLAGE", "Avion decolle avec succes");
    char log_msg[100];
    sprintf(log_msg, "Avion ID %d decolle (%d passagers)", avionActif->id, avionActif->nombre_de_passagers);
    ecrire_log_activite("DEPART", log_msg);
    printf("\n L'avion %d a decoller avec succes. (%d passagers embarques)",
           avionActif->id, avionActif->nombre_de_passagers);
    return;
  }
}