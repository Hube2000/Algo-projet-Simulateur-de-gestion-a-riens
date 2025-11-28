#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"

// ============ STRUCTURES PARTAGÉES ============
typedef struct {
    int decollages;
    int atterrissages;
    int avions_en_vol;
    int avions_parking;
} Statistiques;

typedef struct {
    int piste1_occupation;
    int piste2_occupation;
    int piste3_occupation;
} EtatPistes;

typedef struct {
    char id[10];
    char type[20];
    char statut[20];
} Avion;

typedef struct {
    Avion avions[10];
    int nb_avions;
} ListeAvions;

// ============ ÉTAT GLOBAL PARTAGÉ ============
typedef struct {
    Statistiques stats;
    EtatPistes pistes;
    ListeAvions liste;
    char message_action[100];
    int tick_counter;
    HANDLE hMapFile;
} EtatGlobal;

// ============ MÉMOIRE PARTAGÉE ============
#define SHARED_MEM_NAME "AeroportControlMemory"
#define SHARED_MEM_SIZE sizeof(EtatGlobal)

EtatGlobal* creer_memoire_partagee() {
    HANDLE hMapFile = CreateFileMapping(
        INVALID_HANDLE_VALUE,
        NULL,
        PAGE_READWRITE,
        0,
        SHARED_MEM_SIZE,
        SHARED_MEM_NAME
    );
    
    if (hMapFile == NULL) {
        printf("Erreur creation memoire partagee\n");
        return NULL;
    }
    
    EtatGlobal* etat = (EtatGlobal*)MapViewOfFile(
        hMapFile,
        FILE_MAP_ALL_ACCESS,
        0,
        0,
        SHARED_MEM_SIZE
    );
    
    if (etat == NULL) {
        CloseHandle(hMapFile);
        return NULL;
    }
    
    etat->hMapFile = hMapFile;
    return etat;
}

EtatGlobal* ouvrir_memoire_partagee() {
    HANDLE hMapFile = OpenFileMapping(
        FILE_MAP_ALL_ACCESS,
        FALSE,
        SHARED_MEM_NAME
    );
    
    if (hMapFile == NULL) {
        return NULL;
    }
    
    EtatGlobal* etat = (EtatGlobal*)MapViewOfFile(
        hMapFile,
        FILE_MAP_ALL_ACCESS,
        0,
        0,
        SHARED_MEM_SIZE
    );
    
    if (etat == NULL) {
        CloseHandle(hMapFile);
        return NULL;
    }
    
    etat->hMapFile = hMapFile;
    return etat;
}

void fermer_memoire_partagee(EtatGlobal* etat) {
    if (etat) {
        UnmapViewOfFile(etat);
        if (etat->hMapFile) {
            CloseHandle(etat->hMapFile);
        }
    }
}

// ============ INITIALISATION ============
void initialiser_etat(EtatGlobal *etat) {
    etat->stats.decollages = 0;
    etat->stats.atterrissages = 0;
    etat->stats.avions_en_vol = 0;
    etat->stats.avions_parking = 3;
    
    etat->pistes.piste1_occupation = 20;
    etat->pistes.piste2_occupation = 50;
    etat->pistes.piste3_occupation = 80;
    
    strcpy(etat->liste.avions[0].id, "AF123");
    strcpy(etat->liste.avions[0].type, "A380");
    strcpy(etat->liste.avions[0].statut, "PARKING");
    
    strcpy(etat->liste.avions[1].id, "BA456");
    strcpy(etat->liste.avions[1].type, "B747");
    strcpy(etat->liste.avions[1].statut, "EN ATTENTE");
    
    strcpy(etat->liste.avions[2].id, "LH789");
    strcpy(etat->liste.avions[2].type, "A320");
    strcpy(etat->liste.avions[2].statut, "DECOLLAGE");
    
    etat->liste.nb_avions = 3;
    strcpy(etat->message_action, "Systeme initialise");
    etat->tick_counter = 0;
}

// ============ FONCTIONS D'AFFICHAGE PAR PAGE ============

void afficher_page_actions(EtatGlobal *etat) {
    system("cls");
    
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, dwMode);
    
    printf("%s╔════════════════════════════════════════════════╗\n", GREEN);
    printf("║         %sPAGE 1 - ACTIONS%s                    ║\n", BOLD, RESET);
    printf("%s╚════════════════════════════════════════════════╝%s\n\n", GREEN, RESET);
    
    // ========== EXEMPLE D'AFFICHAGE ==========
    printf("%sTick: %d%s\n\n", CYAN, etat->tick_counter, RESET);
    
    printf("Exemple 1 - Texte simple:\n");
    printf("  Bonjour depuis la page Actions\n\n");
    
    printf("Exemple 2 - Texte avec couleur:\n");
    printf("  %sTexte en vert%s\n", GREEN, RESET);
    printf("  %sTexte en rouge%s\n", RED, RESET);
    printf("  %sTexte en jaune%s\n\n", YELLOW, RESET);
    
    printf("Exemple 3 - Afficher des variables:\n");
    printf("  Decollages = %d\n", etat->stats.decollages);
    printf("  Message = %s\n\n", etat->message_action);
    
    printf("%s========== AJOUTEZ VOS PRINTF ICI ==========%s\n", MAGENTA, RESET);
    printf("// printf(\"Mon texte\");\n");
    printf("// printf(\"%sTexte couleur%s\", GREEN, RESET);\n", GREEN, RESET);
    // ==============================================
}

