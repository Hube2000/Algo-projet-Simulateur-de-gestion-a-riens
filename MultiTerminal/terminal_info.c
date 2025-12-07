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

#define BUFFER_SIZE 4096

int main(void) {
    FILE *file;
    char buffer[BUFFER_SIZE];
    
    printf("==============================================\n");
    printf("   TERMINAL INFO - INFORMATIONS GENERALES\n");
    printf("==============================================\n\n");
    
    while (1) {
        CLEAR_SCREEN();
        
        printf("==============================================\n");
        printf("   TERMINAL INFO - INFORMATIONS GENERALES\n");
        printf("==============================================\n\n");
        
        file = fopen("data_info.txt", "r");
        
        if (file != NULL) {
            // Lire tout le contenu du fichier
            while (fgets(buffer, BUFFER_SIZE, file) != NULL) {
                printf("%s", buffer);
            }
            fclose(file);
        } else {
            printf("En attente des donnees...\n");
        }
        
        SLEEP(2);
    }
    
    return 0;
}
