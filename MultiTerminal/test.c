#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#include "aeroport.h"
#include "airportController.h"
#include "avion.h"
#include "bdd.h"
#include "events.h"
#include "gestion.h"
#include "gestionEssence.h"
#include "piste.h"
#include "verif.h"
#include "../UI/logs_ui.h"

#ifdef _WIN32
#include <windows.h>
#define SLEEP_MS(x) Sleep(x)
#define CLEAR_SCREEN() system("cls")
#else
#include <unistd.h>
#define SLEEP_MS(x) usleep((x) * 1000)
#define CLEAR_SCREEN() system("clear")
#endif

#define NB_PISTES 3

/*  PK IL Y A TT CES DECLARATION ICI ???


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

// Variable globale pour l'aéroport (nécessaire pour le gestionnaire de signal)
static Aeroport *aeroport_global = NULL;

// Gestionnaire de signal pour sauvegarder avant de quitter (Ctrl+C)
void gestionnaire_arret(int sig) {
  (void)sig; // Évite l'avertissement du compilateur
  printf("\n\n>>> Arrêt demandé, sauvegarde en cours...\n");
  if (aeroport_global) {
    sauvegarderAeroportBDD(aeroport_global, "aeroport.bin");
    detruireAeroport(aeroport_global);
    printf(">>> Sauvegarde terminée. Au revoir !\n");
  }
  exit(0);
}

int main() {
  srand(time(NULL));

  // IMPORTANT CA EN GROS SIGINIT c'est le signal interrupt ça se declenche par
  // exemple avec le ctrl+c ET LE SIGTERM c'est le signal term envoyé par le
  // systeme (un kill processus) signal c'est une fonction natif au c qui permet
  // d'enregister le signal systeme

  signal(SIGINT, gestionnaire_arret);
  signal(SIGTERM, gestionnaire_arret);

  aeroport_global = initAeroportBDD("aeroport.bin");
  if (!aeroport_global) {
    printf("ERREUR: Impossible de créer/charger l'aéroport.\n");
    return 1;
  }

  Aeroport *aeroport = aeroport_global;
  int cycle_sauvegarde = 0;
  int cycle_count = 0;
  if (!aeroport) {
    printf("Erreur: Impossible de créer l'aéroport.\n");
    return 1;
  }
  while (1) {
    cycle_count++;
    ecrire_entete_cycle(cycle_count);
    consume_carburant_vol(aeroport);
    manageAirport(aeroport);
    displayAirport(aeroport);
    writeAirportInfo(aeroport);
    triggerRandomEvent(aeroport);
    aeroport->heure += 5;
    cycle_sauvegarde++;
    if (cycle_sauvegarde >= 10) {
      printf(">>> Sauvegarde automatique...\n");
      sauvegarderAeroportBDD(aeroport_global, "aeroport.bin");
      cycle_sauvegarde = 0;
      printf(">>> Sauvegarde terminée \n\n");
    }
    SLEEP_MS(3000);
  }
  // Normalement cette ligne ne sera pas lu mais on sait jamais (sécurité)
  sauvegarderAeroportBDD(aeroport_global, "aeroport.bin");
  detruireAeroport(aeroport_global);
  return 0;
}