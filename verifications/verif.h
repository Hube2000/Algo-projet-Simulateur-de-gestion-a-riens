#ifndef VERIF_H
#define VERIF_H

#include <stdbool.h>

#include "../models/aeroport.h"
#include "../models/avion.h"
#include "../models/piste.h"

bool verifier_compatibilite(avion *avion, PISTE *piste);
int compter_elements(AvionFile *file);
bool parking_est_plein(AvionFile *liste_parking, int capacite_max_parking);
int *verifier_dec(Aeroport *aeroport);
void afficher_compatibilite(avion *av, PISTE *p);
int trouver_piste_libre(Aeroport *aeroport, avion *avion);
void chargement(void);

#endif
