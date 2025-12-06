#ifndef FILE_H
#define FILE_H

#include "../models/avion.h"

AvionFile *creerAvionFile(void);

void ajouterDebutFile(AvionFile *file, avion *a);

void ajouterFinFile(AvionFile *file, avion *a);

void supprimerDebutFile(AvionFile *file);

void supprimerFinFile(AvionFile *file);

void detruireAvionFile(AvionFile *file);

#endif /* FILE_H */