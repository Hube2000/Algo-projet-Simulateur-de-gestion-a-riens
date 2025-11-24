#include <stdio.h>
#include <stdlib.h>

#include "avion.h"
#include "piste.h"

typedef struct Aeroport {
  PISTE *pistes[3];
  avion *parking[50];
  int places;
  int passagers;
  int departs;
  int retours;

} Aeroport;
