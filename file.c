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
        file->premier = newAvion;
        file->dernier = newAvion;
    } else {
        newAvion->next = file->premier;
        file->premier->prev = newAvion;
        file->premier = newAvion;
    }
    file->nbElement++;
    return file;

}