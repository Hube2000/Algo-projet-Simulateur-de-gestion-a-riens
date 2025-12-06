#include "verif.h"
#include "file.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

bool verifier_compatibilite(avion *avion, PISTE *piste) {
  if (avion == NULL || piste == NULL) {
    return false;
  }

  switch (avion->categorie) {
  case AVION_LEGER:
    // Avion léger peut utiliser toutes les pistes
    return true;

  case AVION_D_AFFAIRE:
    // Avion d'affaire peut utiliser piste moyenne ou grande
    return (piste->categorie_piste == PISTE_MOYENNE ||
            piste->categorie_piste == PISTE_GRANDE);

  case AVION_DE_LIGNE:
    // Avion de ligne nécessite une grande piste
    return (piste->categorie_piste == PISTE_GRANDE);

  default:
    return false;
  }
}

int compter_elements(AvionFile *file) {
  if (file == NULL) {
    return 0;
  }
  return file->nbElement;
}

bool parking_est_plein(AvionFile *liste_parking, int capacite_max_parking) {
  if (liste_parking == NULL) {
    return true; // Si pas de parking, considéré comme plein pr le moment
  }

  int nb_avions = compter_elements(liste_parking);
  return (nb_avions >= capacite_max_parking);
}

bool parking_est_plein_avec_reservations(Aeroport *aeroport) {
  if (!aeroport || !aeroport->parking) {
    return true;
  }
  int nb_avions = compter_elements(aeroport->parking);
  int total_occupation = nb_avions + aeroport->places_reservees;
  return (total_occupation >= aeroport->places);
}

void afficher_compatibilite(avion *av, PISTE *p) {
  if (verifier_compatibilite(av, p)) {
    printf("Avion #%d (", av->id);
    switch (av->categorie) {
    case AVION_LEGER:
      printf("Léger)");
      break;
    case AVION_D_AFFAIRE:
      printf("Affaire)");
      break;
    case AVION_DE_LIGNE:
      printf("Ligne)");
      break;
    }

    printf(" compatible avec Piste #%d (", p->numero_de_piste);
    switch (p->categorie_piste) {
    case PISTE_PETITE:
      printf("Petite)\n");
      break;
    case PISTE_MOYENNE:
      printf("Moyenne)\n");
      break;
    case PISTE_GRANDE:
      printf("Grande)\n");
      break;
    }

  } else {
    printf("ERREUR : Avion #%d incompatible avec Piste #%d\n", av->id,
           p->numero_de_piste);
  }
}

int trouver_piste_libre(Aeroport *aeroport, avion *plane) {
  if (!aeroport || !plane) {
    return -1;
  }

  for (int i = 0; i < 3; i++) {
    PISTE *piste = aeroport->pistes[i];
    if (!piste || !piste->liste_avions_attente) {
      continue;
    }
    if (verifier_compatibilite(plane, piste) &&
        piste->liste_avions_attente->nbElement <
            piste->nombre_max_avions_attente) {
      return i;
    }
  }
  return -1;
}

int trouver_piste(Aeroport *airport, avion *plane) {
  if (!airport || !plane) {
    return -1;
  }

  for (int i = 0; i < 3; i++) {
    PISTE *piste = airport->pistes[i];
    if (!piste || !piste->liste_avions_attente) {
      continue;
    }
    if (verifier_compatibilite(plane, piste)) {
      return i;
    }
  }
  return -1;
}