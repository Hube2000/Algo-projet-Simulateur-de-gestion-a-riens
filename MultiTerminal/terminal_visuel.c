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

#define BUFFER_SIZE 2048
#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define CYAN    "\033[36m"
#define RED     "\033[31m"
#define BRIGHT_YELLOW  "\033[93m"

int main(void) {
    FILE *file;
    char buffer[BUFFER_SIZE];
    long last_position = 0;
    
    // Activer les couleurs ANSI sur Windows
    #ifdef _WIN32
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, dwMode);
    #endif
    
    printf("==============================================\n");
    printf("    TERMINAL VISUEL - LOGS DE SIMULATION\n");
    printf("==============================================\n\n");
    
    while (1) {
        file = fopen("data_cycles.txt", "r");
        
        if (file != NULL) {
            // Se positionner à la dernière position lue
            fseek(file, last_position, SEEK_SET);
            
            // Lire les nouvelles lignes
            while (fgets(buffer, BUFFER_SIZE, file) != NULL) {
                // Colorer selon le type de log
                if (strstr(buffer, "CYCLE :")) {
                    printf("%s%s%s", CYAN, buffer, RESET);
                } else if (strstr(buffer, "ARRIVEE")) {
                    printf("%s%s%s", GREEN, buffer, RESET);
                } else if (strstr(buffer, "DEPART")) {
                    printf("%s%s%s", BRIGHT_YELLOW, buffer, RESET);
                } else if (strstr(buffer, "EVENEMENT")) {
                    printf("%s%s%s", RED, buffer, RESET);
                } else if (strstr(buffer, "====")) {
                    printf("%s%s%s", CYAN, buffer, RESET);
                } else {
                    printf("%s", buffer);
                }
            }
            
            // Sauvegarder la position actuelle
            last_position = ftell(file);
            fclose(file);
        }
        
        SLEEP(1);
    }
    
    return 0;
}
