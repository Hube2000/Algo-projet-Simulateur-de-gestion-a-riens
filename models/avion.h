#ifndef AVION_H
#define AVION_H

#include <stdlib.h>

struct Aeroport;

typedef enum CATEGORIE_AVION {
  AVION_DE_LIGNE,
  AVION_D_AFFAIRE,
  AVION_LEGER
} CATEGORIE_AVION;

typedef struct avion avion;

typedef struct avion {
  int id;
  CATEGORIE_AVION categorie;
  int etat; // 0 pour au sol, 1 pour en vol
  int nombre_de_passagers;
  int heure;
  struct avion *next;
  struct avion *prev;
  int carburant;
} avion;

typedef struct AvionFile {
  int nbElement;
  avion *premier;
  avion *dernier;
} AvionFile;

avion *creerAvion(struct Aeroport *airport);
AvionFile *creerAvionFile(void);
AvionFile *ajouterDebutFile(AvionFile *file, avion *a);
AvionFile *ajouterFinFile(AvionFile *file, avion *a);
AvionFile *supprimerDebutFile(AvionFile *file);
AvionFile *supprimerFinFile(AvionFile *file);
avion *rechercherAvion(AvionFile *file, int id);
avion *retirerAvion(AvionFile *file, int id);
void detruireAvionFile(AvionFile *file);

#endif
