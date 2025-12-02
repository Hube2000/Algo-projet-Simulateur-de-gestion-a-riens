#include <stdlib.h>
#include <stdio.h>
#include "../models/avion.h"
#include "../models/aeroport.h"
#include "../controllers/avionController.c"

/* EVENT DISPONIBLES
- Météo -> Decale le temps de décollage + random (selon gravite )-> (pluie,orage,neige)
- Attaque terroriste -> Detruit un avion en vol

*/


void MeteoEvent(Aeroport *aeroport){
    int meteo = rand() % 3; // 0: pluie, 1: orage, 2: neige
    int decalage;

    switch(meteo){
        case 0:
            decalage = 10 + rand() % 11; // Décalage entre 10 et 20 minutes
            printf("Météo : Pluie Décalage des décollages de %d minutes.\n", decalage);
            break;
        case 1:
            decalage = 20 + rand() % 21; // Décalage entre 20 et 40 minutes
            printf("Météo : Orage Décalage des décollages de %d minutes.\n", decalage);
            break;
        case 2:
            decalage = 30 + rand() % 31; // Décalage entre 30 et 60 minutes
            printf("Météo : Neige Décalage des décollages de %d minutes.\n", decalage);
            break;
        default:
            decalage = 0;
            break;
    }
    
    // Decale le temps de décollage pour tout les avions
    for(int i=0;i<aeroport->pistes[i]!=NULL;i++){
        PISTE *piste = aeroport->pistes[i];
        avion *current = piste->liste_avions_attente->premier;
        while(current){
            current->heure_decollage += decalage;
            current = current->next;
        }
    }    
}

void AttaqueTerroristeEvent(Aeroport *aeroport){
    if(aeroport->enVol->nbElement == 0){
        printf("Aucun avion en vol pour être ciblé.\n");
        return;
    }
    int randomIndex = rand() % aeroport->enVol->nbElement;
    avion *current = aeroport->enVol->premier;
    for(int i=0;i<randomIndex;i++){
        current = current->next;
    }
    printf("L'avion 'ID %d a été ciblé et s'est écrasé.\n", current->id);
    retirerAvion(aeroport->enVol, current->id);
}