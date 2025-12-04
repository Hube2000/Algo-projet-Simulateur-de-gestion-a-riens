#include <stdio.h>
#include <stdlib.h>

#include "../verifications/verif.h"
#include "gestion.h"

void decollage_atterrissage(Aeroport *airport, PISTE *piste) {
  // Vérifications de sécurité
  if (!airport) {
    printf("Erreur: Aéroport invalide dans decollage_atterrissage.\n");
    return;
  }
  if (!piste) {
    printf("Erreur: Piste invalide dans decollage_atterrissage.\n");
    return;
  }
  if (!piste->liste_avions_attente) {
    printf("Erreur: Liste d'attente invalide pour la piste %d.\n",
           piste->numero_de_piste);
    return;
  }

  avion *avionActif = piste->liste_avions_attente->premier;
  if (avionActif == NULL) {
    // Mettre une fonction d'affichage d'erreur ici.
    printf("Aucun avion n'est en attente sur la piste %d.\n",
           piste->numero_de_piste);
    return;
  }
  switch (avionActif->etat) {
  case 0:
    // Mettre la fonction d'affichage du décollage ici.
    printf("L'avion %d a decollé de la piste %d.\n", avionActif->id,
           piste->numero_de_piste);
    printf("\n SI ERREUR : case 0 : dec/att ajouterfinfile\n");
    if (!airport->liste_avions_en_vol) {
      printf("Erreur: Liste des avions en vol invalide.\n");
      return;
    }
    ajouterFinFile(airport->liste_avions_en_vol, avionActif);
    avionActif->etat = 1;
    printf("\n SI ERREUR : case 0 : dec/att retirer\n");
    retirerAvion(piste->liste_avions_attente, avionActif->id);
    break;

  case 1:
    // Mettre la fonction d'affichage de l'atterrissage ici.
    printf("L'avion %d a atterri sur la piste %d.\n", avionActif->id,
           piste->numero_de_piste);
    printf("\n SI ERREUR : case 1 : dec/att ajouterfinfile\n");
    if (!airport->parking) {
      printf("Erreur: Parking invalide.\n");
      return;
    }
    ajouterFinFile(airport->parking, avionActif);
    avionActif->etat = 0;
    printf("\n SI ERREUR : case 1 : dec/att retirer\n");
    // ICI C POURRI
    retirerAvion(piste->liste_avions_attente, avionActif->id);
    break;

  default:
    printf("Etat d'avion inconnu (%d) pour l'avion %d sur la piste %d.\n",
           avionActif->etat, avionActif->id, piste->numero_de_piste);
    free(avionActif);
    break;
  }
}

int demandeAtt(Aeroport *airport, avion *plane) {
  // Vérifications de sécurité
  if (!airport) {
    printf("Erreur: Aéroport invalide dans demandeAtt.\n");
    return -1;
  }
  if (!plane) {
    printf("Erreur: Avion invalide dans demandeAtt.\n");
    return -1;
  }
  if (!airport->parking) {
    printf("Erreur: Parking invalide dans demandeAtt.\n");
    return -1;
  }

  // Test si le parking est plein.
  if (parking_est_plein(airport->parking, airport->places)) {
    // Affichage d'erreur.
    printf("Le parking est plein, veuillez aller dans la file d'attente.\n");
    // Si plein, retourne -1 pour ajouter a la file d'attente.
    return -1;
  }
  // Cherche une piste libre.
  int id = trouver_piste_libre(airport, plane);
  // Si une piste est libre, ajout dans la file de la piste.
  if (id != -1) {
    // Affichage de déplacement d'avion vers la piste.
    plane->heure = airport->heure + 5;
    return id;
  }
  // Sinon, retourne -1 pour ajouter a la file d'attente.
  else {
    // Affichage d'erreur.
    printf("Aucune Piste n'est disponible pour votre type d'avion, veuillez "
           "patientez le temps qu'une piste se libère.\n");
    return -1;
  }
}

void demande_file_aerienne(Aeroport *aeroport, avion *plane) {
  // Vérifications de sécurité
  if (!aeroport) {
    printf("Erreur: Aéroport invalide dans demande_file_aerienne.\n");
    return;
  }
  if (plane == NULL) {
    printf(" \n! SKIP AUCUN AVION DISPO !\n");
    return;
  }
  if (!aeroport->liste_avions_en_vol) {
    printf("Erreur: Liste des avions en vol invalide.\n");
    return;
  }

  int request = demandeAtt(aeroport, plane);
  if (request == -1 && aeroport->file_attente_aerienne != NULL) {
    // Affichage d'attente de l'avion dans la file d'attente aerienne.
    printf("Ajout de l'avion %d a la file d'attente aerienne. \n", plane->id);
    if (!aeroport->file_attente_aerienne) {
      printf("Erreur: File d'attente aérienne invalide.\n");
      return;
    }
    ajouterFinFile(aeroport->file_attente_aerienne, plane);
    retirerAvion(aeroport->liste_avions_en_vol, plane->id);
  } else if (request >= 0 && request < 3) {
    // Affichage de déplacement d'avion vers la piste.
    printf("L'avion %d se dirige vers la piste %d pour atterrir.\n", plane->id,
           request);
    PISTE *piste = aeroport->pistes[request];
    if (piste && piste->liste_avions_attente) {
      ajouterFinFile(piste->liste_avions_attente, plane);
      retirerAvion(aeroport->liste_avions_en_vol, plane->id);
    } else {
      printf("Erreur: Piste %d ou sa liste d'attente invalide.\n", request);
    }
  }
  return;
}

