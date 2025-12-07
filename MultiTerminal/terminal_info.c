#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#include <windows.h>
#define SLEEP_MS(x) Sleep(x)
#define CLEAR_SCREEN() system("cls")
#else
#include <unistd.h>
#define SLEEP_MS(x) usleep((x) * 1000)
#define CLEAR_SCREEN() system("clear")
#endif

#include "../UI/couleur.h"

#define BUFFER_SIZE 4096

int main(void) {
    FILE *file;
    char buffer[BUFFER_SIZE];
    
    printf("%s==============================================\n", GREEN);
    printf("   TERMINAL INFO - INFORMATIONS GENERALES\n");
    printf("==============================================\n%s\n", RESET);
    
    while (1) {
        CLEAR_SCREEN();
        
        printf("%s==============================================\n", GREEN);
        printf("   TERMINAL INFO - INFORMATIONS GENERALES\n");
        printf("==============================================\n%s\n", RESET);
        
        file = fopen("data_info.txt", "r");
        
        if (file != NULL) {
            while (fgets(buffer, BUFFER_SIZE, file) != NULL) {

                if (strstr(buffer, "Cycle") || strstr(buffer, "CYCLE")) {
                    printf("%s%s%s", BRIGHT_CYAN, buffer, RESET);

                } else if (strstr(buffer, "Avion") || strstr(buffer, "AVION")) {
                    printf("%s%s%s", YELLOW, buffer, RESET);

                } else if (strstr(buffer, "Piste") || strstr(buffer, "PISTE")) {
                    printf("%s%s%s", BLUE, buffer, RESET);

                } else if (strstr(buffer, "En attente") || strstr(buffer, "Attente")) {
                    printf("%s%s%s", MAGENTA, buffer, RESET);

                } else if (strstr(buffer, "Essence") || strstr(buffer, "Carburant")) {
                    printf("%s%s%s", BRIGHT_GREEN, buffer, RESET);

                } else if (strstr(buffer, "====")) {
                    printf("%s%s%s", GREEN, buffer, RESET);

                } else {
                    printf("%s", buffer);
                }
            }
            fclose(file);

        } else {
            printf("%sEn attente des donnees\n%s", YELLOW, RESET);
        }
        
        SLEEP_MS(2000);
    }
    
    return 0;
}
