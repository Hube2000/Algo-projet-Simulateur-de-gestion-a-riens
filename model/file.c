#include <stlio.h>
#include <stdlib.h>
#include <string.h>
#include "/model/avion.c"
#include "/model/piste.c"

avion * creerAvion(){
    avion * newAvion = malloc(sizeof(avion));
    newAvion->identifiant = rand() % 51 + 1; 
    newAvion->categorie = rand() % 3;
    newAvion->etat = 0;
    newAvion->nombre_de_passagers =0;
    newAvion->next = NULL;
    newAvion->prev = NULL;
    return newAvion;
}

AvionFile *creerAvionFile(){
    AvionFile *file = malloc(sizeof(AvionFile));
    file->nbElement = 0;
    file->premier = NULL;
    file->dernier = NULL;
    return file;
}

AvionFile ajouterDebutFile(AvionFile *file, avion *avion){
    
    if(file->nbElement == 0){
        file->premier = avion;
        file->dernier = avion;
    } else {
        newAvion->next = file->premier;
        file->premier->prev = avion;
        file->premier = avion;
    }
    file->nbElement++;
    return file;

}

AvionFile ajouterFinFile(AvionFile *file, avion *avion){
    if(file->nbElement == 0){
        file->premier = avion;
        file->dernier = avion;
    } else {
        file->dernier->next = avion;
        newAvion->prev = file->dernier;
        file->dernier = avion;
    }
    file->nbElement++;
    return file;
}


AvionFile supprimerDebutFile(AvionFile *file){
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

AvionFile supprimerFinFile(AvionFile *file){
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
