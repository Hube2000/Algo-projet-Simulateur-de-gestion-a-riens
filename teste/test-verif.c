#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../verif/verif.h"


int main() {
    
    printf("\n=== Tests de verification de compatibilite entre avions et pistes ===\n\n");
        // Création d'avions de différentes catégories
    avion avion_leger = { .id = 1, .categorie = AVION_LEGER };
    avion avion_affaire = { .id = 2, .categorie = AVION_D_AFFAIRE };
    avion avion_ligne = { .id = 3, .categorie = AVION_DE_LIGNE };

    // Création de pistes de différentes catégories
    PISTE piste_petite = { .numero_de_piste = 101, .categorie_piste = PISTE_PETITE };
    PISTE piste_moyenne = { .numero_de_piste = 102, .categorie_piste = PISTE_MOYENNE };
    PISTE piste_grande = { .numero_de_piste = 103, .categorie_piste = PISTE_GRANDE };

    // Vérification et affichage des compatibilités
    afficher_compatibilite(&avion_leger, &piste_petite);
    afficher_compatibilite(&avion_leger, &piste_moyenne);
    afficher_compatibilite(&avion_leger, &piste_grande);


    afficher_compatibilite(&avion_affaire, &piste_petite);
    afficher_compatibilite(&avion_affaire, &piste_moyenne);
    afficher_compatibilite(&avion_affaire, &piste_grande);

    afficher_compatibilite(&avion_ligne, &piste_petite);
    afficher_compatibilite(&avion_ligne, &piste_moyenne);
    afficher_compatibilite(&avion_ligne, &piste_grande);

    // compter_elements et parking_est_plein peuvent être testés une fois la structure AvionFile implémentée
    
    return 0;
}