#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "avion.h"

avion * creerAvion(){
    avion * newAvion = malloc(sizeof(avion));
    if(!newAvion) return NULL;
    newAvion->id = rand() % 51 + 1; // random id 1-50
    newAvion->categorie = (CATEGORIE_AVION)(rand() % 3);
    newAvion->etat = 0;
    newAvion->nombre_de_passagers = 0;
    newAvion->next = NULL;
    newAvion->prev = NULL;
    return newAvion;
}

AvionFile *creerAvionFile(){
    AvionFile *file = malloc(sizeof(AvionFile));
    if(!file) return NULL;
    file->nbElement = 0;
    file->premier = NULL;
    file->dernier = NULL;
    return file;
}

AvionFile * ajouterDebutFile(AvionFile *file, avion *a){
    if(!file || !a) return file;
    if(file->nbElement == 0){
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
    return file;

}

