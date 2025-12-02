#ifndef ATTERISSAGE_H
#define ATTERISSAGE_H
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <mmsystem.h>
#include "couleur.h"

void atterissage_UI(){    
    if (isShiny()) {        
    }
    
    for (int i = 0; i < 2; i++)
    {   
    system("cls");
    printf("%s", CYAN);
    printf("   Big airplane                           .------,\n");
    printf("   Joan Stark                              =\\      \\\n");
    printf("   spunk1111@juno.com         .---.         =\\      \\\n");
    printf("                              | C~ \\         =\\      \\\n");
    printf("                              |     `----------'------'----------,\n");
    printf("                             .'     LI.-.LI LI LI LI LI LI LI.-.LI`-.\n");
    printf("                             \\ _/.____|_|______.------,______|_|_____)\n");
    printf("                                              /      /\n");
    printf("                                            =/      /\n");
    printf("                                           =/      /\n");
    printf("                                          =/      /\n");
    printf("                                          /_____,'\n");

    
    Sleep(300);
    system("cls");

    printf("   Big airplane                                          .------,\n");
    printf("   Joan Stark                                  =\\      \\\n");
    printf("   spunk1111@juno.com                        .---.         =\\      \\\n");
    printf("                                             | C~ \\         =\\      \\\n");
    printf("                                             |     `----------'------'----------,\n");
    printf("                                            .'     LI.-.LI LI LI LI LI LI LI.-.LI`-.\n");
    printf("                                             \\ _/.____|_|______.------,______|_|_____)\n");
    printf("                                                             /      /\n");
    printf("                                                           =/      /\n");
    printf("                                                          =/      /\n");
    printf("                                                         =/      /\n");
    printf("                                                         /_____,'\n");

    
    Sleep(300);
    system("cls");

    printf("   Big airplane                                                                   .------,\n");
    printf("   Joan Stark                                                           =\\      \\\n");
    printf("   spunk1111@juno.com                                                 .---.         =\\      \\\n");
    printf("                                                                      | C~ \\         =\\      \\\n");
    printf("                                                                      |     `----------'------'----------,\n");
    printf("                                                                     .'     LI.-.LI LI LI LI LI LI LI.-.LI`-.\n");
    printf("                                                                      \\ _/.____|_|______.------,______|_|_____)\n");
    printf("                                                                                      /      /\n");
    printf("                                                                                    =/      /\n");
    printf("                                                                                   =/      /\n");
    printf("                                                                                  =/      /\n");
    printf("                                                                                  /_____,'\n");
    printf("%s", RESET);
    printf("\n%sEn vol...%s\n", CYAN, RESET);
    Sleep(300);
    system("cls");
    }
    Sleep(100);
    system("cls");

    printf("%s", BRIGHT_YELLOW);
    printf("            _______\n");
    printf("            \\=====/\n");
    printf("              |||\n");
    printf("               #                                                   \n");
    printf("               |                                                    \n");
    printf("  ===========================                                      \n");
    printf("  |  Marburg International  |                                      \n");
    printf("  ===========================                                         \n");
    printf("  \\        |       |        /                                         \n");
    printf("   \\       |       |       /                                          \n");
    printf("    \\      |       |      /                                            \n");
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
}

#endif
