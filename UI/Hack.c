#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<windows.h>
#include <time.h>
  
// pr lancer le programme il faut faire: 
//system("start cmd /k \"gcc UI/Hack.c -o UI/Hack.exe && .\\Hack.exe\"");
int main(void){
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
    Sleep(7000);
    system("taskkill /F /FI \"WINDOWTITLE eq IPConfig\"");
    system("taskkill /F /FI \"WINDOWTITLE eq Parrot\"");
    exit(0);
    return 0;
}