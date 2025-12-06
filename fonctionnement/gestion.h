#ifndef GESTION_H
#define GESTION_H

#include "../models/aeroport.h"
#include "../models/avion.h"
#include "../models/piste.h"

void decollage_atterrissage(Aeroport *airport, PISTE *piste);
int demandeAtt(Aeroport *airport, avion *plane);
void demande_file_aerienne(Aeroport *aeroport, avion *plane);
void demandeDec(Aeroport *airport, avion *plane);
void action_on_time(Aeroport *aeroport);
void incoming_plane(Aeroport *airport);
avion *select_rand_in_list(AvionFile *list);
void manageAirport(Aeroport *airport);

#endif
