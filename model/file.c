#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "avion.h"

avion * creerAvion(){
    avion * newAvion = malloc(sizeof(avion));
    if(!newAvion) return NULL;
    newAvion->identifiant = rand() % 51 + 1;
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

AvionFile * ajouterFinFile(AvionFile *file, avion *a){
    if(!file || !a) return file;
    if(file->nbElement == 0){
        file->premier = a;
        file->dernier = a;
        a->next = NULL;
        a->prev = NULL;
    } else {
        file->dernier->next = a;
        a->prev = file->dernier;
        a->next = NULL;
        file->dernier = a;
    }
    file->nbElement++;
    return file;
}



AvionFile * supprimerDebutFile(AvionFile *file){
    if(file->nbElement == 0){
        return file;
    } else {
        avion *temp = file->premier;
        file->premier = file->premier->next;
        if(file->premier != NULL){
            file->premier->prev = NULL;
        } else {
            file->dernier = NULL; // file -> VIDE
        }
        free(temp);
        file->nbElement--;
    }
    return file;
}

AvionFile *supprimerFinFile(AvionFile *file){
    if(file->nbElement == 0){
        return file;
    } else {
        avion *temp = file->dernier;
        file->dernier = file->dernier->prev;
        if(file->dernier != NULL){
            file->dernier->next = NULL;
        } else {
            file->premier = NULL; // file -> VIDE
        }
        free(temp);
        file->nbElement--;
    }
    return file;
}

avion * rechercherAvion(AvionFile *file, int id){ 
    if(!file) return NULL;
    avion *current = file->premier;
    while(current != NULL){
        if(current->identifiant == id){
            return current;
        }
        current = current->next;
    }
    return NULL;
}