#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#include "models/aeroport.h"
#include "models/avion.h"
#include "models/piste.h"

#include "controllers/airportController.h"
#include "fonctionnement/gestion.h"
#include "verifications/verif.h"

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
    manageAirport(aeroport);
    aeroport->heure += 5;
    printf("\n");
    printf("Heure actuelle : %d\n", aeroport->heure);
    printf("###########################################################\n");
    printf("##                        TERMINAL                       ##\n");
    printf("###########################################################\n");
    printf("--------------------PRAKING-----------------------\n");
    afficherFile(aeroport->parking);
    printf("\n--------------------PISTE 1-----------------------\n");
    afficherFile(aeroport->pistes[0]->liste_avions_attente);
    printf("\n--------------------PISTE 2-----------------------\n");
    afficherFile(aeroport->pistes[1]->liste_avions_attente);
    printf("\n--------------------PISTE 3-----------------------\n");
    afficherFile(aeroport->pistes[2]->liste_avions_attente);
    printf("\n--------------------EN VOL-------------------------\n");
    afficherFile(aeroport->liste_avions_en_vol);
    printf("\n--------------------FILE AERIENNE-----------------\n");
    afficherFile(aeroport->file_attente_aerienne);
    printf("\n---------------------------------------------------\n");
    printf("\n");
    sleep(2);
  }
}