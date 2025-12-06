#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <signal.h>

#include "models/aeroport.h"
#include "models/avion.h"
#include "models/piste.h"

#include "controllers/airportController.h"
#include "fonctionnement/gestion.h"
#include "fonctionnement/bdd.h"
#include "verifications/verif.h"

#define NB_PISTES 3

// Variable globale pour l'aéroport (nécessaire pour le gestionnaire de signal)
static Aeroport *aeroport_global = NULL;

// Gestionnaire de signal pour sauvegarder avant de quitter (Ctrl+C)
void gestionnaire_arret(int sig)
{
    (void)sig; // Évite l'avertissement du compilateur
    printf("\n\n>>> Arrêt demandé, sauvegarde en cours...\n");
    if (aeroport_global)
    {
        sauvegarderAeroportBDD(aeroport_global, "aeroport.bin");
        detruireAeroport(aeroport_global);
        printf(">>> Sauvegarde terminée. Au revoir !\n");
    }
    exit(0);
}

int main()
{
    srand(time(NULL));

    // IMPORTANT CA EN GROS SIGINIT c'est le signal interrupt ça se declenche par exemple avec le ctrl+c
    // ET LE SIGTERM c'est le signal term envoyé par le systeme (un kill processus)
    // signal c'est une fonction natif au c qui permet d'enregister le signal systeme
    signal(SIGINT, gestionnaire_arret);
    signal(SIGTERM, gestionnaire_arret);

    printf("========================================\n");
    printf("  SIMULATEUR DE GESTION AÉRIENNE\n");
    printf("========================================\n\n");

    aeroport_global = initAeroportBDD("aeroport.bin");
    if (!aeroport_global)
    {
        printf("ERREUR: Impossible de créer/charger l'aéroport.\n");
        return 1;
    }

    printf("\n >>> Aéroport initialisé avec succès !\n");
    printf(">>> Appuyez sur Ctrl+C pour quitter et sauvegarder.\n");
    printf(">>> Sauvegarde automatique tous les 10 cycles.\n\n");

    int cycle_sauvegarde = 0;
    while (1)
    {
        manageAirport(aeroport_global);
        aeroport_global->heure += 5;

        printf("\n");
        printf("Heure actuelle : %d\n", aeroport_global->heure);
        printf("###########################################################\n");
        printf("##                        TERMINAL                       ##\n");
        printf("###########################################################\n");
        printf("--------------------PARKING-----------------------\n");
        afficherFile(aeroport_global->parking);
        printf("\n--------------------PISTE 1-----------------------\n");
        afficherFile(aeroport_global->pistes[0]->liste_avions_attente);
        printf("\n--------------------PISTE 2-----------------------\n");
        afficherFile(aeroport_global->pistes[1]->liste_avions_attente);
        printf("\n--------------------PISTE 3-----------------------\n");
        afficherFile(aeroport_global->pistes[2]->liste_avions_attente);
        printf("\n--------------------EN VOL-------------------------\n");
        afficherFile(aeroport_global->liste_avions_en_vol);
        printf("\n--------------------FILE AERIENNE-----------------\n");
        afficherFile(aeroport_global->file_attente_aerienne);
        printf("\n---------------------------------------------------\n");
        printf("\n");

        // Save automatique tous les 10 cycles
        cycle_sauvegarde++;
        if (cycle_sauvegarde >= 10)
        {
            printf(">>> Sauvegarde automatique...\n");
            sauvegarderAeroportBDD(aeroport_global, "aeroport.bin");
            cycle_sauvegarde = 0;
            printf(">>> Sauvegarde terminée \n\n");
        }

        sleep(2);
    }

    // Normalement cette ligne ne sera pas lu mais on sait jamais (sécurité)
    sauvegarderAeroportBDD(aeroport_global, "aeroport.bin");
    detruireAeroport(aeroport_global);
    return 0;
}