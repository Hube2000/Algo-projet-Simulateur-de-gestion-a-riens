#ifndef UI_HACK_C
#define UI_HACK_C

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include <time.h>
#include "couleur.h"

#ifdef _WIN32
#include <windows.h>
#define SLEEP_MS(x) Sleep(x)
#define CLEAR_SCREEN() system("cls")
#else
#include <unistd.h>
#define SLEEP_MS(x) usleep((x) * 1000)
#define CLEAR_SCREEN() system("clear")
#endif

void hack(){
    CLEAR_SCREEN();
    system("title Hack en cours...");

    bool shiny  = isShiny();

        if (shiny)
        {
          system("start https://www.youtube.com/watch?v=dQw4w9WgXcQ");
        }else{
    system("start cmd /c title HACK_IPConfig_Backdoor & ipconfig /all & pause");
        }
    printf("%sHack reussi! Systeme controle par l'ennemi.%s\n", RED, RESET);
    SLEEP_MS(1000);
}

#endif // UI_HACK_C
