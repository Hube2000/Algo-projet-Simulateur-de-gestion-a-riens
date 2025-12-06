#ifndef AVION_CONTROLLER_H
#define AVION_CONTROLLER_H

#include "aeroport.h"
#include "avion.h"

avion *creerAvion(Aeroport *airport);
avion *rechercherAvion(AvionFile *file, int id);
void retirerAvion(AvionFile *file, int id);

#endif