void afficher_page_stats(EtatGlobal *etat) {
    system("cls");
    
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, dwMode);
    
    printf("%s╔════════════════════════════════════════════════╗\n", BLUE);
    printf("║         %sPAGE 2 - STATS%s                       ║\n", BOLD, RESET);
    printf("%s╚════════════════════════════════════════════════╝%s\n\n", BLUE, RESET);
    
    // ========== EXEMPLE D'AFFICHAGE ==========
    printf("%sTick: %d%s\n\n", CYAN, etat->tick_counter, RESET);
    
    printf("Exemple 1 - Liste simple:\n");
    printf("  - Element 1\n");
    printf("  - Element 2\n");
    printf("  - Element 3\n\n");
    
    printf("Exemple 2 - Avec boucle for:\n");
    for(int i = 0; i < 5; i++) {
        printf("  Ligne %d\n", i+1);
    }
    printf("\n");
    
    printf("Exemple 3 - Barre de progression:\n");
    printf("  [");
    for(int i = 0; i < 10; i++) {
        if(i < etat->tick_counter % 10) printf("%s█%s", GREEN, RESET);
        else printf("░");
    }
    printf("]\n\n");
    
    printf("%s========== AJOUTEZ VOS PRINTF ICI ==========%s\n", MAGENTA, RESET);
    // ==============================================
}

void afficher_page_visuelles(EtatGlobal *etat) {
    system("cls");
    
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, dwMode);
    
    printf("%s╔════════════════════════════════════════════════╗\n", MAGENTA);
    printf("║         %sPAGE 3 - VISUELLES%s                   ║\n", BOLD, RESET);
    printf("%s╚════════════════════════════════════════════════╝%s\n\n", MAGENTA, RESET);
    
    // ========== EXEMPLE D'AFFICHAGE ==========
    printf("%sTick: %d%s\n\n", CYAN, etat->tick_counter, RESET);
    
    printf("Exemple 1 - ASCII art simple:\n");
    printf("    /\\\n");
    printf("   /  \\\n");
    printf("  /    \\\n");
    printf(" /______\\\n\n");
    
    printf("Exemple 2 - Tableau:\n");
    printf("  +------+------+\n");
    printf("  | A    | B    |\n");
    printf("  +------+------+\n");
    printf("  | %d    | %d    |\n", etat->stats.decollages, etat->stats.atterrissages);
    printf("  +------+------+\n\n");
    
    printf("Exemple 3 - Animation (change avec tick):\n");
    if(etat->tick_counter % 2 == 0) {
        printf("  %s* CLIGNOTANT *%s\n\n", RED, RESET);
    } else {
        printf("  %s  CLIGNOTANT  %s\n\n", YELLOW, RESET);
    }
    
    printf("%s========== AJOUTEZ VOS PRINTF ICI ==========%s\n", MAGENTA, RESET);
    // ==============================================
}

void afficher_page_listes(EtatGlobal *etat) {
    system("cls");
    
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, dwMode);
    
    printf("%s╔════════════════════════════════════════════════╗\n", YELLOW);
    printf("║         %sPAGE 4 - LISTES%s                      ║\n", BOLD, RESET);
    printf("%s╚════════════════════════════════════════════════╝%s\n\n", YELLOW, RESET);
    
    // ========== EXEMPLE D'AFFICHAGE ==========
    printf("%sTick: %d%s\n\n", CYAN, etat->tick_counter, RESET);
    
    printf("Exemple 1 - Parcourir un tableau:\n");
    for(int i = 0; i < etat->liste.nb_avions; i++) {
        printf("  %d. Avion %s\n", i+1, etat->liste.avions[i].id);
    }
    printf("\n");
    
    printf("Exemple 2 - Condition if/else:\n");
    if(etat->stats.avions_parking > 0) {
        printf("  %sIl y a des avions au parking%s\n", GREEN, RESET);
    } else {
        printf("  %sParking vide%s\n", RED, RESET);
    }
    printf("\n");
    
    printf("Exemple 3 - Afficher structures:\n");
    printf("  ID=%s, Type=%s\n", etat->liste.avions[0].id, etat->liste.avions[0].type);
    printf("  Statut=%s\n\n", etat->liste.avions[0].statut);
    
    printf("%s========== AJOUTEZ VOS PRINTF ICI ==========%s\n", MAGENTA, RESET);
    // ==============================================
}

