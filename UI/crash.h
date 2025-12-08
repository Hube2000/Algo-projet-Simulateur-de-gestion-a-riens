#ifndef UI_CRASH_H
#define UI_CRASH_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
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

void crash_UI(){

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

    
    SLEEP_MS(150);
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

    
    SLEEP_MS(150);
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

    if (isShiny())
    {
    SLEEP_MS(300);
    CLEAR_SCREEN();
        CLEAR_SCREEN();
        printf("%s\n", BRIGHT_YELLOW);
        printf("     .\"         \".\n");
        printf("     /             \\\\\n");
        printf("    |   __          |\n");
        printf("    |  (_o) _ \\__.  |\n");
        printf("     \\     /_\\     /\n");
        printf("     / -T-.___.-T- \\\n");
        printf("     \\_ '-|_|_|-' _/\n");
        printf("  .-' \\'-_______-'/ '-.\n");
        printf(" /   _ '-||---||-' _   \\\n");
        printf("|     \\\\ \\\\   // //     |\n");
        printf(" -____// /|   |\\ \\\\____-\n");
        printf("   '-.--'-'---'-'--.-'\n");
        printf("    /       .       \\\n");
        printf("    |       /\\      |\n");
        printf("    '______'  '_____'\n");
        printf("    .-.  \\     /   .-.\n");
        printf("   (___\\o'     'o___)\n");
        printf("%s\n", RESET);
        SLEEP_MS(500);
        printf("%s\n", BRIGHT_YELLOW);
        
        CLEAR_SCREEN();

        printf(" ____   ___   ___  __  __ \n");
        printf("| __ ) / _ \\ / _ \\|  \\/  |\n");
        printf("|  _ \\| | | | | | | |\\/| |\n");
        printf("| |_) | |_| | |_| | |  | |\n");
        printf("|____/ \\___/ \\___/|_|  |_|\n");
        printf("\n");
        SLEEP_MS(2000);

                //sans 2eme
        printf("     .\"         \".\n");
        printf("     /             \\\\\n");
        printf("    |   __       __ |\n");
        printf("    |  (_o) _ \\(o_)  |\n");
        printf("     \\     /_\\     /\n");
        printf("     / -T-.___.-T- \\\n");
        printf("     \\_ '-|_|_|-' _/\n");
        printf("  .-' \\'-_______-'/ '-.\n");
        printf(" /   _ '-||---||-' _   \\\n");
        printf("|     \\\\ \\\\   // //     |\n");
        printf(" -____// /|   |\\ \\\\____-\n");
        printf("   '-.--'-'---'-'--.-'\n");
        printf("    /       .       \\\n");
        printf("    |       /\\      |\n");
        printf("    '______'  '_____'\n");
        printf("    .-.  \\     /   .-.\n");
        printf("   (___\\o'     'o___)\n");
        printf("%s\n", RESET);
        SLEEP_MS(1500);
        CLEAR_SCREEN();
    }else{
    
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
    
    SLEEP_MS(800);
    CLEAR_SCREEN();

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


     SLEEP_MS(800);
    CLEAR_SCREEN();


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

    SLEEP_MS(800);
    CLEAR_SCREEN();

    printf("          _  _\n");
    printf("         ( `   )_\n");
    printf("        (    )    `)\n");
    printf("      (_   (_ .  _) _)\n");
    printf("                                     _\n");
    printf("                                    (  )\n");
    printf("     _ .                         ( `  ) . )\n");
    printf("   (  _ )_                      (_, _(  ,_)_)\n");
    printf(" (_  _(_ ,)\n");

    SLEEP_MS(500);
    CLEAR_SCREEN();

    printf("                  %s _.-^^---....,,-- %s\n", YELLOW, RESET);
    printf("               %s3_--                --_%s\n", YELLOW, RESET);
    printf("             %s <                      >)%s\n", YELLOW, RESET);
    printf("             %s |                      |%s\n", YELLOW, RESET);
    printf("             %s \\._                  _./%s\n", YELLOW, RESET);
    printf("                %s ```--. . , ; .--'''%s\n", YELLOW, RESET);
    printf("                      %s| |   |%s\n", BRIGHT_YELLOW, RESET);
    printf("                   %s.-=||  | |=-.\n", BRIGHT_YELLOW, RESET);
    printf("                   %s`-=#$%%&%%$#=-'%s\n", BRIGHT_YELLOW, RESET);
    printf("                      %s| ;  :|%s\n", BRIGHT_YELLOW, RESET);
    printf("           %s  _____.,-#%%%%&$@%%#&#~,._____ %s\n", BRIGHT_YELLOW, RESET);
    printf("\n");
    }
}
#endif // UI_CRASH_H
