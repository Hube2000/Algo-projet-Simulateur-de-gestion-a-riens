//terminal PANNEAU DE CONTROLE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

#define CALLBACK_FILE "callback_data.txt"
#define TAILLE_MAX 100
#define FICHIER_LISTE "liste_data.txt"

int liste[TAILLE_MAX];

// Déclarations de fonctions
int chargerListe(int liste[], char fichier[]);
void sauvegarderListe(int liste[], int taille, char fichier[]);
void EnvoiCallBackFunction();
bool ReciveCallBackFunction();

void EnvoiCallBackFunction() {// Envoyer une réponse au terminal 2
    printf("Envoi de la reponse au terminal 2...\n");
    FILE* f = fopen(CALLBACK_FILE, "w");
    if (f != NULL) {
        fprintf(f, "1\n2\n"); // 2 = réponse du terminal 1
        fclose(f);
    }
}

bool ReciveCallBackFunction(){// Vérifier si le terminal 2 a envoyé une requête
    int liste_callback[TAILLE_MAX];
    int taille = chargerListe(liste_callback, CALLBACK_FILE);
    
    for (int i = 0; i < taille; i++)
    {
        if (liste_callback[i] == 1){ // Requête du terminal 2 détectée
            return true;
        }    
    }
    return false;
}


bool eventrandom(){
    int r = rand() % 100;
    if (r < 95)
    {
        return false;
    }
    return true; //20% de chance d'avoir un evenement critique
}

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

    } else {
        liste[0] = 10; 
        liste[1] = 20; 
        liste[2] = 30;

        taille = 3;
        sauvegarderListe(liste, taille, fichier);
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


int main(void){
    
    while (1)
    {        
        system("cls");
        int taille = chargerListe(liste, FICHIER_LISTE);
        afficherListe(liste, taille);
        printf("\n\n\n");
        
        // Vérifier si le terminal 2 a envoyé une requête
        if(ReciveCallBackFunction()){
            printf("Requete recue du terminal 2! Traitement en cours...\n");
            
            //analyse de la demande
            for(int i=0; i<taille;i++){
                switch (liste[i])
                {
                case 1:
                    printf("  -> Execution fonction 1\n");
                    break;
                case 2:
                    printf("  -> Execution fonction 2\n");
                    break;
                case 3:
                    printf("  -> Execution fonction 3\n");
                    break;
                }
            }
            
            // Envoyer la réponse au terminal 2
            EnvoiCallBackFunction();
        }
        
        if(eventrandom()){
            printf("Evenement critique detecte !\n");
        }else{
            printf("AUCUN evenement critique detecte.\n");
        }
        
        sleep(1);
    }
    return 0;
}