// ============ MODES D'AFFICHAGE ============
void mode_actions() {
    EtatGlobal* etat = ouvrir_memoire_partagee();
    if (!etat) return;
    
    while(1) {
        afficher_page_actions(etat);
        Sleep(500);
    }
}

void mode_stats() {
    EtatGlobal* etat = ouvrir_memoire_partagee();
    if (!etat) return;
    
    while(1) {
        afficher_page_stats(etat);
        Sleep(500);
    }
}

void mode_visuelles() {
    EtatGlobal* etat = ouvrir_memoire_partagee();
    if (!etat) return;
    
    while(1) {
        afficher_page_visuelles(etat);
        Sleep(500);
    }
}

void mode_listes() {
    EtatGlobal* etat = ouvrir_memoire_partagee();
    if (!etat) return;
    
    while(1) {
        afficher_page_listes(etat);
        Sleep(500);
    }
}

// ============ LANCEMENT DES FENÊTRES ============
void ouvrir_terminal(const char* titre, const char* mode, int x, int y) {
    char chemin_executable[MAX_PATH];
    GetModuleFileName(NULL, chemin_executable, MAX_PATH);
    
    char commande[1024];
    sprintf(commande, 
        "powershell -NoExit -Command \"& {"
        "$host.UI.RawUI.WindowTitle='%s'; "
        "$host.UI.RawUI.WindowPosition = New-Object System.Management.Automation.Host.Coordinates %d,%d; "
        "& '%s' %s"
        "}\"",
        titre, x, y, chemin_executable, mode);
    
    STARTUPINFO si = {sizeof(si)};
    PROCESS_INFORMATION pi;
    
    CreateProcess(NULL, commande, NULL, NULL, FALSE, 
                  CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi);
    
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
}

// ============ SYSTÈME DE TICK ============
void tick_update(EtatGlobal *etat) {
    etat->tick_counter++;
    
    // Simulation occupation des pistes
    etat->pistes.piste1_occupation = (etat->pistes.piste1_occupation + 5) % 101;
    etat->pistes.piste2_occupation = (etat->pistes.piste2_occupation + 7) % 101;
    etat->pistes.piste3_occupation = (etat->pistes.piste3_occupation + 3) % 101;
}

// ============ MAIN PRINCIPAL ============
int main(int argc, char *argv[]) {
    // Si appelé avec argument, c'est un terminal enfant
    if (argc > 1) {
        if (strcmp(argv[1], "actions") == 0) {
            mode_actions();
        } else if (strcmp(argv[1], "stats") == 0) {
            mode_stats();
        } else if (strcmp(argv[1], "visuelles") == 0) {
            mode_visuelles();
        } else if (strcmp(argv[1], "listes") == 0) {
            mode_listes();
        }
        return 0;
    }
    
    // Main principal - créer mémoire partagée
    EtatGlobal* etat = creer_memoire_partagee();
    if (!etat) {
        printf("Erreur initialisation memoire partagee\n");
        return 1;
    }
    
    initialiser_etat(etat);
    
    printf("%s╔═══════════════════════════════════════════════════╗\n", CYAN);
    printf("║  %sCENTRE DE CONTROLE AEROPORTUAIRE - MAIN%s       ║\n", BOLD, RESET);
    printf("%s╚═══════════════════════════════════════════════════╝%s\n\n", CYAN, RESET);
    
    printf("Lancement des 4 pages shell...\n\n");
    
    // Lancer les 4 terminaux
    ouvrir_terminal("Actions", "actions", 0, 0);
    Sleep(500);
    ouvrir_terminal("Stats", "stats", 60, 0);
    Sleep(500);
    ouvrir_terminal("Visuelles", "visuelles", 0, 25);
    Sleep(500);
    ouvrir_terminal("Listes", "listes", 60, 25);
    
    printf("%s✓ Toutes les pages sont ouvertes%s\n\n", GREEN, RESET);
    printf("Systeme de tick actif (500ms)\n");
    printf("Appuyez sur Q pour quitter...\n\n");
    
    // Boucle de tick principale
    while(1) {
        tick_update(etat);
        
        printf("\r%sTick: %d%s", CYAN, etat->tick_counter, RESET);
        fflush(stdout);

        
        // Vérifier si Q est pressé
        if (GetAsyncKeyState('Q') & 0x8000) {
            break;
        }
        
        Sleep(500);
    }
    
    printf("\n\n%sFermeture du systeme...%s\n", GREEN, RESET);
    fermer_memoire_partagee(etat);
    
    return 0;
}
