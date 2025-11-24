

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "avion.h"

typedef enum CATEGORIE_PISTE
{
    PISTE_PETITE,
    PISTE_MOYENNE,
    PISTE_GRANDE
} CATEGORIE_PISTE;

typedef struct piste PISTE;


struct piste
{
    int numero_de_piste;
    int longueur;
    CATEGORIE_PISTE categorie_piste;
    int nombre_max_avions_attente;
    AvionFile* liste_avions_attente; // Pointeur vers la liste chaînée des avions en attente
} PISTE;
