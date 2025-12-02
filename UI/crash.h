#ifndef UI_CRASH_H
#define UI_CRASH_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<windows.h>
#include<mmsystem.h>
#include <time.h>

#include "couleur.h"

bool isShiny() {
    static bool initialized = false;
    if (!initialized) {
        srand(time(NULL));
        initialized = true;
    }
    return (rand() % 100) < 5; // 5% de chance
}

void crash_UI(){
    bool shiny = isShiny();
    
    if (shiny) {
        
        
    }
    
        printf("           %s_\n", BRIGHT_WHITE);
    printf("         %s-=\\`\\\n", BRIGHT_WHITE);
    printf("    %s|\\ ____\\_\\__\n", BRIGHT_WHITE);
    printf("   %s-=\\c`\"\"\"\"\"\"\" \"\"`)  \n", BRIGHT_WHITE);
    printf("      %s`~~~~~/ /~~`\n", BRIGHT_WHITE);
    printf("        %s-==/ /\n", BRIGHT_WHITE);
    printf("          %s'-'\n", BRIGHT_WHITE);
    printf("\n");
    printf("          _  _\n");
    printf("         ( `   )_\n");
    printf("        (    )    `)\n");
    printf("      (_   (_ .  _) _)\n");
    printf("                                     _\n");
    printf("                                    (  )\n");
    printf("     _ .                         ( `  ) . )\n");
    printf("   (  _ )_                      (_, _(  ,_)_)\n");
    printf(" (_  _(_ ,)\n");
    printf("\n");
    
    Sleep(800);
    system("cls");

    printf("\n");
    printf("          _  _\n");
    printf("         ( `   )_\n");
    printf("        (    )    `)\n");
    printf("      (_   (_ .  _) _)\n");
        printf("           %s_\n", BRIGHT_WHITE);
    printf("         %s-=\\`\\\n", BRIGHT_WHITE);
    printf("    %s|\\ ____\\_\\__\n", BRIGHT_WHITE);
    printf("   %s-=\\c`\"\"\"\"\"\"\" \"\"`)  \n", BRIGHT_WHITE);
    printf("      %s`~~~~~/ /~~`\n", BRIGHT_WHITE);
    printf("        %s-==/ /\n", BRIGHT_WHITE);
    printf("          %s'-'\n", BRIGHT_WHITE);
    printf("                                     _\n");
    printf("                                    (  )\n");
    printf("     _ .                         ( `  ) . )\n");
    printf("   (  _ )_                      (_, _(  ,_)_)\n");
    printf(" (_  _(_ ,)\n");
    printf("\n");


     Sleep(800);
    system("cls");


        printf("          _  _\n");
    printf("         ( `   )_\n");
    printf("        (    )    `)\n");
    printf("      (_   (_ .  _) _)\n");
    printf("                                     _\n");
    printf("                                    (  )\n");
    printf("     _ .                         ( `  ) . )\n");
    printf("   (  _ )_                      (_, _(  ,_)_)\n");
    printf(" (_  _(_ ,)\n");
        printf("           %s_\n", BRIGHT_WHITE);
    printf("         %s-=\\`\\\n", BRIGHT_WHITE);
    printf("    %s|\\ ____\\_\\__\n", BRIGHT_WHITE);
    printf("   %s-=\\c`\"\"\"\"\"\"\" \"\"`)  \n", BRIGHT_WHITE);
    printf("      %s`~~~~~/ /~~`\n", BRIGHT_WHITE);
    printf("        %s-==/ /\n", BRIGHT_WHITE);
    printf("          %s'-'\n", BRIGHT_WHITE);
    
    printf("\n");

    Sleep(800);
    system("cls");

    printf("          _  _\n");
    printf("         ( `   )_\n");
    printf("        (    )    `)\n");
    printf("      (_   (_ .  _) _)\n");
    printf("                                     _\n");
    printf("                                    (  )\n");
    printf("     _ .                         ( `  ) . )\n");
    printf("   (  _ )_                      (_, _(  ,_)_)\n");
    printf(" (_  _(_ ,)\n");

    Sleep(500);
    system("cls");

    printf("                  %s _.-^^---....,,-- %s\n", YELLOW, RESET);
    printf("               %s3_--                --_%s\n", YELLOW, RESET);
    printf("             %s <                      >)%s\n", YELLOW, RESET);
    printf("             %s |                      |%s\n", YELLOW, RESET);
    printf("             %s \\._                  _./%s\n", YELLOW, RESET);
    printf("                %s ```--. . , ; .--'''%s\n", YELLOW, RESET);
    printf("                      %s| |   |%s\n", BRIGHT_YELLOW, RESET);
    printf("                   %s.-=||  | |=-.\n", BRIGHT_YELLOW, RESET);
    printf("                   %s`-=#$%&%$#=-'%s\n", BRIGHT_YELLOW, RESET);
    printf("                      %s| ;  :|%s\n", BRIGHT_YELLOW, RESET);
    printf("           %s  _____.,-#%%&$@%#&#~,._____ %s\n", BRIGHT_YELLOW, RESET);
    printf("\n");
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