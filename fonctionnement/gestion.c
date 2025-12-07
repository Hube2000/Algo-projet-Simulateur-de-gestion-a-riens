#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

#include "aeroport.h"
#include "avion.h"
#include "avionController.h"
#include "file.h"
#include "gestion.h"
#include "gestionAtt.h"
#include "gestionDec.h"
#include "gestionEssence.h"
#include "piste.h"
#include "verif.h"

void action_on_time(Aeroport *airport) {
  if (!airport) {
    printf("Erreur: Aéroport invalide dans action_on_time.\n");
    return;
  }

  for (int i = 0; i < 3; i++) {
    PISTE *piste = airport->pistes[i];
    if (!piste || !piste->liste_avions_attente ||
        piste->liste_avions_attente->nbElement == 0) {
      continue;
    }

    int max_iterations = piste->liste_avions_attente->nbElement + 5;
    int iterations = 0;

    while (piste->liste_avions_attente->nbElement > 0 &&
           iterations < max_iterations) {
      avion *premier = piste->liste_avions_attente->premier;
      if (!premier) {
        piste->liste_avions_attente->nbElement = 0;
        break;
      }

      int idAvion = premier->id;
      int heureAvion = premier->heure;
      int nbAvionsAvant = piste->liste_avions_attente->nbElement;

      if (premier->heure <= airport->heure) {
        if (premier->etat == 1) {
          atterissage(airport, piste);
        } else if (premier->etat == 0) {
          decollage(airport, piste);
        }
        if (piste->liste_avions_attente->premier &&
            piste->liste_avions_attente->premier->id == idAvion) {
          printf("\n [DEBUG] Avion %d (heure %d) non retire de la piste %d, "
                 "retrait force\n",
                 idAvion, heureAvion, piste->numero_de_piste);
          retirerAvion(piste->liste_avions_attente, idAvion);
          break;
        }

        if (piste->liste_avions_attente->nbElement >= nbAvionsAvant) {
          printf("\n [DEBUG] ERREUR: Le nombre d'avions n'a pas diminue apres "
                 "traitement (piste %d)\n",
                 piste->numero_de_piste);
          break;
        }
      } else {
        break;
      }

      iterations++;
    }
  }
  return;
}

void incoming_plane(Aeroport *airport) {
  if (!airport) {
    return;
  }

  avion *plane = creerAvion(airport);
  int etat = rand() % 2;

  if (!plane) {
    return;
  } else {
    plane->etat = etat;
    switch (etat) {
    case 0: {
      if (airport->parking == NULL ||
          parking_est_plein(airport->parking, airport->places)) {
        printf("Plus de places ou autre.");
        free(plane);
        return;
      } else {
        ajouterFinFile(airport->parking, plane);
        printf("\n ### ARRIVE D'UN NOUVEL L'AVION %d AU PARKING ###",
               plane->id);
        return;
      }
      break;
    }
    case 1: {
      if (airport->liste_avions_en_vol == NULL) {
        free(plane);
        return;
      } else {
        ajouterFinFile(airport->liste_avions_en_vol, plane);
        printf("\n ### ARRIVE D'UN NOUVEL L'AVION %d DANS LES AIRS ###",
               plane->id);
        return;
      }
      break;
    }
    default: {

      free(plane);
      return;
      break;
    }
    }
    return;
  }
}

avion *select_rand_in_list(AvionFile *list) {
  // Vérifications de sécurité
  if (!list || list->nbElement == 0) {
    printf("LISTE NON FOURNIE");
    return NULL;
  }

  int index = rand() % list->nbElement;
  avion *current = list->premier;

  if (!current) {
    return NULL;
  } else {
    for (int i = 0; i < index && current != NULL; i++) {
      current = current->next;
    }
    return current;
  }
}

void ajoutHeure(Aeroport *airport, PISTE *piste, avion *plane) {
  if (!airport || !piste || !plane || !piste->liste_avions_attente) {
    printf("Erreur: Paramètres invalides dans ajoutHeure.\n");
    return;
  }

  int min = ((airport->heure / 5) + 1) * 5;
  int offset = (rand() % 6) * 5;
  int try = min + offset;
  int heure = 0;

  while (!heure) {
    int conflit = 0;
    avion *current = piste->liste_avions_attente->premier;
    while (current != NULL) {
      if (current != plane && current->heure == try) {
        conflit = 1;
        break;
      }
      current = current->next;
    }

    if (!conflit) {
      heure = 1;
    } else {
      try += 5;
    }
  }

  plane->heure = try;
}

