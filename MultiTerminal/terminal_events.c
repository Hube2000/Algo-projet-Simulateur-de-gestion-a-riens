#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#include <windows.h>
#define SLEEP(x) Sleep((x) * 1000)
#define CLEAR_SCREEN() system("cls")
#else
#include <unistd.h>
#define SLEEP(x) sleep(x)
#define CLEAR_SCREEN() system("clear")
#endif

// Inclusion des headers UI
#include "../UI/couleur.h"
#include "../UI/atterissage.h"
#include "../UI/Decollage.h"
#include "../UI/crash.h"
#include "../UI/Attack_Terroriste.h"
#include "../UI/Hack.h"

#define BUFFER_SIZE 256

int main(void) {
    FILE *file;
    char buffer[BUFFER_SIZE];
    char last_event[BUFFER_SIZE] = "";
    
    // Activer les couleurs ANSI sur Windows
    #ifdef _WIN32
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, dwMode);
    #endif
    
    printf("==============================================\n");
    printf("      TERMINAL UI - EVENEMENTS VISUELS\n");
    printf("==============================================\n\n");
    printf("En attente d'evenements...\n\n");
    
    while (1) {
        file = fopen("data_events.txt", "r");
        
        if (file != NULL) {
            // Lire le dernier événement
            while (fgets(buffer, BUFFER_SIZE, file) != NULL) {
                // Garder la dernière ligne non vide
                if (strlen(buffer) > 1) {
                    strcpy(last_event, buffer);
                }
            }
            fclose(file);
            
            // Supprimer le retour à la ligne
            last_event[strcspn(last_event, "\n")] = 0;
            
            // Afficher l'animation selon l'événement
            if (strlen(last_event) > 0) {
                if (strstr(last_event, "ATTERRISSAGE")) {
                    atterissage_UI();
                    SLEEP(2);
                    CLEAR_SCREEN();
                    printf("==============================================\n");
                    printf("      TERMINAL UI - EVENEMENTS VISUELS\n");
                    printf("==============================================\n\n");
                    printf("Dernier evenement: %s%s%s\n\n", GREEN, last_event, RESET);
                    
                } else if (strstr(last_event, "DECOLLAGE")) {
                    Decollage_UI();
                    SLEEP(2);
                    CLEAR_SCREEN();
                    printf("==============================================\n");
                    printf("      TERMINAL UI - EVENEMENTS VISUELS\n");
                    printf("==============================================\n\n");
                    printf("Dernier evenement: %s%s%s\n\n", BRIGHT_YELLOW, last_event, RESET);
                    
                } else if (strstr(last_event, "CRASH")) {
                    crash_UI();
                    SLEEP(2);
                    CLEAR_SCREEN();
                    printf("==============================================\n");
                    printf("      TERMINAL UI - EVENEMENTS VISUELS\n");
                    printf("==============================================\n\n");
                    printf("Dernier evenement: %s%s%s\n\n", RED, last_event, RESET);
                    
                } else if (strstr(last_event, "ATTAQUE")) {
                    Attack_Terroriste_UI();
                    SLEEP(2);
                    CLEAR_SCREEN();
                    printf("==============================================\n");
                    printf("      TERMINAL UI - EVENEMENTS VISUELS\n");
                    printf("==============================================\n\n");
                    printf("Dernier evenement: %s%s%s\n\n", RED, last_event, RESET);
                    
                } else if (strstr(last_event, "HACK")) {
                    hack();
                    SLEEP(2);
                    CLEAR_SCREEN();
                    printf("==============================================\n");
                    printf("      TERMINAL UI - EVENEMENTS VISUELS\n");
                    printf("==============================================\n\n");
                    printf("Dernier evenement: %s%s%s\n\n", RED, last_event, RESET);
                }
                
                // Réinitialiser pour ne pas répéter
                last_event[0] = '\0';
            }
        }
        
        SLEEP(1);
    }
    
    return 0;
}
