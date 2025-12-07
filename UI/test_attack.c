
#include <stdio.h>
#include <stdlib.h>

#include "Crash.h"
#include "Attack_Terroriste.h"
#include "Hack.h"
#include "Decollage.h"
#include "atterissage.h"

#ifdef _WIN32
#include <windows.h>
#define SLEEP_MS(x) SLEEP_MS(x)
#define CLEAR_SCREEN() CLEAR_SCREEN()
#else
#include <unistd.h>
#define SLEEP_MS(x) uSLEEP_MS((x) * 1000)
#define CLEAR_SCREEN() system("clear")
#endif


int main(void) {
    CLEAR_SCREEN();
    system("gcc couleur.h crash.h Attack_Terroriste.h Hack.h Decollage.h atterissage.h test_attack.c -o simulator.exe -lwinmm");
    int choix;
    while (1)
    {    
    printf("Menu\n");
    printf("1. Attack Terroriste\n");
    printf("2. Hack\n");
    printf("3. Crash\n");
    printf("4. Decollage\n");
    printf("5. Atterissage\n");
    printf("0. Quitter\n");
    printf("Votre choix: ");
    scanf("%d", &choix);
    
    CLEAR_SCREEN();
    
    if (choix == 1) {
        Attack_Terroriste_UI();
    } else if (choix == 2) {
        hack();
    }else if (choix == 3) {
        crash_UI();
    }else if (choix == 4) {
        Decollage_UI();
    }else if (choix == 5) {
        atterissage_UI();
    }
    else {
        printf("Choix invalide!\n");
    }
    }
    return 0;
}