#include <stdio.h>
#include <stdlib.h>

#define TAILLE_MAX 100
#define FICHIER_LISTE "liste_data.txt"

int liste[TAILLE_MAX];

void sauvegarderListe(int liste[], int taille) {
    FILE *f = fopen(FICHIER_LISTE, "w");

    if (f != NULL) {
        fprintf(f, "%d\n", taille);
        for (int i = 0; i < taille; i++) {

            fprintf(f, "%d\n", liste[i]);
        }
        fclose(f);
    }
}

int chargerListe(int liste[]) {
    FILE *f = fopen(FICHIER_LISTE, "r");
    int taille = 3;

    if (f != NULL) {
        fscanf(f, "%d", &taille);
        for (int i = 0; i < taille; i++) {
            fscanf(f, "%d", &liste[i]);
        }
        fclose(f);

    } else {
        liste[0] = 10; 
        liste[1] = 20; 
        liste[2] = 30;

        taille = 3;
        sauvegarderListe(liste, taille);
    }
    return taille;
}

void afficherListe(int liste[], int taille) {
    printf("Liste : [");
    for (int i = 0; i < taille; i++) {
        printf("%d", liste[i]);

        if (i < taille - 1) { 
            printf(", ");
        }
    }
    printf("]\n");
}

int main() {
    int taille;
    int choix;

    while (1) {

        taille = chargerListe(liste);
        afficherListe(liste, taille);

        printf("\n");
        printf("1. Ajouter un element\n");
        printf("3. Afficher la liste\n");
        printf("0. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);
        
        if (choix == 0) {
            break;
    
        } else if (choix == 1) {

            if (taille < TAILLE_MAX) {
                int valeur;
                printf("valeur a ajouter : ");
                scanf("%d", &valeur);

                liste[taille] = valeur;
                taille++;

                sauvegarderListe(liste, taille);
                printf("Element ajoute !\n\n");

            } else {
                printf("La liste est pleine !\n\n");
            }


        } else if (choix == 3) {
            printf("\n");
        } else {
            printf("Choix invalide !\n\n");
        }
    }
    
    return 0;
}
