#ifndef ATTERISSAGE_H
#define ATTERISSAGE_H
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <mmsystem.h>
#include "couleur.h"

void atterissage_UI(){     
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

     if (!isShiny()) {
        system("cls");
        printf("%s\n", BRIGHT_YELLOW);
        printf("*** ATTERRISSAGE CASI PARFAIT ***\n\n");
        printf(".-------------------.              ___\n");
        printf("( Have we landed yet? )            /  /]\n");
        printf(" `-------------.   ,-'            /  / ]\n");
        printf("                \\ |      _____,. '  /__]\n");
        printf("             )   \\|   ,-'             _>\n");
        printf("               (  ` _/  G-BUMR   ,. '`\n");
        printf("              )    / |     _,. '`\n");
        printf("              (   /. /    |\n");
        printf("               ) ,  /`  ./\n");
        printf("              (  \\_/   //_ _\n");
        printf("               ) /    //  (_)\n");
        printf("             _,~'#   (/.\n");
        printf("~~~~~~~~~~~~~~~#~~#~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("%s\n", RESET);
        Sleep(3000);
        system("cls");
        printf("C'est une blague: on a atterri sans encombre !\n");
        Sleep(2500);
    }
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
    Sleep(3000);
}


#endif
