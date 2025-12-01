#include "Attack_Terroriste.h"
#include "Hack.h"
#include <stdio.h>
#include "crash.h"

int main(void) {
    int choix;
    
    printf("Menu\n");
    printf("1. Attack Terroriste\n");
    printf("2. Hack\n");
    printf("3. Crash\n");
    printf("Votre choix: ");
    scanf("%d", &choix);
    
    if (choix == 1) {
        Attack_Terroriste_UI();
    } else if (choix == 2) {
        hack();
    }else if (choix == 3) {
        crash_UI();
    }else {
        printf("Choix invalide!\n");
    }

    return 0;
}
