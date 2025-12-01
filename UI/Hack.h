#ifndef UI_HACK_C
#define UI_HACK_C

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<windows.h>
#include <time.h>
  
// pr lancer le programme il faut faire: 
//system("start cmd /k \"gcc UI/Hack.c -o UI/Hack.exe && .\\Hack.exe\"");
void hack(){
    system("cls");
    system("title Hack en cours...");
    //bou je fais peur
    Sleep(2000);
    srand(time(NULL));
    int randNum = 0;
    for (int i = 0; i < 10; i++)
    {
      if (randNum % 2 == 0){
    system("start cmd /k \"color a && ipconfig && title IPConfig\"");
      }else{
    system("start cmd /k \"color c && curl parrot.live && title Parrot\"");
    }
        randNum = rand() % 100;
    }
    Sleep(700);
    system("taskkill /F /FI \"WINDOWTITLE eq IPConfig\"");
    system("taskkill /F /FI \"WINDOWTITLE eq Parrot\"");
    exit(0);
}

#endif // UI_HACK_C