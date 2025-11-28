#ifndef VERIF_H
#define VERIF_H
#include <stdbool.h>
#include "../models/aeroport.h"

bool verifier_compatibilite(avion *avion, PISTE *piste);
bool parking_est_plein(AvionFile *liste_parking, int capacite_max_parking);
int compter_elements(AvionFile *file);
void afficher_compatibilite(avion *av, PISTE *p);
// bool file_attente_piste_pleine(PISTE *piste); // a faire quand la liste d'attente sera fini

#endif 
