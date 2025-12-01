#ifndef UI_CRASH_H
#define UI_CRASH_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<windows.h>
#include<mmsystem.h>
#include <time.h>

void crash_UI(){
    // Joue plusieurs sons d'erreur en série
    PlaySound(TEXT("SystemHand"), NULL, SND_ALIAS | SND_SYNC);
    Sleep(200);
    PlaySound(TEXT("SystemExclamation"), NULL, SND_ALIAS | SND_SYNC);
    Sleep(200);
    PlaySound(TEXT("SystemHand"), NULL, SND_ALIAS | SND_SYNC);
    Sleep(200);
    PlaySound(TEXT("SystemAsterisk"), NULL, SND_ALIAS | SND_SYNC);
    Sleep(200);
    PlaySound(TEXT("SystemHand"), NULL, SND_ALIAS | SND_SYNC);
}
#endif // UI_CRASH_H