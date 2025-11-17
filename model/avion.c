#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef enum CATEGORIE_AVION
{
    AVION_DE_LIGNE,
    AVION_D_AFFAIRE,
    AVION_LEGER
} CATEGORIE_AVION;

typedef struct avion
{
    int identifiant; 
    CATEGORIE_AVION categorie;
    int etat; // 0 pour au sol, 1 pour en vol
    int nombre_de_passagers;
};