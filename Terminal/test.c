#include <stdio.h>
#include <stdlib.h>

int main(void) {
        //init
        system("cls");
        system("gcc mainTERMINAL1.c -o mainTERMINAL1.exe");
        system("gcc mainTERMINAL2.c -o mainTERMINAL2.exe");

        printf("Lancement du terminal 1...\n");
        system("start cmd /k \"title TERMINAL1 && color a && mainTERMINAL1.exe \"");
    
        printf("Lancement du terminal 2...\n");
        system("start cmd /k \"title TERMINAL2 && color b && mainTERMINAL2.exe \"");

        printf("Appuyez sur une touche pour quitter...\n");
        getchar();
    return 0;
}
