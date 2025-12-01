//terminal data management

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

#define CALLBACK_FILE "callback_data.txt"
#define TAILLE_MAX 100
#define FICHIER_LISTE "liste_data.txt"

int liste[TAILLE_MAX];

void sauvegarderListe(int liste[], int taille, char fichier[]) {
    FILE *f = fopen(fichier, "w");

    if (f != NULL) {
        fprintf(f, "%d\n", taille);
        for (int i = 0; i < taille; i++) {

            fprintf(f, "%d\n", liste[i]);
        }
        fclose(f);
    }
}

void viderListe(int liste[], int taille, char fichier[]) {
    FILE *f = fopen(fichier, "w");
    if (f != NULL) {
        fprintf(f, "0\n");
        fclose(f);
    }
}

int chargerListe(int liste[], char fichier[]) {
    FILE *f = fopen(fichier, "r");
    int taille = 3;

    if (f != NULL) {
        fscanf(f, "%d", &taille);
        for (int i = 0; i < taille; i++) {
            fscanf(f, "%d", &liste[i]);
        }
        fclose(f);

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

void EnvoiCallBackFunction() {// Envoyer une requête au terminal 1
    printf("Envoi de la requete au terminal 1...\n");
    FILE* f = fopen(CALLBACK_FILE, "w");
    if (f != NULL) {
        fprintf(f, "1\n1\n"); // 1 = requête du terminal 2
        fclose(f);
    }
}


void ReciveCallBackFunction(){// Attendre la réponse du terminal 1
    printf("Attente de la reponse du terminal 1...\n");
    int liste_callback[TAILLE_MAX];
    bool reponse_recue = false;

    while (!reponse_recue) {
        int taille = chargerListe(liste_callback, CALLBACK_FILE);
        for (int i = 0; i < taille; i++)
        {
            if (liste_callback[i] == 2){ // Réponse du terminal 1 reçue
                reponse_recue = true;
                printf("Reponse recue du terminal 1!\n");
                // Nettoyer le fichier callback
                FILE* f = fopen(CALLBACK_FILE, "w");
                if (f != NULL) {
                    fprintf(f, "0\n");
                    fclose(f);
                }
                break;
            }
        }
        if (!reponse_recue) {
            sleep(1);    
        }
    }
}



int main(void){
    int choix = 0;
    int taille = chargerListe(liste, FICHIER_LISTE);
    while (1)
    {
        printf("action faisable test\n");
        printf("1. Action 1\n");
        printf("2. Action 2\n");
        printf("3. Action 3\n");
        printf("0. Quitter\n");

        printf("\nchoix : ");
        scanf("%d", &choix);

        if(choix == 0) {
            break;
        }
        switch (choix)
        {
            case 1:
            {
            if (taille < TAILLE_MAX) {
                int valeur;
                valeur = 1;
                liste[taille] = valeur;
                taille++;
                sauvegarderListe(liste, taille, FICHIER_LISTE);
                printf("Element %d ajouté.\n", valeur);
                EnvoiCallBackFunction();
                //attente de retour de l'autre terminal
                ReciveCallBackFunction();
            }

            }
                break;

            case 2:
            if (taille < TAILLE_MAX) {
                int valeur;
                valeur = 2;
                liste[taille] = valeur;
                taille++;
                sauvegarderListe(liste, taille, FICHIER_LISTE);
                printf("Element %d ajouté.\n", valeur);
                EnvoiCallBackFunction();
                //attente de retour de l'autre terminal
                ReciveCallBackFunction();
            }
                break;

            case 3:           
             if (taille < TAILLE_MAX) {
                int valeur;
                valeur = 3;
                liste[taille] = valeur;
                taille++;
                sauvegarderListe(liste, taille, FICHIER_LISTE);
                printf("Element %d ajouté.\n", valeur);
                EnvoiCallBackFunction();
                //attente de retour de l'autre terminal
                ReciveCallBackFunction();
            }

                break;
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
                break;
        }
    }   
    return 0;
}

