#ifndef BDD_H
#define BDD_H

#include <stdio.h>

#include "aeroport.h"
#include "avion.h"
#include "avionController.h"
#include "file.h"


/* Fonctions pour la gestion de la BDD (sauvegarde / chargement) */
void genererAvionsAleatoires(Aeroport *aeroport, int nombre_avions);

/* Sauvegarde/chargement d'un avion dans un FILE* */
void sauvegarderAvion(FILE *f, avion *a);
avion *chargerAvion(FILE *f);

/* Sauvegarde/chargement d'une file d'avions */
void sauvegarderFileAvions(FILE *f, AvionFile *file);
void chargerFileAvions(FILE *f, AvionFile *file);

/* Initialisation / sauvegarde de l'aéroport complet (fichier binaire) */
Aeroport *initAeroportBDD(const char *nom_fichier);
void sauvegarderAeroportBDD(Aeroport *aeroport, const char *nom_fichier);

/* Helpers pour sauvegarder/charger des fichiers d'avions individuels */
void chargerAvionBDD(AvionFile *file, char *path);
void sauvegarderAvionBDD(AvionFile *file);

#endif /* BDD_H */
