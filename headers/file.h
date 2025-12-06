#ifndef FILE_H
#define FILE_H

#include "aeroport.h"
#include "avion.h"

AvionFile *creerAvionFile(void);
void ajouterDebutFile(AvionFile *file, avion *a);
void ajouterFinFile(AvionFile *file, avion *a);
void supprimerDebutFile(AvionFile *file);
void supprimerFinFile(AvionFile *file);
void detruireAvionFile(AvionFile *file);
void ajouter_bonne_place(Aeroport *airport, avion *plane, int indexBonnePlace);
void ajouter_bonne_place_essence(Aeroport *airport, avion *plane);

#endif

