#include "piste.h"
#include <stdio.h>
#include <stdlib.h>
#include <avion.h>

PISTE * init_aeroport(int cap_parking, int cap_piste1, int cap_piste2, int cap_piste3){
    PISTE * aeroport = malloc(3*sizeof(PISTE));
    if(!aeroport) return NULL;
    aeroport[0].numero_de_piste = 1;
    aeroport[0].longueur = 3000;
    aeroport[0].categorie_piste = PISTE_GRANDE;
    aeroport[0].nombre_max_avions_attente = cap_piste1;
    aeroport[0].liste_avions_attente = NULL;
    aeroport[1].numero_de_piste = 2;
    aeroport[1].longueur = 2000;
    aeroport[1].categorie_piste = PISTE_MOYENNE;
    aeroport[1].nombre_max_avions_attente = cap_piste2;
    aeroport[1].liste_avions_attente = NULL;
    aeroport[2].numero_de_piste = 3;
    aeroport[2].longueur = 1000;
    aeroport[2].categorie_piste = PISTE_PETITE;
    aeroport[2].nombre_max_avions_attente = cap_piste3;
    aeroport[2].liste_avions_attente = NULL;
    return aeroport;
}

void charger_bdd(PISTE *aeroport,const char* path){
    FILE* file = fopen(path,"r");
    if(!file) return;
    AvionFile * file_avions = creerAvionFile();
    
    avion * current = file_avions->premier;
    while(current != NULL ){


}