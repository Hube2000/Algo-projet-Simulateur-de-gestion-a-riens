#ifndef GESTION_ESSENCE_H
#define GESTION_ESSENCE_H

#include "aeroport.h"
#include "avion.h"

int fuel_check(avion *plane);
void remplir_carburant(avion *plane);
void consume_carburant_vol(Aeroport *airport);

#endif
