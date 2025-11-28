#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

void ouvrir_terminal(const char* titre, int x, int y, int largeur, int hauteur, const char* programme) {
    char cmd[1024];
    
    sprintf(cmd, "start powershell -NoExit -Command " "\"$host.UI.RawUI.WindowTitle='%s'; "
        "$host.UI.RawUI.WindowPosition = New-Object System.Management.Automation.Host.Coordinates %d, %d; "
        "$host.UI.RawUI.WindowSize = New-Object System.Management.Automation.Host.Size %d, %d; "
        "cd '%s'; "
        "%s\"",
        titre, x, y, largeur, hauteur,
        "c:\\Users\\hugob\\OneDrive\\Bureau\\help\\Algo-projet-Simulateur-de-gestion-a-riens",
        programme
    );
    
    system(cmd);
}



int main(int argc, char *argv[]) {
    if (argc > 1) {
        // Mode spécifique selon l'argument
        if (strcmp(argv[1], "actions") == 0) {
            // Terminal 1 : Actions et Commandes
            system("cls");
            HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
            DWORD dwMode = 0;
            GetConsoleMode(hOut, &dwMode);
            dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
            SetConsoleMode(hOut, dwMode);
            
            printf("%s__________________________________________\n", GREEN);
            printf("|      ACTIONS ET COMMANDES                   |\n");
            printf("__________________________________________%s\n\n", RESET);
            
            int compteur = 0;
            while(1) {
                printf("\r%s[INFO]%s Cycle %d - En attente de commandes...", GREEN, RESET, ++compteur);
                fflush(stdout);
                Sleep(1000);
            }
        }
        else if (strcmp(argv[1], "stats") == 0) {
            // Terminal 2 : Statistiques
            system("cls");
            HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
            DWORD dwMode = 0;
            GetConsoleMode(hOut, &dwMode);
            dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
            SetConsoleMode(hOut, dwMode);
            
            printf("%s__________________________________________\n", BLUE);
            printf("|           STATISTIQUES EN TEMPS RÉEL        |\n");
            printf("__________________________________________%s\n\n", RESET);
            
            int decollages = 0, atterrissages = 0;
            while(1) {
                system("cls");
                printf("%s__________________________________________\n", BLUE);
                printf("|           STATISTIQUES EN TEMPS RÉEL        |\n");
                printf("__________________________________________%s\n\n", RESET);
                
                printf("%s Décollages totaux:%s %d\n", GREEN, RESET, ++decollages);
                printf("%s Atterrissages totaux:%s %d\n", CYAN, RESET, ++atterrissages);
                printf("%s Avions en vol:%s %d\n", YELLOW, RESET, decollages - atterrissages);
                printf("\n%__________________________________________%s\n", BLUE, RESET);
                
                Sleep(2000);
            }
        }
        else if (strcmp(argv[1], "visual") == 0) {
            // Terminal 3 : Visualisation des pistes
            system("cls");
            HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
            DWORD dwMode = 0;
            GetConsoleMode(hOut, &dwMode);
            dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
            SetConsoleMode(hOut, dwMode);
            
            printf("%s__________________________________________\n", CYAN);
            printf("|        VISUALISATION DES PISTES             |\n");
            printf("__________________________________________%s\n\n", RESET);
            
            int etat1 = 0, etat2 = 0, etat3 = 0;
            while(1) {
                system("cls");
                printf("%s╔══════════════════════════════════════════════╗\n", CYAN);
                printf("║        VISUALISATION DES PISTES             ║\n");
                printf("╚══════════════════════════════════════════════╝%s\n\n", RESET);
                
                etat1 = (etat1 + 10) % 110;
                etat2 = (etat2 + 15) % 110;
                etat3 = (etat3 + 20) % 110;
                
                printf("Piste 1: [");
                for(int i = 0; i < 10; i++) printf(i < etat1/10 ? "█" : "░");
                printf("] %d%%\n", etat1 > 100 ? 100 : etat1);
                
                printf("Piste 2: [");
                for(int i = 0; i < 10; i++) printf(i < etat2/10 ? "█" : "░");
                printf("] %d%%\n", etat2 > 100 ? 100 : etat2);
                
                printf("Piste 3: [");
                for(int i = 0; i < 10; i++) printf(i < etat3/10 ? "█" : "░");
                printf("] %d%%\n\n", etat3 > 100 ? 100 : etat3);
                
                printf("       _\n");
                printf("      -=\\`\\\n");
                printf("  |\\ ____\\_\\__\n");
                printf("-=\\c`\"\"\"\"\"\"\" \"`)\n");
                printf("  `~~~~~/ /~~`\n");
                
                Sleep(1500);
            }
        }
        else if (strcmp(argv[1], "listes") == 0) {
            // Terminal 4 : Listes des avions
            system("cls");
            HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
            DWORD dwMode = 0;
            GetConsoleMode(hOut, &dwMode);
            dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
            SetConsoleMode(hOut, dwMode);
            
            printf("%s__________________________________________\n", YELLOW);
            printf("|          LISTE DES AVIONS EN ATTENTE       |\n");
            printf("__________________________________________%s\n\n", RESET);
            
            int nb_avions = 3;
            while(1) {
                system("cls");
                printf("%s__________________________________________\n", YELLOW);
                printf("|          LISTE DES AVIONS EN ATTENTE       |\n");
                printf("__________________________________________%s\n\n", RESET);
                
                printf("%s1.%s AF123 - Airbus A380   - %s[DÉCOLLAGE]%s\n", YELLOW, RESET, GREEN, RESET);
                printf("%s2.%s BA456 - Boeing 747    - %s[EN ATTENTE]%s\n", YELLOW, RESET, CYAN, RESET);
                printf("%s3.%s LH789 - Airbus A320   - %s[ATTERRISSAGE]%s\n", YELLOW, RESET, MAGENTA, RESET);
                
                if (nb_avions > 3) {
                    printf("%s4.%s EK101 - Boeing 777    - %s[EN ATTENTE]%s\n", YELLOW, RESET, CYAN, RESET);
                }
                
                printf("\n%sTotal: %d avions%s\n", YELLOW, nb_avions, RESET);
                
                nb_avions = 3 + (rand() % 3);
                Sleep(3000);
            }
        }
    }
    else {
        // Mode principal : lance tous les terminaux
        printf("Lancement du centre de controle aeroportuaire...\n\n");
        
        // Terminal 1 : Actions (haut gauche)
        ouvrir_terminal("ACTIONS", 0, 0, 80, 20, ".\\verif\\test.exe actions");
        Sleep(500);
        
        // Terminal 2 : Statistiques (haut droite)
        ouvrir_terminal("STATISTIQUES", 85, 0, 80, 20, ".\\verif\\test.exe stats");
        
        // Terminal 3 : Visualisation (bas gauche)
        ouvrir_terminal("VISUALISATION", 0, 25, 80, 20, ".\\verif\\test.exe visual");
        Sleep(500);
        
        // Terminal 4 : Listes (bas droite)
        ouvrir_terminal("LISTES", 85, 25, 80, 20, ".\\verif\\test.exe listes");
        
        printf("\n%s Centre de controle lance avec succes!%s\n", GREEN, RESET);
        printf(" terminaux actifs:\n");
        printf("  - Actions et Commandes\n");
        printf("  - Statistiques\n");
        printf("  - Visualisation des Pistes\n");
        printf("  - Listes des Avions\n\n");
        printf("Appuyez sur Entree pour quitter...\n");
        getchar();
    }
    
    return 0;
}
