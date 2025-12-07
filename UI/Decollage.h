#ifndef DECOLLAGE_H
#define DECOLLAGE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include<mmsystem.h>
#include <time.h>

#include "couleur.h"

void Decollage_UI(){    
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

    Sleep(800);
    system("cls");

    printf("%s\n", GREEN);
    printf("                                    ___\n");
    printf("                                   /L|0\\\n");
    printf("                                  /  |  \\\n");
    printf("                                 /       \\\n");
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
    
    Sleep(800);
    system("cls");

    printf("%s", CYAN);
    printf("                                              .------,\n");
    printf("                                               =\\      \\\n");
    printf("                                  .---.         =\\      \\\n");
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
    Sleep(1000);

    printf("%s", RESET);

    printf("%sDecollage termine\n", RED);
    printf("%s", RESET);
}

#endif // DECOLLAGE_H