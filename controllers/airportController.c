#include "airportController.h"
#include <stdio.h>
#include <stdlib.h>

PISTE *creerPiste(int numero, int longeur, CATEGORIE_PISTE categorie,
                  int capa) {
  PISTE *piste = malloc(sizeof(PISTE));
  if (!piste)
    return NULL;
  piste->numero_de_piste = numero;
  piste->longueur = longeur;
  piste->categorie_piste = categorie;
  piste->nombre_max_avions_attente = capa;
  piste->liste_avions_attente = creerAvionFile();
  if (!piste->liste_avions_attente) {
    /* Échec d'allocation de la file : on libère la piste et on
     * signale l'erreur au code appelant. */
    free(piste);
    return NULL;
  }
  return piste;
}

Aeroport *creerAeroport() {
  Aeroport *aeroport = malloc(sizeof(Aeroport));
  if (!aeroport)
    return NULL;
  aeroport->places = 50;
  aeroport->parking = creerAvionFile();
  aeroport->liste_avions_en_vol = creerAvionFile();
  aeroport->file_attente_aerienne = creerAvionFile();
  aeroport->passagers = 0;
  aeroport->departs = 0;
  aeroport->retours = 0;
  aeroport->heure = 0;
  aeroport->total_avions = 0;

  aeroport->pistes[0] = creerPiste(1, 1000, PISTE_PETITE, 5);
  aeroport->pistes[1] = creerPiste(2, 2000, PISTE_MOYENNE, 5);
  aeroport->pistes[2] = creerPiste(3, 3000, PISTE_GRANDE, 5);

  /* Si une des pistes ou files principales n'a pas pu être allouée,
   * on libère tout proprement et on retourne NULL. */
  if (!aeroport->parking || !aeroport->liste_avions_en_vol ||
      !aeroport->file_attente_aerienne || !aeroport->pistes[0] ||
      !aeroport->pistes[1] || !aeroport->pistes[2]) {
    detruireAeroport(aeroport);
    return NULL;
  }
  return aeroport;
}

/* Libère complètement un aéroport et toutes ses structures associées. */
void detruireAeroport(Aeroport *aeroport) {
  if (!aeroport)
    return;

  /* Libère les files principales de l'aéroport. */
  detruireAvionFile(aeroport->parking);
  detruireAvionFile(aeroport->liste_avions_en_vol);
  detruireAvionFile(aeroport->file_attente_aerienne);

  /* Libère les pistes et leurs files. */
  for (int i = 0; i < 3; ++i) {
    if (aeroport->pistes[i]) {
      if (aeroport->pistes[i]->liste_avions_attente) {
        detruireAvionFile(aeroport->pistes[i]->liste_avions_attente);
      }
      free(aeroport->pistes[i]);
      aeroport->pistes[i] = NULL;
    }
  }

  free(aeroport);
}

void afficherFile(AvionFile *file) {
  if (!file) {
    printf("File inexistante.\n");
    return;
  }
  if (file->nbElement == 0) {
    printf("File vide.\n");
    return;
  }
  avion *current = file->premier;
  printf("Contenu de la file (%d éléments):\n", file->nbElement);
  int count = 0;
  while (current != NULL && count < file->nbElement) {
    printf("Avion ID: %d, État: %d, Heure: %d\n", current->id, current->etat,
           current->heure);
    current = current->next;
    count++;
  }
  if (count >= file->nbElement && current != NULL) {
    printf("ERREUR: Cycle détecté dans la file ! Arrêt de l'affichage.\n");
  }
}