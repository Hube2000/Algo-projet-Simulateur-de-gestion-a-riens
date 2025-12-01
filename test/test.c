#include <stdio.h>
#include <stdlib.h>

int main(void) {
    while(1) {
        system("cls");
        int choix;
        printf("1. Visuel 1\n");
        printf("2. Visuel 2\n");
        printf("0. Quitter\n");
        printf("\n choix : ");
        scanf("%d", &choix);

        if(choix == 0) {
            break;
        }

        switch(choix) {
            case 1:
                system("cls");
                system("gcc test\\test1.c -o test\\test1.exe");
                system("start cmd /k \"cd test && color a && test1.exe \"");
                break;
            case 2:
            system("cls");
                system("gcc test\\test2.c -o test\\test2.exe");
                system("start cmd /k \"cd test && color a && test2.exe \"");
                break;
            default:
                printf("Choix invalide !\n");
        }
    }
    return 0;
}
