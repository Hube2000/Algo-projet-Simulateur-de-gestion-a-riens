#include "gestionAtt.h"
#include "aeroport.h"
#include "avion.h"
#include "avionController.h"
#include "file.h"
#include "gestion.h"
#include "piste.h"
#include "verif.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int test_Att(Aeroport *airport, avion *plane) {
  if (!airport || !airport->parking) {
    return -1;
  }
  int idPiste = trouver_piste_libre(airport, plane);
  if (idPiste != -1 && airport->places_reservees < 51) {
    return idPiste;
  } else {
    return -1;
  }
}

void demander_atterissage(Aeroport *airport, PISTE *piste, avion *plane) {
  if (!airport || !plane || !piste) {
    return;
  }
  retirerAvion(airport->liste_avions_en_vol, plane->id);
  ajoutHeure(airport, piste, plane);
  int indexPiste = piste->numero_de_piste - 1;
  ajouter_bonne_place(airport, plane, indexPiste);
  airport->places_reservees++;
  return;
}

void demander_file_aerienne(Aeroport *airport, avion *plane) {
  if (!airport || !plane || !airport->file_attente_aerienne) {
    return;
  }
  retirerAvion(airport->liste_avions_en_vol, plane->id);
  ajouter_bonne_place_essence(airport, plane);
  return;
}

void atterissage(Aeroport *airport, PISTE *piste) {
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

    avionActif->etat = 0;
    retirerAvion(piste->liste_avions_attente, avionActif->id);

    if (piste->liste_avions_attente->nbElement != nbAvant - 1) {
      printf("\n [ERREUR] Le nombre d'avions n'a pas diminue correctement lors "
             "de l'atterissage de l'avion %d (piste %d)\n",
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

    ajouterFinFile(airport->parking, avionActif);
    airport->passagers += avionActif->nombre_de_passagers;
    airport->retours++;
    airport->places_reservees--;
    printf("\n L'avion %d a atteri avec succes. (%d passagers debarques)",
           avionActif->id, avionActif->nombre_de_passagers);
    return;
  }
}