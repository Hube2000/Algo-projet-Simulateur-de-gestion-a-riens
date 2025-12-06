#ifndef BDD_H
#define BDD_H

#include "../models/aeroport.h"
#include "../models/avion.h"
#include "../models/piste.h"

// Fonction principale : initialiser ou charger l'aéroport depuis la BDD
// Si le fichier n'existe pas, crée un nouvel aéroport avec des avions aléatoires
Aeroport *initAeroportBDD(const char *nom_fichier);
void sauvegarderAeroportBDD(Aeroport *aeroport, const char *nom_fichier);
void genererAvionsAleatoires(Aeroport *aeroport, int nombre_avions);
void chargerAvionBDD(AvionFile *file, char *path);
void sauvegarderAvionBDD(AvionFile *file);

#endif
