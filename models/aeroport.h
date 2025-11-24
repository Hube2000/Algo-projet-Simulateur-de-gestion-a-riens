#include <stdio.h>
#include <stdlib.h>

#include ".file.c"
#include "avion.c"
#include "piste.c"

typedef struct Aeroport {
  PISTE *pistes[3];
  Avion *parking[50];
  int places;
  int passagers;
  int departs;
  int retours;
} Aeroport;