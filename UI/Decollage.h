#ifndef DECOLLAGE_H
#define DECOLLAGE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
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

void Decollage_UI(){    
    CLEAR_SCREEN();
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

    SLEEP_MS(400);
    CLEAR_SCREEN();

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
    
    SLEEP_MS(400);
    CLEAR_SCREEN();

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
    SLEEP_MS(600);

    printf("%s", RESET);

    printf("%sDecollage termine\n", RED);
    printf("%s", RESET);
}

#endif // DECOLLAGE_H
