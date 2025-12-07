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

int main(void) {
    FILE *file;
    char buffer[BUFFER_SIZE];
    long last_position = 0;
    
    printf("==============================================\n");
    printf("    TERMINAL VISUEL - CYCLES DE SIMULATION\n");
    printf("==============================================\n\n");
    
    while (1) {
        file = fopen("data_cycles.txt", "r");
        
        if (file != NULL) {
            // Se positionner à la dernière position lue
            fseek(file, last_position, SEEK_SET);
            
            // Lire les nouvelles lignes
            while (fgets(buffer, BUFFER_SIZE, file) != NULL) {
                printf("%s", buffer);
            }
            
            // Sauvegarder la position actuelle
            last_position = ftell(file);
            fclose(file);
        }
        
        SLEEP(1);
    }
    
    return 0;
}
