#include <stdio.h>
#include <stdlib.h>

#include "../verifications/verif.h"
#include "gestion.h"

void decollage_atterrissage(Aeroport *airport, PISTE *piste) {
  avion *avionActif = piste->liste_avions_attente->premier;
  if (avionActif == NULL) {
    // Mettre une fonction d'affichage d'erreur ici.
    printf("Aucun avion n'est en attente sur la piste %d.\n",
           piste->numero_de_piste);
    return;
  }

  avion *avionRetire = retirerAvion(piste->liste_avions_attente, avionActif->id);

  if (avionRetire == NULL) {
    printf("Erreur: impossible de retirer l'avion %d de la piste %d.\n",
           avionActif->id, piste->numero_de_piste);
    return;
  }

  switch (avionRetire->etat) {
  case 0:
    // Mettre la fonction d'affichage du décollage ici.
    printf("L'avion %d a decollé de la piste %d. (Carburant: %d)\n", avionRetire->id,
           piste->numero_de_piste, avionRetire->carburant);
    avionRetire->carburant -= 10;
    ajouterFinFile(airport->liste_avions_en_vol, avionRetire);
    avionRetire->etat = 1;
    break;

  case 1:
    // Mettre la fonction d'affichage de l'atterrissage ici.
    printf("L'avion %d a atterri sur la piste %d. (Carburant restant: %d)\n", avionRetire->id,
           piste->numero_de_piste, avionRetire->carburant);
    avionRetire->carburant = 100;  /* Refuel au parking */
    ajouterFinFile(airport->parking, avionRetire);
    avionRetire->etat = 0;
    break;

  default:
    printf("Etat d'avion inconnu (%d) pour l'avion %d sur la piste %d.\n",
           avionRetire->etat, avionRetire->id, piste->numero_de_piste);
    break;
  }
}

int demandeAtt(Aeroport *airport, avion *plane) {
  // Test si le parking est plein.
  if (parking_est_plein(airport->parking, airport->places)) {
    // Affichage d'erreur.
    printf("Le parking est plein, veuillez aller dans la file d'attente.\n");
    // Si plein, retourne 0 pour ajouter a la file d'attente.
    return 0;
  }
  // Cherche une piste libre.
  int id = trouver_piste_libre(airport, plane);
  // Si une piste est libre, ajout dans la file de la piste.
  if (id != -1) {
    // Affichage de déplacement d'avion vers la piste.
    plane->heure = airport->heure + 5;
    return id;
  }
  // Sinon, retourne 0 pour ajouter a la file d'attente.
  else {
    // Affichage d'erreur.
    printf("Aucune Piste n'est disponible pour votre type d'avion, veuillez "
           "patientez le temps qu'une piste se libère.\n");
    return -1;
  }
}

void demande_file_aerienne(Aeroport *aeroport, avion *plane) {
  if (plane == NULL) {
    printf(" \n! SKIP AUCUN AVION DISPO !\n");
    return;
  }
  int request = demandeAtt(aeroport, plane);
  if (request == -1 && aeroport->file_attente_aerienne != NULL) {
    // Affichage d'attente de l'avion dans la file d'attente aerienne.
    printf("Ajout de l'avion %d a la file d'attente aerienne. \n", plane->id);
    ajouterFinFile(aeroport->file_attente_aerienne, plane);
    retirerAvion(aeroport->liste_avions_en_vol, plane->id);
  } else if (request >= 0 && request < 3) {
    // Affichage de déplacement d'avion vers la piste.
    printf("L'avion %d se dirige vers la piste %d pour atterrir.\n", plane->id,
           request);
    PISTE *piste = aeroport->pistes[request];
    if (piste) {
      ajouterFinFile(piste->liste_avions_attente, plane);
      retirerAvion(aeroport->liste_avions_en_vol, plane->id);
    }
  }
  return;
}

