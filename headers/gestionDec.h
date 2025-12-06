#ifndef GESTION_DEC_H
#define GESTION_DEC_H

#include "aeroport.h"
#include "avion.h"
#include "piste.h"

void decollage(Aeroport *airport, PISTE *piste);
void demander_decollage(Aeroport *airport, PISTE *piste, avion *plane);
void force_action(Aeroport *airport, PISTE *piste, avion *plane);

#endif