void manageAirport(Aeroport *airport) {
  int event = rand() % 3;
  action_on_time(airport);
  switch (event) {
  case 0: {
    incoming_plane(airport);
    break;
  }

  case 1: {
    if (!airport->parking || airport->parking->nbElement == 0) {
      break;
    }
    avion *plane = select_rand_in_list(airport->parking);
    if (!plane) {
      break;
    }
    int idPiste = trouver_piste_libre(airport, plane);
    if (idPiste != -1) {
      demander_decollage(airport, airport->pistes[idPiste], plane);
      return;
    } else {
      idPiste = trouver_piste(airport, plane);
      if (idPiste != -1) {
        force_action(airport, airport->pistes[idPiste], plane);
        return;
      }
    }
    break;
  }

  case 2: {
    avion *plane = NULL;
    int idPiste;
    if (!airport->file_attente_aerienne ||
        airport->file_attente_aerienne->nbElement == 0) {
      if (!airport->liste_avions_en_vol ||
          airport->liste_avions_en_vol->nbElement == 0) {
        break;
      }
      plane = select_rand_in_list(airport->liste_avions_en_vol);
      if (!plane) {
        break;
      }
      idPiste = test_Att(airport, plane);
      if (idPiste != -1) {
        demander_atterissage(airport, airport->pistes[idPiste], plane);
        return;
      } else {
        remplir_carburant(plane);
        demander_file_aerienne(airport, plane);
        return;
      }
    } else {
      plane = airport->file_attente_aerienne->premier;
      if (!plane) {
        break;
      }
      idPiste = test_Att(airport, plane);
      if (idPiste != -1) {
        demander_atterissage(airport, airport->pistes[idPiste], plane);
        return;
      }
      return;
    }
    break;
  }
  default:
    printf("Cette partie ne fait pas partie du programme.\n");
    break;
  }
}

void writeAirportInfo(Aeroport *airport) {
  if (!airport) {
    return;
  }

  FILE *file = fopen("data_info.txt", "w");
  if (!file) {
    return;
  }

  fprintf(file, "HEURE ACTUELLE: %d minutes\n\n", airport->heure);

  fprintf(file, "STATISTIQUES:\n");
  fprintf(file, "  - Avions au parking: %d / %d places\n", 
          airport->parking ? airport->parking->nbElement : 0, airport->places);
  fprintf(file, "  - Avions en vol: %d\n", 
          airport->liste_avions_en_vol ? airport->liste_avions_en_vol->nbElement : 0);
  fprintf(file, "  - Avions en file aerienne: %d\n", 
          airport->file_attente_aerienne ? airport->file_attente_aerienne->nbElement : 0);
  fprintf(file, "  - Total avions geres: %d\n\n", airport->total_avions);

  fprintf(file, "ETAT DES PISTES:\n");
  for (int i = 0; i < 3; i++) {
    PISTE *piste = airport->pistes[i];
    if (piste && piste->liste_avions_attente) {
      if (piste->liste_avions_attente->nbElement > 0) {
        fprintf(file, "  Piste %d: %d avion(s) en attente\n", 
                i + 1, piste->liste_avions_attente->nbElement);
      } else {
        fprintf(file, "  Piste %d: Aucun avion en attente\n", i + 1);
      }
    }
  }

  fclose(file);
}

