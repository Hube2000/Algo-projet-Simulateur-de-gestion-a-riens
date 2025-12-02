#ifndef AIRPORT_CONTROLLER_H
#define AIRPORT_CONTROLLER_H

#include "../models/aeroport.h"
#include "../models/piste.h"

PISTE *creerPiste(int numero, int longueur, CATEGORIE_PISTE categorie,
                  int capacite_max_attente);
Aeroport *creerAeroport(void);
void afficherFile(AvionFile *file);
void detruireAeroport(Aeroport *aeroport);

#endif
