#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

#include "../UI/couleur.h"
#include "../UI/atterissage.h"
#include "../UI/Decollage.h"
#include "../UI/crash.h"
#include "../UI/Attack_Terroriste.h"
#include "../UI/Hack.h"

#ifdef _WIN32
#include <windows.h>
#define SLEEP_MS(x) Sleep(x)
#define CLEAR_SCREEN() system("cls")
#else
#include <unistd.h>
#define SLEEP_MS(x) usleep((x) * 1000)
#define CLEAR_SCREEN() system("clear")
#endif

#define BUFFER_SIZE 256

int main(void) {
    FILE *file;
    char buffer[BUFFER_SIZE];
    char last_event[BUFFER_SIZE] = "";
    

    
    printf("%s==============================================\n", MAGENTA);
    printf("      TERMINAL UI - EVENEMENTS VISUELS\n");
    printf("==============================================\n%s\n", RESET);
    printf("%sEn attente d'evenements...\n%s\n", YELLOW, RESET);
    
    while (1) {
        file = fopen("data_events.txt", "r");
        
        if (file != NULL) {
            while (fgets(buffer, BUFFER_SIZE, file) != NULL) {
                if (strlen(buffer) > 1) {
                    strcpy(last_event, buffer);
                }
            }
            fclose(file);
            
            last_event[strcspn(last_event, "\n")] = 0;

            if (strlen(last_event) > 0) {
                if (strstr(last_event, "ATTERRISSAGE")) {
                    atterissage_UI();
                    SLEEP_MS(2000);
                    CLEAR_SCREEN();
                    printf("==============================================\n");
                    printf("      TERMINAL UI - EVENEMENTS VISUELS\n");
                    printf("==============================================\n\n");
                    printf("Dernier evenement: %s%s%s\n\n", GREEN, last_event, RESET);
                    
                } else if (strstr(last_event, "DECOLLAGE")) {
                    Decollage_UI();
                    SLEEP_MS(2000);
                    CLEAR_SCREEN();
                    printf("==============================================\n");
                    printf("      TERMINAL UI - EVENEMENTS VISUELS\n");
                    printf("==============================================\n\n");
                    printf("Dernier evenement: %s%s%s\n\n", BRIGHT_YELLOW, last_event, RESET);
                    
                } else if (strstr(last_event, "CRASH")) {
                    crash_UI();
                    SLEEP_MS(2000);
                    CLEAR_SCREEN();
                    printf("==============================================\n");
                    printf("      TERMINAL UI - EVENEMENTS VISUELS\n");
                    printf("==============================================\n\n");
                    printf("Dernier evenement: %s%s%s\n\n", RED, last_event, RESET);
                    
                } else if (strstr(last_event, "ATTAQUE")) {
                    Attack_Terroriste_UI();
                    SLEEP_MS(2000);
                    CLEAR_SCREEN();
                    printf("==============================================\n");
                    printf("      TERMINAL UI - EVENEMENTS VISUELS\n");
                    printf("==============================================\n\n");
                    printf("Dernier evenement: %s%s%s\n\n", RED, last_event, RESET);
                    
                } else if (strstr(last_event, "HACK")) {
                    hack();
                    SLEEP_MS(2000);
                    CLEAR_SCREEN();
                    printf("==============================================\n");
                    printf("      TERMINAL UI - EVENEMENTS VISUELS\n");
                    printf("==============================================\n\n");
                    printf("Dernier evenement: %s%s%s\n\n", RED, last_event, RESET);
                }
                
                last_event[0] = '\0';
            }
        }
        
        SLEEP_MS(1000);
    }
    
    return 0;
}
