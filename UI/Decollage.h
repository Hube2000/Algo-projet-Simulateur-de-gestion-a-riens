#ifndef DECOLLAGE_H
#define DECOLLAGE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
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

void Decollage_UI(){
    bool shiny = isShiny();
    
    if (shiny) {
        // TODO: Animation shiny à définir
        
    }
    
    system("cls");
    printf("%s", BRIGHT_YELLOW);
    printf("            _______\n");
    printf("            \\=====/\n");
    printf("              |||\n");
    printf("               #                                                   (#######)\n");
    printf("               |                                                    \\\\\\|///\n");
    printf("  ===========================                                        \\\\|//\n");
    printf("  |  Marburg International  |                                         \\|/\n");
    printf("  ===========================                                          Y\n");
    printf("  \\        |       |        /                                          O\n");
    printf("   \\       |       |       /                                          -|-\n");
    printf("    \\      |       |      /                                           / \\\n");
    printf("     \\     |       |     /\n");
    printf("      ###################\n");
    printf("      ||               ||\n");
    printf("      ||               ||\n");
    printf("      ||               ||\n");
    printf("      ||               ||\n");
    printf("      ||               ||\n");
    printf("      %s||               ||%s       %s___\n",BRIGHT_YELLOW, RESET, CYAN);
    printf("      %s||               ||        %s%s| \\_______________\n",BRIGHT_YELLOW, RESET, CYAN);
    printf("      %s||  ####         ||      %s%s ====( oooooooooo  O\\___\n",BRIGHT_YELLOW, RESET, CYAN);
    printf("      %s||  #  #         ||        %s%s(________/=====>______)--\n",BRIGHT_YELLOW, RESET, CYAN);
    printf("      %s||  #  #         ||                 %s%sOO        O\n", BRIGHT_YELLOW, RESET, CYAN);
    printf("%s%s  ============================================================================\n", RESET, GREEN);
    printf("%s", RESET);
    printf("\n%sDecollage en cours...%s\n", BRIGHT_YELLOW, RESET);

    PlaySound(TEXT("SystemStart"), NULL, SND_ALIAS | SND_SYNC);
    Sleep(1000);
    system("cls");

    system("cls");
    printf("%s\n", GREEN);
    printf("                                    ___\n");
    printf("   PA28-161 Warrior                /L|0\\\n");
    printf("   by Paul Tomblin                /  |  \\\n");
    printf("   ptomblin@xcski.com            /       \\\n");
    printf("                                /    |    \\\n");
    printf("                               /           \\\n");
    printf("                              /  __  | __   \\\n");
    printf("                             /  __/    \\__   \\\n");
    printf("                            /  /__   |  __\\   \\\n");
    printf("                           /___________________\\\n%s", RESET);
    printf("\n");
    printf("                         %s /          |         \\\n", CYAN);
    printf("                                %s/   _|_   \\\n", CYAN);
    printf("                        %s/      ____/___\\____     \\\n", CYAN);
    printf("                        %s___________[o0o]___________\n", CYAN);
    printf("                       %s          O   O   O\n", CYAN);
    printf("\n");
        
    PlaySound(TEXT("SystemStart"), NULL, SND_ALIAS | SND_SYNC);
    Sleep(1500);
    system("cls");

    printf("%s", CYAN);
    printf("   Big airplane                               .------,\n");
    printf("   Joan Stark                                  =\\      \\\n");
    printf("   spunk1111@juno.com             .---.         =\\      \\\n");
    printf("                                  | C~ \\         =\\      \\\n");
    printf("                                  |     `----------'------'----------,\n");
    printf("                                 .'     LI.-.LI LI LI LI LI LI LI.-.LI`-.\n");
    printf("                                 \\ _/.____|_|______.------,______|_|_____)\n");
    printf("                                                  /      /\n");
    printf("                                                =/      /\n");
    printf("                                               =/      /\n");
    printf("                                              =/      /\n");
    printf("                                              /_____,'\n");
    printf("%s", RESET);
    printf("\n%sEn vol...%s\n", CYAN, RESET);
    Sleep(3000);

    printf("%s", RESET);

    printf("%sDecollage termine\n", RED);
    printf("%s", RESET);
}

#endif // DECOLLAGE_H