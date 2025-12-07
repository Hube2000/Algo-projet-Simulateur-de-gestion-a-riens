#ifndef EVENTS_H
#define EVENTS_H

#include "aeroport.h"

void MeteoEvent(Aeroport *aeroport);
void AttaqueTerroristeEvent(Aeroport *aeroport);
void HackEvent(Aeroport *aeroport);
void triggerRandomEvent(Aeroport *airport);

#endif /* EVENTS_H */
