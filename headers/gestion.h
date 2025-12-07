#ifndef GESTION_H
#define GESTION_H

#include "aeroport.h"
#include "avion.h"
#include "piste.h"

void action_on_time(Aeroport *aeroport);
void incoming_plane(Aeroport *airport);
void manageAirport(Aeroport *airport);
void ajoutHeure(Aeroport *airport, PISTE *piste, avion *plane);
void displayAirport(Aeroport *airport);
void writeAirportInfo(Aeroport *airport);

avion *select_rand_in_list(AvionFile *list);

#endif
