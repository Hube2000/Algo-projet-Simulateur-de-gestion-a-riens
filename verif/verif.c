#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "avion.h"
#include "piste.h"
#include "verif.h"


bool verifier_compatibilite(avion *avion, PISTE *piste) {
    if (avion == NULL || piste == NULL) {
        return false;
    }
    
    switch (avion->categorie) {
        case AVION_LEGER:
            // Avion léger peut utiliser toutes les pistes
            return true;
            
        case AVION_D_AFFAIRE:
            // Avion d'affaire peut utiliser piste moyenne ou grande
            return (piste->categorie_piste == PISTE_MOYENNE || 
                    piste->categorie_piste == PISTE_GRANDE);
            
        case AVION_DE_LIGNE:
            // Avion de ligne nécessite une grande piste
            return (piste->categorie_piste == PISTE_GRANDE);
            
        default:
            return false;
    }
}


int compter_elements(AvionFile *file) {
    if (file == NULL) {
        return 0;
    }
    return file->nbElement;
}


bool parking_est_plein(AvionFile *liste_parking, int capacite_max_parking) {
    if (liste_parking == NULL) {
        return true; // Si pas de parking, considéré comme plein pr le moment
    }
    
    int nb_avions = compter_elements(liste_parking);
    return (nb_avions >= capacite_max_parking);
}

// bool file_attente_piste_pleine(PISTE *piste) {
// a faire quand file (pr la liste d'attente) sera fini et que la brnaches de gestion de file sois ok
// }


void afficher_compatibilite(avion *av, PISTE *p) {
    if (verifier_compatibilite(av, p)) {
        printf("Avion #%d ", av->id);
        switch(av->categorie) {
            case AVION_LEGER: printf("Léger)"); break;
            case AVION_D_AFFAIRE: printf("Affaire)"); break;
            case AVION_DE_LIGNE: printf("Ligne)"); break;
        }

        printf(" - compatible avec Piste #%d (", p->numero_de_piste);
        switch(p->categorie_piste) {
            case PISTE_PETITE: printf("Petite)"); break;
            case PISTE_MOYENNE: printf("Moyenne)"); break;
            case PISTE_GRANDE: printf("Grande)"); break;
        }
        printf("\n");
    } else {
        printf("incompatibilite\n");
    }
}