void demandeDec(Aeroport *airport, avion *plane) {
  if (plane == NULL) {
    printf(" \n! SKIP AUCUN AVION DISPO !\n");
    return;
  }
  int id = trouver_piste_libre(airport, plane);
  if (id != -1 && id >= 0 && id < 3) {
    // Affichage de déplacement d'avion vers la piste.
    printf("L'avion %d se dirige vers la piste %d pour decoller.\n", plane->id,
           id);
    PISTE *piste = airport->pistes[id];
    if (piste) {
      ajouterFinFile(piste->liste_avions_attente, plane);
      retirerAvion(airport->parking, plane->id);
      plane->heure = airport->heure + 5;

    }
  } else {
    // Affichage d'erreur.
    printf("Aucune Piste n'est disponible pour votre type d'avion, veuillez "
           "patientez le temps qu'une piste se libère.\n");
    // Forcer le premier avion de la file d'attente a decoller avant son crénau.
    printf("Forcage du décollage de l'avion %d avant son crénau. \n",
           plane->id);
    PISTE *piste_forcee = NULL;
    for (int i = 0; i < 3; i++) {
      if (airport->pistes[i] &&
          airport->pistes[i]->liste_avions_attente->nbElement > 0) {
        piste_forcee = airport->pistes[i];
        break;
      }
    }
    if (piste_forcee) {
      decollage_atterrissage(airport, piste_forcee);
      ajouterFinFile(piste_forcee->liste_avions_attente, plane);
      retirerAvion(airport->parking, plane->id);
    } else {
      printf("Aucun avion à forcer au décollage, opération annulée.\n");
    }
  }
}

void action_on_time(Aeroport *Aeroport) {
  for (int i = 0; i < 3; i++) {
    PISTE *piste = Aeroport->pistes[i];
    if (piste->liste_avions_attente->nbElement != 0) {
      if (piste->liste_avions_attente->premier->heure == Aeroport->heure) {
        decollage_atterrissage(Aeroport, piste);
      };
    }
  }
}

void incoming_plane(Aeroport *airport) {
  if (!airport) return;
  int etat = rand() % 2;
  avion *plane = creerAvion(airport);
  if (!plane) return;
  
  plane->etat = etat;
  if (etat == 0) {
    // Ajout de l'avion au parking si possible.
    if (parking_est_plein(airport->parking, airport->places)) {
      free(plane);
      return;
    }
    printf("Arrivée d'un nouvel avion %d au parking. (Carburant: %d)\n", plane->id, plane->carburant);
    ajouterFinFile(airport->parking, plane);
  } else {
    // Ajout de l'avion a la liste des avions en vol.
    printf("Arrivée d'un nouvel avion %d en vol. (Carburant: %d)\n", plane->id, plane->carburant);
    ajouterFinFile(airport->liste_avions_en_vol, plane);
  }
}

avion *select_rand_in_list(AvionFile *list) {
  if (list->nbElement == 0) {
    return NULL;
  };
  int index = rand() % list->nbElement;
  avion *current = list->premier;
  for (int i = 0; i < index; i++) {
    current = current->next;
  }
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
  if (!airport) return;
  
  /* Consommer du carburant en vol et vérifier les crashs */
  consume_carburant_vol(airport);
  
  int event = rand() % 3;
  // Fonction qui fait decoler les avions en fonctions des crénaux.
  action_on_time(airport);
  switch (event) {
  case 0:
    // Creer un avion et l'ajoute au parking ou en vol.
    incoming_plane(airport);
    break;

  case 1:
    // Selectionne un avion aleatoirement dans le parking pour decoller.
    {
      avion *plane = select_rand_in_list(airport->parking);
      if (plane && fuel_check(plane)) demandeDec(airport, plane);
      break;
    }

  case 2: {
    avion *plane = select_rand_in_list(airport->parking);
    if (plane && fuel_check(plane)) demande_file_aerienne(airport, plane);
    break;
  }
  default:
    printf("Cette partie ne fait pas partie du programme.\n");
    break;
  }
}

int fuel_check(avion *plane) {
  if(plane->carburant <= 0) {
    return 0;
  }
  return 1;
}

void remplir_carburant(avion *plane) {
  plane->carburant = 100;
}

void consume_carburant_vol(Aeroport *airport) {
  if (!airport || !airport->liste_avions_en_vol) return;
  
  avion *current = airport->liste_avions_en_vol->premier;
  while (current) {
    avion *next = current->next;
    current->carburant -= 5;  /* Perte de 5 unités par cycle en vol */
    
    /* Alerte carburant faible */
    if (current->carburant <= 20 && current->carburant > 0) {
      printf("⚠️  ALERTE CARBURANT: L'avion %d a moins de 20 unités! (Carburant: %d)\n", 
             current->id, current->carburant);
    }
    
    /* Crash si carburant épuisé */
    if (current->carburant <= 0) {
      printf("💥 CRASH! L'avion %d s'est écrasé par manque de carburant!\n", current->id);
      avion *crashed = retirerAvion(airport->liste_avions_en_vol, current->id);
      if (crashed) free(crashed);
    }
    
    current = next;
  }
}
