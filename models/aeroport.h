#ifndef AEROPORT_H
#define AEROPORT_H

#include <stdio.h>
#include <stdlib.h>

#include "avion.h"
#include "piste.h"

typedef struct Aeroport {
  PISTE *pistes[3];
  AvionFile *parking;
  AvionFile *liste_avions_en_vol;
  AvionFile *file_attente_aerienne;
  int places;
  int passagers;
  int departs;
  int retours;
  int heure;
  int total_avions;
} Aeroport;

#endif