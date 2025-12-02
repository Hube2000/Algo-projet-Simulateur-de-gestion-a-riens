#ifndef UI_HACK_C
#define UI_HACK_C

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<windows.h>
#include <time.h>
#include "couleur.h"

void hack(){
    system("cls");
   PlaySound(TEXT("SystemHand"), NULL, SND_ALIAS | SND_SYNC);
    system("title Hack en cours...");

    bool loop = true;
    //bou je fais peur;
    srand(time(NULL));
    int randNum = 0;
    for (int i = 0; i < 3; i++)
    {
      if (loop = true)
      {      
        if (randNum % 2 == 0){
           system("start cmd /k \"color a && ipconfig && title IPConfig\"");   
        }if (randNum % 3 == 0){
            system("start cmd /k \"color b && ping 8.8.8.8 && title Ping\"");
            randNum = rand() % 100;
        }
        if (randNum % 5 == 0)//10% de chance d'ouvrir la fenetre Rickroll
        {
          loop = false;
          system("start cmd /k \"color b && curl ascii.live/rick\"");
        }
        randNum = rand() % 100;
    }
  }
    printf("%sHack reussi! Systeme controle par l'ennemi.%s\n", RED, RESET);
    Sleep(5500);

    for (int i = 0; i < 4; i++)
    {  
    system("taskkill /F /FI \"WINDOWTITLE eq Rick\" >nul 2>&1");
    system("taskkill /F /FI \"WINDOWTITLE eq Ping\" >nul 2>&1");
    system("taskkill /F /FI \"WINDOWTITLE eq IPConfig\" >nul 2>&1");
    Sleep(300);
    }
    printf("%sFermeture des backdoors...%s\n", YELLOW, RESET);
    Sleep(200);
}

#endif // UI_HACK_C