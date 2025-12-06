#include "file.h"
#include "aeroport.h"
#include "avion.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

AvionFile *creerAvionFile() {
  AvionFile *file = malloc(sizeof(AvionFile));
  if (!file)
    return NULL;
  file->nbElement = 0;
  file->premier = NULL;
  file->dernier = NULL;
  return file;
}

void ajouterDebutFile(AvionFile *file, avion *a) {
  if (!file || !a) {
    printf("\n Donnée manquantes dans les inputs. ajouterDebutFile (file.c)\n");
    return;
  }
  if (file->nbElement == 0) {
    file->premier = a;
    file->dernier = a;
    a->next = NULL;
    a->prev = NULL;
  } else {
    a->next = file->premier;
    a->prev = NULL;
    file->premier->prev = a;
    file->premier = a;
  }
  file->nbElement++;
  return;
}

void ajouterFinFile(AvionFile *file, avion *a) {
  if (!file || !a) {
    printf("\n Donnée manquantes dans les inputs. ajouterFinFile (file.c)\n");
    return;
  }
  if (file->nbElement == 0) {
    file->premier = a;
    file->dernier = a;
    a->next = NULL;
    a->prev = NULL;
  } else {
    a->prev = file->dernier;
    a->next = NULL;
    file->dernier->next = a;
    file->dernier = a;
  }
  file->nbElement++;
  return;
}

void supprimerDebutFile(AvionFile *file) {
  if (!file || file->nbElement == 0) {
    printf("\n Donnée manquantes dans les inputs ou file vide. "
           "supprimerDebutFile (file.c)\n");
    return;
  }
  avion *toRemove = file->premier;
  if (file->nbElement == 1) {
    file->premier = NULL;
    file->dernier = NULL;
  } else {
    file->premier = toRemove->next;
    if (file->premier)
      file->premier->prev = NULL;
  }
  free(toRemove);
  file->nbElement--;
  return;
}

void supprimerFinFile(AvionFile *file) {
  if (!file || file->nbElement == 0) {
    printf("\n Donnée manquantes dans les inputs ou file vide. "
           "supprimerFinFile (file.c)\n");
    return;
  }
  avion *toRemove = file->dernier;
  if (file->nbElement == 1) {
    file->premier = NULL;
    file->dernier = NULL;
  } else {
    file->dernier = toRemove->prev;
    if (file->dernier)
      file->dernier->next = NULL;
  }
  free(toRemove);
  file->nbElement--;
  return;
}

void detruireAvionFile(AvionFile *file) {
  if (!file) {
    printf("\n Erreur file vide. detruireAvionFile (file.c)\n");
    return;
  }

  avion *courant = file->premier;
  while (courant) {
    avion *suivant = courant->next;
    free(courant);
    courant = suivant;
  }
  free(file);
}

void ajouter_bonne_place(Aeroport *airport, avion *plane, int indexBonnePlace) {
  if (!airport || !plane || indexBonnePlace < 0 || indexBonnePlace >= 3 ||
      !airport->pistes[indexBonnePlace] ||
      !airport->pistes[indexBonnePlace]->liste_avions_attente) {
    printf("Erreur: Paramètres invalides dans ajouter_bonne_place.\n");
    return;
  }
  if (plane->next != NULL || plane->prev != NULL) {
    printf("Erreur: L'avion %d est déjà dans une liste!\n", plane->id);
    plane->next = NULL;
    plane->prev = NULL;
  }
  avion *current =
      airport->pistes[indexBonnePlace]->liste_avions_attente->premier;
  while (current && current->heure <= plane->heure) {
    current = current->next;
  }
  // cas fin
  if (!current) {
    ajouterFinFile(airport->pistes[indexBonnePlace]->liste_avions_attente,
                   plane);
  }
  // Cas début
  else if (current ==
           airport->pistes[indexBonnePlace]->liste_avions_attente->premier) {
    ajouterDebutFile(airport->pistes[indexBonnePlace]->liste_avions_attente,
                     plane);
  } // Cas milieu
  else {
    if (current->prev) {
      plane->next = current;
      plane->prev = current->prev;
      current->prev->next = plane;
      current->prev = plane;
      airport->pistes[indexBonnePlace]->liste_avions_attente->nbElement++;
    } else {
      ajouterDebutFile(airport->pistes[indexBonnePlace]->liste_avions_attente,
                       plane);
    }
  }
}

void ajouter_bonne_place_essence(Aeroport *airport, avion *plane) {
  if (!airport || !plane || !airport->file_attente_aerienne) {
    printf("Erreur: Paramètres invalides dans ajouter_bonne_place_essence.\n");
    return;
  }
  if (plane->next != NULL || plane->prev != NULL) {
    printf("Erreur: L'avion %d est déjà dans une liste!\n", plane->id);
    plane->next = NULL;
    plane->prev = NULL;
  }
  avion *current = airport->file_attente_aerienne->premier;
  while (current && current->carburant <= plane->carburant) {
    current = current->next;
  }
  // cas fin
  if (!current) {
    ajouterFinFile(airport->file_attente_aerienne, plane);
  }
  // Cas début
  else if (current == airport->file_attente_aerienne->premier) {
    ajouterDebutFile(airport->file_attente_aerienne, plane);
  } // Cas milieu
  else {
    if (current->prev) {
      plane->next = current;
      plane->prev = current->prev;
      current->prev->next = plane;
      current->prev = plane;
      airport->file_attente_aerienne->nbElement++;
    } else {
      ajouterDebutFile(airport->file_attente_aerienne, plane);
    }
  }
}