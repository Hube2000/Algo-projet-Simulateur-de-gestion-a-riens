#ifndef LISTE_D_ATTENTE_H
#define LISTE_D_ATTENTE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "../model/piste.c"
#include "../model/avion.c"

typedef struct noeud_avion
{
    AVION* avion;
    struct noeud_avion* suivant;
} NOEUD_AVION;

typedef struct liste_avions_attente
{
    NOEUD_AVION* tete;
    int taille;
} LISTE_AVIONS_ATTENTE;


LISTE_AVIONS_ATTENTE* creer_liste_avions_attente();

void ajouter_avion_a_liste(LISTE_AVIONS_ATTENTE* liste, AVION* avion);

AVION* retirer_avion_de_liste(LISTE_AVIONS_ATTENTE* liste);

bool est_liste_vide(LISTE_AVIONS_ATTENTE* liste);

void liberer_liste_avions_attente(LISTE_AVIONS_ATTENTE* liste);

#endif 
