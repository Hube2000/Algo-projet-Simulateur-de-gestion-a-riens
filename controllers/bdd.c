#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../models/avion.h"

void chargerAvionBDD(AvionFile *file,char *path){
    FILE *f = fopen(path,"rb");
    if(!f) {
        printf("ERREUR DE BDD %s\n",path);
    }
    int id, categorie, etat, nombre_de_passagers;
    while(fread(&id, sizeof(int), 1, f) == 1 &&
          fread(&categorie, sizeof(int), 1, f) == 1 &&
          fread(&etat, sizeof(int), 1, f) == 1 &&
          fread(&nombre_de_passagers, sizeof(int), 1, f) == 1)
    {
        avion *a = creerAvion();
        a->id = id;
        a->categorie = (CATEGORIE_AVION)categorie;
        a->etat = etat;
        a->nombre_de_passagers = nombre_de_passagers;
        ajouterDebutFile(file, a);
    }
}


void sauvegarderAvionBDD(AvionFile *file){
    // Implementer avec un sprintf pour le path comme un vrai log
    FILE *f = fopen("log","wb"); 
    if(!f) {
        printf("ERREUR DE BDD %s\n");
    }
    avion *current = file->premier;
    while(current != NULL){
        fwrite(&current->id, sizeof(int), 1, f);
        int categorie = current->categorie;
        fwrite(&categorie, sizeof(int), 1, f);
        fwrite(&current->etat, sizeof(int), 1, f);
        fwrite(&current->nombre_de_passagers, sizeof(int), 1, f);
        current = current->next;
    }
    fclose(f);
}