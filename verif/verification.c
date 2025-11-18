#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "avion.c"
#include "piste.c"
#include "file.c"

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


// il y a un probleme avec la liste d'attente qui n'est pas encore implementée

// bool file_attente_piste_pleine(PISTE *piste) {
//     if (piste == NULL) {
//         return true;
//     }
    

//     int nb_avions_en_attente = 0;
//     struct avion_attente *current = piste->liste_avions_attente;
    
//     while (current != NULL) {
//         nb_avions_en_attente++;
//         current = current->next; // Supposant qu'il y a un pointeur next sur le sur la liste d'attente
//     }
    
//     return (nb_avions_en_attente >= piste->nombre_max_avions_attente);
// }


void afficher_compatibilite(avion *av, PISTE *p) {
    if (verifier_compatibilite(av, p)) {
        printf("Avion #%d ", av->identifiant);
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


// a remplacer (le nom ) quand tt est fini
//int tester_verif(void) {
int main ( void) {
    // Creation avions test
    avion *avion_leger = creerAvion();
    avion_leger->categorie = AVION_LEGER;
    
    avion *avion_affaire = creerAvion();
    avion_affaire->categorie = AVION_D_AFFAIRE;
    
    avion *avion_ligne = creerAvion();
    avion_ligne->categorie = AVION_DE_LIGNE;
    
    // Cration pistes test 
    PISTE piste_petite = {1, 1200, PISTE_PETITE, 5, NULL};
    PISTE piste_moyenne = {2, 2000, PISTE_MOYENNE, 8, NULL};
    PISTE piste_grande = {3, 3500, PISTE_GRANDE, 12, NULL};
    
    // Test compatibilité
    printf("Compatibilité avion-piste\n");
    afficher_compatibilite(avion_leger, &piste_petite);
    afficher_compatibilite(avion_affaire, &piste_petite);
    afficher_compatibilite(avion_ligne, &piste_petite);
    afficher_compatibilite(avion_ligne, &piste_grande);
    
    // Test parking plein
    printf("\nParking:  \n");
    AvionFile *parking = creerAvionFile();
    int capacite = 3;
    
    printf("Parking vide: %s\n", parking_est_plein(parking, capacite) ? "PLEIN" : "LIBRE");
    
    ajouterFinFile(parking, avion_leger);
    ajouterFinFile(parking, avion_affaire);

    printf("Parking (2/%d): %s\n", capacite, parking_est_plein(parking, capacite) ? "PLEIN" : "LIBRE");
    
    ajouterFinFile(parking, avion_ligne);

    printf("Parking (3/%d): %s\n", capacite, parking_est_plein(parking, capacite) ? "PLEIN" : "LIBRE");
    

    printf("File d'attente piste\n");

    // a verif quand la liste d'attente sera fini
    // printf("Piste grande - File attente: %s\n", file_attente_piste_pleine(&piste_grande) ? "PLEINE" : "DISPONIBLE");
    
    return 0;
}
