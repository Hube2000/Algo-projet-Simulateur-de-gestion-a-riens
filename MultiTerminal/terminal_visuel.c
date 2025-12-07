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

#define BUFFER_SIZE 2048

int main(void) {
    FILE *file;
    char buffer[BUFFER_SIZE];
    long last_position = 0;
    
    printf("%s==============================================\n", CYAN);
    printf("    TERMINAL VISUEL - LOGS DE SIMULATION\n");
    printf("==============================================\n%s\n", RESET);
    
    while (1) {
        file = fopen("data_cycles.txt", "r");
        
        if (file != NULL) {
            fseek(file, last_position, SEEK_SET);
            
            while (fgets(buffer, BUFFER_SIZE, file) != NULL) {
                if (strstr(buffer, "CYCLE :")) {
                    printf("%s%s%s", BRIGHT_CYAN, buffer, RESET);
                } else if (strstr(buffer, "ARRIVEE")) {
                    printf("%s%s%s", BRIGHT_GREEN, buffer, RESET);
                } else if (strstr(buffer, "DEPART")) {
                    printf("%s%s%s", BRIGHT_YELLOW, buffer, RESET);
                } else if (strstr(buffer, "EVENEMENT") || strstr(buffer, "ALERTE")) {
                    printf("%s%s%s", BRIGHT_RED, buffer, RESET);
                } else if (strstr(buffer, "====")) {
                    printf("%s%s%s", CYAN, buffer, RESET);
                } else if (strstr(buffer, "Piste")) {
                    printf("%s%s%s", MAGENTA, buffer, RESET);
                } else {
                    printf("%s", buffer);
                }
            }
            
            last_position = ftell(file);
            fclose(file);
        }
        
        SLEEP_MS(1000);
    }
    
    return 0;
}
