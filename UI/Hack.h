#ifndef UI_HACK_C
#define UI_HACK_C

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<windows.h>
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
    int k = 0;
    //bou je fais peur;
    srand(time(NULL));
    int randNum = 0;
    for (int i = 0; i < 3; i++)
    {    
        if (randNum % 2 == 0){
           system("start cmd /k \"color a && ipconfig && title HACK_IPConfig_Backdoor\"");   
        }if (randNum % 3 == 0){
            system("start cmd /k \"color b && ping 8.8.8.8 && title HACK_Ping_Backdoor\"");
            randNum = rand() % 100;
        }
        if (shiny && k == 0)
        {
          system("start https://www.youtube.com/watch?v=dQw4w9WgXcQ");
          k = 1;
        }
        randNum = rand() % 100;
    }
    printf("%sHack reussi! Systeme controle par l'ennemi.%s\n", RED, RESET);
    SLEEP_MS(1000);

    for (int i = 0; i < 4; i++)
    {  
    system("taskkill /F /FI \"WINDOWTITLE eq HACK_IPConfig_Backdoor\" >nul 2>&1");
    system("taskkill /F /FI \"WINDOWTITLE eq HACK_Ping_Backdoor\" >nul 2>&1");
    SLEEP_MS(200);
    }
    printf("%sFermeture des backdoors...%s\n", YELLOW, RESET);
}

#endif // UI_HACK_C