void displayAirport(Aeroport *airport) {
  if (!airport) {
    printf("Erreur: Aéroport invalide.\n");
    return;
  }

  #ifdef _WIN32
  system("cls");
  #else
  system("clear");
  #endif

  printf("====================================================================="
         "=\n");
  printf("                    SIMULATEUR DE GESTION\n");
  printf("                         D'AEROPORT\n");
  printf("====================================================================="
         "=\n\n");

  printf("---------------------------------------------------------------------"
         "-\n");
  printf("HEURE ACTUELLE : %d minutes\n", airport->heure);
  printf("---------------------------------------------------------------------"
         "-\n\n");

  printf("STATISTIQUES:\n");
  printf("   - Passagers totaux: %d\n", airport->passagers);
  printf("   - Departs: %d\n", airport->departs);
  printf("   - Retours: %d\n", airport->retours);
  printf("   - Total avions crees: %d\n", airport->total_avions);
  printf("\n");

  printf("---------------------------------------------------------------------"
         "-\n");
  printf("PARKING (%d/%d places)\n",
         airport->parking ? airport->parking->nbElement : 0, airport->places);
  printf("---------------------------------------------------------------------"
         "-\n");
  if (!airport->parking || airport->parking->nbElement == 0) {
    printf("   (vide)\n");
  } else {
    if (!airport->parking->premier) {
      airport->parking->nbElement = 0;
      printf("   (vide)\n");
    } else {
      avion *current = airport->parking->premier;
      int count = 0;
      int max_iterations = 200;

      while (current != NULL && count < max_iterations) {
        const char *cat = "";
        switch (current->categorie) {
        case AVION_LEGER:
          cat = "Léger";
          break;
        case AVION_D_AFFAIRE:
          cat = "Affaire";
          break;
        case AVION_DE_LIGNE:
          cat = "Ligne";
          break;
        }
        printf("   - Avion #%d [%s] | Passagers: %d | Carburant: %d%%\n",
               current->id, cat, current->nombre_de_passagers,
               current->carburant);
        current = current->next;
        count++;
      }
      airport->parking->nbElement = count;
    }
  }
  printf("\n");

  for (int i = 0; i < 3; i++) {
    PISTE *piste = airport->pistes[i];
    if (!piste)
      continue;

    const char *cat_piste = "";
    switch (piste->categorie_piste) {
    case PISTE_PETITE:
      cat_piste = "Petite";
      break;
    case PISTE_MOYENNE:
      cat_piste = "Moyenne";
      break;
    case PISTE_GRANDE:
      cat_piste = "Grande";
      break;
    }

    printf("-------------------------------------------------------------------"
           "---\n");
    printf("PISTE %d [%s] (%d/%d avions)\n", piste->numero_de_piste, cat_piste,
           piste->liste_avions_attente ? piste->liste_avions_attente->nbElement
                                       : 0,
           piste->nombre_max_avions_attente);
    printf("-------------------------------------------------------------------"
           "---\n");

    if (!piste->liste_avions_attente ||
        piste->liste_avions_attente->nbElement == 0) {
      printf("   (vide)\n");
    } else {
      if (!piste->liste_avions_attente->premier) {
        piste->liste_avions_attente->nbElement = 0;
        printf("   (vide)\n");
      } else {
        avion *current = piste->liste_avions_attente->premier;
        int count = 0;
        int max_iterations = 200;
        while (current != NULL && count < max_iterations) {
          const char *cat = "";
          const char *action = "";
          switch (current->categorie) {
          case AVION_LEGER:
            cat = "Léger";
            break;
          case AVION_D_AFFAIRE:
            cat = "Affaire";
            break;
          case AVION_DE_LIGNE:
            cat = "Ligne";
            break;
          }
          action = (current->etat == 1) ? "Atterrissage" : "Décollage";
          printf("   - Avion #%d [%s] | %s a l'heure %d | Carburant: %d%%\n",
                 current->id, cat, action, current->heure, current->carburant);
          current = current->next;
          count++;
        }
        piste->liste_avions_attente->nbElement = count;
      }
    }
    printf("\n");
  }

  printf("---------------------------------------------------------------------"
         "-\n");
  printf("AVIONS EN VOL\n");
  printf("---------------------------------------------------------------------"
         "-\n");
  if (!airport->liste_avions_en_vol ||
      airport->liste_avions_en_vol->nbElement == 0) {
    printf("   (aucun)\n");
  } else {
    if (!airport->liste_avions_en_vol->premier) {
      airport->liste_avions_en_vol->nbElement = 0;
      printf("   (aucun)\n");
    } else {
      avion *current = airport->liste_avions_en_vol->premier;
      int count = 0;
      int max_iterations = 200;
      while (current != NULL && count < max_iterations) {
        const char *cat = "";
        switch (current->categorie) {
        case AVION_LEGER:
          cat = "Léger";
          break;
        case AVION_D_AFFAIRE:
          cat = "Affaire";
          break;
        case AVION_DE_LIGNE:
          cat = "Ligne";
          break;
        }
        printf("   - Avion #%d [%s] | Carburant: %d%% | Passagers: %d\n",
               current->id, cat, current->carburant,
               current->nombre_de_passagers);
        current = current->next;
        count++;
      }
      airport->liste_avions_en_vol->nbElement = count;
    }
  }
  printf("\n");

  printf("---------------------------------------------------------------------"
         "-\n");
  printf("FILE D'ATTENTE AERIENNE\n");
  printf("---------------------------------------------------------------------"
         "-\n");
  if (!airport->file_attente_aerienne ||
      airport->file_attente_aerienne->nbElement == 0) {
    printf("   (vide)\n");
  } else {
    if (!airport->file_attente_aerienne->premier) {
      airport->file_attente_aerienne->nbElement = 0;
      printf("   (vide)\n");
    } else {
      avion *current = airport->file_attente_aerienne->premier;
      int count = 0;
      int max_iterations = 200;
      while (current != NULL && count < max_iterations) {
        const char *cat = "";
        switch (current->categorie) {
        case AVION_LEGER:
          cat = "Léger";
          break;
        case AVION_D_AFFAIRE:
          cat = "Affaire";
          break;
        case AVION_DE_LIGNE:
          cat = "Ligne";
          break;
        }
        printf("   - Avion #%d [%s] | Carburant: %d%%\n", current->id, cat,
               current->carburant);
        current = current->next;
        count++;
      }
      airport->file_attente_aerienne->nbElement = count;
    }
  }
  printf("\n");
  printf("====================================================================="
         "=\n");
}
