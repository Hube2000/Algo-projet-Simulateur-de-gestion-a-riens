#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


//pr que ca marche par tout le  ( l'untie c les seconds )
#ifdef _WIN32
#include <windows.h>
#define SLEEP(x) Sleep((x) * 1000)
#else
#include <unistd.h>
#define SLEEP(x) sleep(x)
#endif

#include "../headers/aeroport.h"
#include "../headers/airportController.h"
#include "../headers/avion.h"
#include "../headers/bdd.h"
#include "../headers/events.h"
#include "../headers/gestion.h"
#include "../headers/gestionEssence.h"
#include "../headers/piste.h"
#include "../headers/verif.h"

#define NB_PISTES 3

// Fonction pour écrire les informations de cycle
void ecrire_cycle_info(int cycle_count) {
    FILE *f = fopen("../MultiTerminal/data_cycles.txt", "a");
    if (f) {
        fprintf(f, "\n========================================\n");
        fprintf(f, "           CYCLE : %d\n", cycle_count);
        fprintf(f, "========================================\n");
        fclose(f);
    }
}

// Fonction pour écrire les logs d'activités
void ecrire_log_activite(const char* type, const char* message) {
    FILE *f = fopen("../MultiTerminal/data_cycles.txt", "a");
    if (f) {
        time_t now = time(NULL);
        struct tm *t = localtime(&now);
        fprintf(f, "[%02d:%02d:%02d] %s: %s\n", 
                t->tm_hour, t->tm_min, t->tm_sec, 
                type, message);
        fclose(f);
    }
}

// Fonction pour écrire les informations générales de l'aéroport
void ecrire_info_generale(Aeroport *aeroport) {
    FILE *f = fopen("../MultiTerminal/data_info.txt", "w");
    if (f) {
        fprintf(f, "HEURE ACTUELLE: %d minutes\n\n", aeroport->heure);
        
        // Compter les avions dans chaque file
        int nb_parking = 0, nb_vol = 0, nb_aerienne = 0;
        
        if (aeroport->parking) {
            nb_parking = aeroport->parking->nbElement;
        }
        
        if (aeroport->liste_avions_en_vol) {
            nb_vol = aeroport->liste_avions_en_vol->nbElement;
        }
        
        if (aeroport->file_attente_aerienne) {
            nb_aerienne = aeroport->file_attente_aerienne->nbElement;
        }
        
        fprintf(f, "STATISTIQUES:\n");
        fprintf(f, "  - Avions au parking: %d / %d places\n", nb_parking, aeroport->places);
        fprintf(f, "  - Avions en vol: %d\n", nb_vol);
        fprintf(f, "  - Avions en file aerienne: %d\n", nb_aerienne);
        fprintf(f, "  - Total avions geres: %d\n\n", aeroport->total_avions);
        
        fprintf(f, "ETAT DES PISTES:\n");
        for (int i = 0; i < NB_PISTES; i++) {
            fprintf(f, "  Piste %d: ", i + 1);
            if (aeroport->pistes[i]->liste_avions_attente && 
                aeroport->pistes[i]->liste_avions_attente->nbElement > 0) {
                fprintf(f, "%d avion(s) en attente\n", 
                        aeroport->pistes[i]->liste_avions_attente->nbElement);
            } else {
                fprintf(f, "Aucun avion en attente\n");
            }
        }
        
        fclose(f);
    }
}

#include "../headers/aeroport.h"
#include "../headers/airportController.h"
#include "../headers/avion.h"
#include "../headers/bdd.h"
#include "../headers/events.h"
#include "../headers/gestion.h"
#include "../headers/gestionEssence.h"
#include "../headers/piste.h"
#include "../headers/verif.h"

#define NB_PISTES 3

static Aeroport *aeroport_global = NULL;

void gestionnaire_arret(int sig) {
    (void)sig; // Évite l'avertissement du compilateur
    printf("\n\n>>> Arrêt demandé, sauvegarde en cours...\n");
    if (aeroport_global) {
        sauvegarderAeroportBDD(aeroport_global, "aeroport.bin");
        detruireAeroport(aeroport_global);
        printf("Sauvegarde terminée. Au revoir !\n");
    }
    exit(0);
}


int main(void) {
    srand(time(NULL));

    // Initialiser les fichiers de données
    FILE *f_cycles = fopen("../MultiTerminal/data_cycles.txt", "w");
    if (f_cycles) {
        fprintf(f_cycles, "==============================================\n");
        fprintf(f_cycles, "  DEMARRAGE DE LA SIMULATION\n");
        fprintf(f_cycles, "==============================================\n");
        fclose(f_cycles);
    }
    
    FILE *f_info = fopen("../MultiTerminal/data_info.txt", "w");
    if (f_info) {
        fprintf(f_info, "Initialisation en cours...\n");
        fclose(f_info);
    }
    
    FILE *f_events = fopen("../MultiTerminal/data_events.txt", "w");
    if (f_events) {
        fprintf(f_events, "En attente d'evenements...\n");
        fclose(f_events);
    }

    // c quoi ce truc mdr, gab j'espère tu as pas fait n'imp...
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

    printf("Aéroport initialisé avec succès!\n");
    printf("Démarrage de la simulation\n\n");

    SLEEP(2);
    while (1) {
        cycle_count++;
        
        // Écrire les informations de cycle
        ecrire_cycle_info(cycle_count);
        
        printf("\n");
        printf("cycle : %d\n", cycle_count);
        consume_carburant_vol(aeroport);
        manageAirport(aeroport);
        displayAirport(aeroport);
        triggerRandomEvent(aeroport);
        aeroport->heure += 5;
        
        // Écrire les informations générales
        ecrire_info_generale(aeroport);

        //SAUVEGARDE AUTOMATIQUE TOUS LES 10 CYCLES
        cycle_sauvegarde++;
        if (cycle_sauvegarde >= 10) {
            printf("\nSauvegarde automatique\n");
            sauvegarderAeroportBDD(aeroport_global, "aeroport.bin");
            cycle_sauvegarde = 0;
            printf("Sauvegarde terminée!\n\n");
        }
        SLEEP(2);
    }

    // Normalement cette ligne ne sera pas lue mais on garde par sécurité
    sauvegarderAeroportBDD(aeroport_global, "aeroport.bin");
    detruireAeroport(aeroport_global);
    return 0;
}