void demandeDec(Aeroport *airport, avion *plane) {
  // Vérifications de sécurité
  if (!airport) {
    // Cas ou l'aeroport n'as pas été creer.
    printf("\nErreur: Aéroport invalide dans demandeDec.\n");
    return;
  }
  if (plane == NULL) {
    // Si l'avion n'existe pas on ne fait rien.
    printf(" \n! SKIP AUCUN AVION DISPO !\n");
    return;
  }
  if (!airport->parking) {
    // Si le parking n'existe pas on ne fait rien.
    printf("Erreur: Parking invalide dans demandeDec.\n");
    return;
  }
  // On cherche une piste libre pour que l'avion s'y rende.
  int id = trouver_piste_libre(airport, plane);
  if (id != -1 && id >= 0 && id < 3) {
    // Affichage de déplacement d'avion vers la piste.
    printf("L'avion %d se dirige vers la piste %d pour decoller.\n", plane->id,
           id);
    PISTE *piste = airport->pistes[id];
    if (piste && piste->liste_avions_attente) {
      // Fonction ajouter dans l'ordre après avoir verifier les crenaux.
      // On attend azox
      ajouterFinFile(piste->liste_avions_attente, plane);
      retirerAvion(airport->parking, plane->id);
      plane->heure = airport->heure + 5;
    } else {
      // Cas si piste pas trouvée.
      printf("Erreur: Piste %d ou sa liste d'attente invalide.\n", id);
    }
  } else {
    // Affichage d'erreur.
    printf("\nAucune Piste n'est disponible pour votre type d'avion, veuillez "
           "patientez le temps qu'une piste se libère.\n");
    // Forcer le premier avion de la file d'attente a decoller avant son crénau.
    printf("Forcage du décollage de l'avion %d avant son crénau. \n",
           plane->id);
    PISTE *piste = airport->pistes[id];
    if (piste && piste->liste_avions_attente) {
      decollage_atterrissage(airport, piste);
      ajouterFinFile(piste->liste_avions_attente, plane);
      retirerAvion(airport->parking, plane->id);
    } else {
      printf("Aucun avion à forcer au décollage, opération annulée. -> Tout "
             "Casse\n");
    }
  }
}

void action_on_time(Aeroport *airport) {
  // Vérification de sécurité
  if (!airport) {
    printf("Erreur: Aéroport invalide dans action_on_time.\n");
    return;
  }

  for (int i = 0; i < 3; i++) {
    PISTE *piste = airport->pistes[i];
    // Vérifications de sécurité pour chaque piste
    if (!piste) {
      continue; // Piste invalide, passer à la suivante
    }
    if (!piste->liste_avions_attente) {
      continue; // Liste d'attente invalide, passer à la suivante
    }
    if (piste->liste_avions_attente->nbElement != 0) {
      avion *premier = piste->liste_avions_attente->premier;
      if (premier && premier->heure == airport->heure) {
        decollage_atterrissage(airport, piste);
      }
    }
  }
}

void incoming_plane(Aeroport *airport) {
  /*
    Incoming_plane
    Entrée : Aeroport *airport
    Sortie : Null
    Fonction qui a pout but de générer un avion pour l'ajouter dans les airs ou
    dans le parking si non plein.
  */
  // Vérification de sécurité
  if (!airport) {
    printf("Erreur: Aéroport invalide dans incoming_plane.\n");
    return;
  }

  int etat = rand() % 2; // Choisi l'emplacement de l'avion (sol 0 / air 1);
  avion *plane = creerAvion(airport); // Creer un avion

  if (!plane) {
    // Si l'avion n'a pas été crée, on arrete avec un message d'erreur.
    printf("Erreur: Impossible de créer un nouvel avion.\n");
    return;
  } else {
    // Sinon on creer un avion et on l'ajoute au bon endroit.
    plane->etat = etat; // Etat de l'avion sol(0)/air(1)
    switch (etat) {
    case 0:
      if (airport->parking == NULL) {
        // Cas ou le parking n'existe pas
        printf("\n{############################}");
        printf("\nERROR : PARKING NOT ALIVE\n");
        printf("{############################}\n");
        free(plane);
        return;
      }
      if (parking_est_plein(airport->parking, airport->places)) {
        // Cas ou le parking est plein
        printf("\n{############################}");
        printf("\nERROR : PARKING FULL\n");
        printf("{############################}\n");
        free(plane);
        return;
      }
      ajouterFinFile(airport->parking, plane);
      printf("\n ### ARRIVE D'UN NOUVEL L'AVION %d AU PARKING ###", plane->id);
      break;
    case 1:
      if (airport->liste_avions_en_vol == NULL) {
        // Cas ou la file aerienne n'existe pas
        printf("\n{############################}");
        printf("\nERROR : NO SKY\n");
        printf("{############################}\n");
        free(plane);
        return;
      }
      ajouterFinFile(airport->liste_avions_en_vol, plane);
      printf("\n ### ARRIVE D'UN NOUVEL L'AVION %d DANS LES AIRS ###",
             plane->id);
      return;
      break;
    default:
      printf("NTM T'A TT CASSÉ");
      free(plane);
      return;
      break;
    }
    return;
  }
}

