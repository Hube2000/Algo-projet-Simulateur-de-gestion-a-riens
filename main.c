#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#include "aeroport.h"
#include "airportController.h"
#include "avion.h"
#include "gestion.h"
#include "gestionEssence.h"
#include "piste.h"
#include "verif.h"

#define NB_PISTES 3

/*
    bool verifier_compatibilite(avion *avion, PISTE *piste);
    bool parking_est_plein(AvionFile *liste_parking, int capacite_max_parking);

    int compter_elements(AvionFile *file);
    int trouver_piste_libre(Aeroport *aeroport, avion *avion);

    void afficher_compatibilite(avion *av, PISTE *p);
    void chargement(void);
    void incoming_plane(Aeroport *airport);
    void manageAirport(Aeroport *airport);
    void action_on_time(Aeroport *airport);
    void demandeDec(Aeroport *airport, avion *plane);
    void demande_file_aerienne(Aeroport *aeroport, avion *plane);
    void demanderAtt(Aeroport *aeroport, avion *avion);
    void decollage_atterrissage(Aeroport *airport, PISTE *piste);

    AvionFile *creerAvionFile(void);
    AvionFile *ajouterDebutFile(AvionFile *file, avion *a);
    AvionFile *ajouterFinFile(AvionFile *file, avion *a);
    AvionFile *supprimerDebutFile(AvionFile *file);
    AvionFile *supprimerFinFile(AvionFile *file);

    avion *creerAvion(void);
    avion *rechercherAvion(AvionFile *file, int id);
    avion *retirerAvion(AvionFile *file, int id);
    avion *select_rand_in_list(AvionFile *list);

*/

int main() {
  srand(time(NULL));
  Aeroport *aeroport = creerAeroport();
  if (!aeroport) {
    printf("Erreur: Impossible de créer l'aéroport.\n");
    return 1;
  }
  while (1) {
    consume_carburant_vol(aeroport);
    manageAirport(aeroport);
    displayAirport(aeroport);
    aeroport->heure += 5; // Incrementer l'heure apres l'affichage
    sleep(2);
  }
}