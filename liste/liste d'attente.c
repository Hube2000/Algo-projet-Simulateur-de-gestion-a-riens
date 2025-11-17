//Liste d’attente pour décollage   ( H)
#include "liste d'attente.h"

LISTE_AVIONS_ATTENTE* creer_liste_avions_attente()
{
    LISTE_AVIONS_ATTENTE* liste = (LISTE_AVIONS_ATTENTE*)malloc(sizeof(LISTE_AVIONS_ATTENTE));
    liste->tete = NULL;
    liste->taille = 0;
    return liste;
}
