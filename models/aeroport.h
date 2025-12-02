#ifndef AEROPORT_H
#define AEROPORT_H

#include <stdio.h>
#include <stdlib.h>

#include "avion.h"
#include "piste.h"

typedef struct Aeroport {
  PISTE *pistes[3];
  AvionFile *parking;
  AvionFile *enVol;
  int places;
  int passagers;
  int departs;
  int retours;
} Aeroport;

#endif