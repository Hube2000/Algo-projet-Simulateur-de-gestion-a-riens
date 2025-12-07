#ifndef ATTERISSAGE_H
#define ATTERISSAGE_H
#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#include <windows.h>
#define SLEEP_MS(x) Sleep(x)
#define CLEAR_SCREEN() system("cls")
#else
#include <unistd.h>
#define SLEEP_MS(x) usleep((x) * 1000)
#define CLEAR_SCREEN() system("clear")
#endif

#include "couleur.h"
void atterissage_UI(){     
    CLEAR_SCREEN();
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

    
    SLEEP_MS(200);
    CLEAR_SCREEN();

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

    
    SLEEP_MS(200);
    CLEAR_SCREEN();

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
    SLEEP_MS(200);
    CLEAR_SCREEN();

     if (isShiny()) {
        CLEAR_SCREEN();
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
        SLEEP_MS(1000);
        CLEAR_SCREEN();
        printf("C'est une blague: on a atterri sans encombre !\n");
        SLEEP_MS(800);
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
    SLEEP_MS(1000);
}


#endif
