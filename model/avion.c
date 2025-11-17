#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct avion avion;
typedef struct AvionFile AvionFile;

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
    avion* next;
    avion* prev;
};

struct AvionFile AvionFile;
struct AvionFile{
    int nbElement;
    avion *premier;
    avion  *dernier;
}

