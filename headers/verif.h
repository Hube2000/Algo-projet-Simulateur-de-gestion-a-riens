#ifndef VERIF_H
#define VERIF_H

#include <stdbool.h>

#include "aeroport.h"
#include "avion.h"
#include "piste.h"

void afficher_compatibilite(avion *av, PISTE *p);

int compter_elements(AvionFile *file);
int trouver_piste(Aeroport *airport, avion *plane);
int trouver_piste_libre(Aeroport *aeroport, avion *avion);

bool verifier_compatibilite(avion *avion, PISTE *piste);
bool parking_est_plein(AvionFile *liste_parking, int capacite_max_parking);
bool parking_est_plein_avec_reservations(Aeroport *aeroport);

#endif
