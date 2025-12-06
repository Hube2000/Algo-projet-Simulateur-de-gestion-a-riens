#ifndef GESTION_ATT_H
#define GESTION_ATT_H

#include "aeroport.h"
#include "avion.h"
#include "piste.h"

int test_Att(Aeroport *airport, avion *plane);
void demander_atterissage(Aeroport *airport, PISTE *piste, avion *plane);
void demander_file_aerienne(Aeroport *airport, avion *plane);
void atterissage(Aeroport *airport, PISTE *piste);

#endif