avion *select_rand_in_list(AvionFile *list) {
  // Vérifications de sécurité
  if (!list) {
    // Cas Liste pas creer
    printf("LISTE NON FOURNIE");
    return NULL;
  }
  if (list->nbElement == 0) {
    // Cas liste vide
    printf("LISTE VIDE");
    return NULL;
  }
  int index = rand() % list->nbElement;
  avion *current = list->premier;
  if (!current) {
    // Cas premier pas trouver.
    printf("Pas d'avions dans la liste.");
    return NULL;
  }
  for (int i = 0; i < index && current != NULL; i++) {
    // Parcour de la liste pour trouver l'avion.
    current = current->next;
  }
  // Retourne l'adresse du l'avion sur lequel effectuer l'action.
  return current;
}

/*
  VerifierDec
  Entrée : Aeroport *aeroport
  Sortie : int* (tableau de 3 entiers)
  Verifie les pistes pour voir les avions qui sont prets a decoller ou
  atterrir. OK
*/

/*
  decollage / atterrissage:
  Entrée : Aeroport *airport, PISTE *piste
  Sortie : void
  Effectue le décollage/atterrisage du premier avion de la piste donnée après
  vérification.
  OK
*/

/*
  demande ATT:
  Entrée : Aeroport *aeroport, avion *avion
  Sortie : int (1 si atterrissage possible, 0 sinon)
  Vérifie si une piste et le parking sont disponibles pour l'atterrissage.
  Si piste pleine retourne 0 pour ajouter a la file d'attente.
  OK
*/

/*
  demande fileAtterissage:
  Entrée : Aeroport *aeroport, avion *avion
  Sortie : void
  Check si l'atterissage est possible et que la file aerienne est vide sinon
  ajoute a la file d'attente
  OK
*/

/*
  plus de fiul :
  Entrée : Aeroport *aeroport
  sortie : void
  Verifie le avions dana la file d'attente et si un avion n'as plus d'essence
  force un atterissage ou fait crasher l'avion.
*/

/*
  demande DEC :
  Entrée : Aeroport *aeroport, avion *avion
  Sortie : void
  Vérifie si une piste est disponible pour le décollage.
  Si piste pleine force le premier avion de la file d'attente a decoller avant
  son crénau.
  OK
*/

/*
  trouver piste libre:
  Entrée : Aeroport *aeroport, avion *avion
  Sortie : int (index de la piste libre ou -1 si aucune)
  Trouve une piste libre compatible avec l'avion donné.
  OK
*/

/*
  action on time:
  entree : Aeroport *aeroport
  sortie : void
  Fait decoller les avions qui ont un crénau a l'heure actuelle.
*/

/*
  IncomingPlane:
  Entrée : Aeroport *aeroport
  Sortie : void
  Creer et ajoute un avion soit dans la liste des avions en vol soit dans le
  parking.
*/

/*
 Selectrancinlist:
  Entrée : AvionFile *
  Sortie : avion *
  Selectionne un avion aleatoirement dans une liste d'avion.
*/

void manageAirport(Aeroport *airport) {
  int event = rand() % 3;
  // Fonction qui fait decoler les avions en fonctions des crénaux.
  printf("\n SI ERREUR : manageAirport -> action on time\n");
  action_on_time(airport); // Problème ici... + avion qui disparait
  switch (event) {
  case 0:
    // Creer un avion et l'ajoute au parking ou en vol.
    printf("Si Erreur : manageAirport case 0");
    incoming_plane(airport);
    break;

  case 1:
    // Selectionne un avion aleatoirement dans le parking pour decoller.
    {
      printf("Si Erreur : manageAirport case 1\n");
      demandeDec(airport, select_rand_in_list(airport->parking));
      break;
    }

  case 2: {
    printf("Si Erreur : manageAirport case 2");
    demande_file_aerienne(airport,
                          select_rand_in_list(airport->liste_avions_en_vol));
    break;
  }
  default:
    printf("Cette partie ne fait pas partie du programme.\n");
    break;
  }
}
