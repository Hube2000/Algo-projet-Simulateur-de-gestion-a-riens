#ifndef UI_ATTACK_TERRORISTE_H
#define UI_ATTACK_TERRORISTE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include <time.h>

// Codes de couleur
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


void Attack_Terroriste_UI(){

    if (isShiny())
    {
        // Version Shiny - Stickman détaillé avec animation
        CLEAR_SCREEN();
        
        printf(" %sLA SCENE QUI SUIS ETANT TROP VIOLENTE ELLE A ETAIT CENSURER POUR VOUS PROTEGER\n %s", RED, RESET);
        SLEEP_MS(1000);

        CLEAR_SCREEN();
        printf("\n\n\n");
        printf("                    %s.oOOOOo.%s\n", CYAN, RESET);
        printf("                   %s(  o  o  )%s\n", BRIGHT_CYAN, RESET);
        printf("                    %s\\  ^  /%s\n", BRIGHT_CYAN, RESET);
        printf("                     %s'---'%s\n", BRIGHT_CYAN, RESET);
        printf("                       %s|%s\n", BRIGHT_CYAN, RESET);
        printf("                    %s__/|\\__%s\n", BRIGHT_CYAN, RESET);
        printf("                  %s_/   |   \\__%s\n", BRIGHT_CYAN, RESET);
        printf("                 %s/     |      \\%s\n", BRIGHT_CYAN, RESET);
        printf("                       %s/|\\%s\n", BRIGHT_CYAN, RESET);
        printf("                      %s/ | \\%s\n", BRIGHT_CYAN, RESET);
        printf("                     %s/  |  \\%s\n", BRIGHT_CYAN, RESET);
        printf("                    %s/   |   \\%s\n", BRIGHT_CYAN, RESET);
        printf("                   %s/    |    \\%s\n", BRIGHT_CYAN, RESET);
        printf("                  %s/_   / \\   _\\%s\n", BRIGHT_CYAN, RESET);
        printf("                    %s\\ /   \\ /%s\n", BRIGHT_CYAN, RESET);
        printf("                    %s |     |%s\n", BRIGHT_CYAN, RESET);
        printf("                   %s/       \\%s\n", BRIGHT_CYAN, RESET);
        printf("                  %s/         \\%s\n", BRIGHT_CYAN, RESET);
        
        SLEEP_MS(300);
        CLEAR_SCREEN();
        
        // Frame 2 - Stickman en BRIGHT_MAGENTA
        printf("\n\n\n");
        printf("                    %s.oOOOOo.%s\n", BRIGHT_MAGENTA, RESET);
        printf("                   %s(  ^  ^  )%s\n", BRIGHT_MAGENTA, RESET);
        printf("                    %s\\  v  /%s\n", BRIGHT_MAGENTA, RESET);
        printf("                     %s'---'%s\n", BRIGHT_MAGENTA, RESET);
        printf("                       %s|%s\n", BRIGHT_MAGENTA, RESET);
        printf("                    %s__/|\\__%s\n", BRIGHT_MAGENTA, RESET);
        printf("                  %s_/   |   \\__%s\n", BRIGHT_MAGENTA, RESET);
        printf("                 %s/     |      \\%s\n", BRIGHT_MAGENTA, RESET);
        printf("                       %s/|\\%s\n", BRIGHT_MAGENTA, RESET);
        printf("                      %s/ | \\%s\n", BRIGHT_MAGENTA, RESET);
        printf("                     %s/  |  \\%s\n", BRIGHT_MAGENTA, RESET);
        printf("                    %s/   |   \\%s\n", BRIGHT_MAGENTA, RESET);
        printf("                   %s/    |    \\%s\n", BRIGHT_MAGENTA, RESET);
        printf("                  %s/_   / \\   _\\%s\n", BRIGHT_MAGENTA, RESET);
        printf("                    %s\\ /   \\ /%s\n", BRIGHT_MAGENTA, RESET);
        printf("                    %s |     |%s\n", BRIGHT_MAGENTA, RESET);
        printf("                   %s/       \\%s\n", BRIGHT_MAGENTA, RESET);
        printf("                  %s/         \\%s\n", BRIGHT_MAGENTA, RESET);
        
        SLEEP_MS(300);
        CLEAR_SCREEN();
        
        // Frame 3 - Stickman en BRIGHT_YELLOW
        printf("\n\n\n");
        printf("                    %s.oOOOOo.%s\n", BRIGHT_YELLOW, RESET);
        printf("                   %s(  O  O  )%s\n", BRIGHT_YELLOW, RESET);
        printf("                    %s\\  o  /%s\n", BRIGHT_YELLOW, RESET);
        printf("                     %s'---'%s\n", BRIGHT_YELLOW, RESET);
        printf("                       %s|%s\n", BRIGHT_YELLOW, RESET);
        printf("                    %s__/|\\__%s\n", BRIGHT_YELLOW, RESET);
        printf("                  %s_/   |   \\__%s\n", BRIGHT_YELLOW, RESET);
        printf("                 %s/     |      \\%s\n", BRIGHT_YELLOW, RESET);
        printf("                       %s/|\\%s\n", BRIGHT_YELLOW, RESET);
        printf("                      %s/ | \\%s\n", BRIGHT_YELLOW, RESET);
        printf("                     %s/  |  \\%s\n", BRIGHT_YELLOW, RESET);
        printf("                    %s/   |   \\%s\n", BRIGHT_YELLOW, RESET);
        printf("                   %s/    |    \\%s\n", BRIGHT_YELLOW, RESET);
        printf("                  %s/_   / \\   _\\%s\n", BRIGHT_YELLOW, RESET);
        printf("                    %s\\ /   \\ /%s\n", BRIGHT_YELLOW, RESET);
        printf("                    %s |     |%s\n", BRIGHT_YELLOW, RESET);
        printf("                   %s/       \\%s\n", BRIGHT_YELLOW, RESET);
        printf("                  %s/         \\%s\n", BRIGHT_YELLOW, RESET);
        
        SLEEP_MS(300);
        CLEAR_SCREEN();
        
        // Frame 4 - Stickman en BRIGHT_GREEN (final)
        printf("\n\n\n");
        printf("                    %s.oOOOOo.%s\n", BRIGHT_GREEN, RESET);
        printf("                   %s(  *  *  )%s\n", BRIGHT_GREEN, RESET);
        printf("                    %s\\  w  /%s\n", BRIGHT_GREEN, RESET);
        printf("                     %s'---'%s\n", BRIGHT_GREEN, RESET);
        printf("                       %s|%s\n", BRIGHT_GREEN, RESET);
        printf("                    %s__/|\\__%s\n", BRIGHT_GREEN, RESET);
        printf("                  %s_/   |   \\__%s\n", BRIGHT_GREEN, RESET);
        printf("                 %s/     |      \\%s\n", BRIGHT_GREEN, RESET);
        printf("                       %s/|\\%s\n", BRIGHT_GREEN, RESET);
        printf("                      %s/ | \\%s\n", BRIGHT_GREEN, RESET);
        printf("                     %s/  |  \\%s\n", BRIGHT_GREEN, RESET);
        printf("                    %s/   |   \\%s\n", BRIGHT_GREEN, RESET);
        printf("                   %s/    |    \\%s\n", BRIGHT_GREEN, RESET);
        printf("                  %s/_   / \\   _\\%s\n", BRIGHT_GREEN, RESET);
        printf("                    %s\\ /   \\ /%s\n", BRIGHT_GREEN, RESET);
        printf("                    %s |     |%s\n", BRIGHT_GREEN, RESET);
        printf("                   %s/       \\%s\n", BRIGHT_GREEN, RESET);
        printf("                  %s/         \\%s\n", BRIGHT_GREEN, RESET);
        SLEEP_MS(2000);
        CLEAR_SCREEN();
        printf("%s ET BOOOM PLUS D'AVION\n", RESET);
        Sleep (2000);
        CLEAR_SCREEN();
    }else{


    CLEAR_SCREEN();
    
    printf("      %s______________________________    . \\  | / .\n", BRIGHT_RED);
    printf("     %s/                            / \\     \\ \\ / /\n", BRIGHT_RED);
    printf("    %s|                            | ==========  - -\n", BRIGHT_RED);
    printf("     %s\\____________________________\\_/     / / \\ \\\n", BRIGHT_RED);
    printf("  %s______________________________      \\  | / | \\\n", BRIGHT_RED);
    printf(" %s/                            / \\     \\ \\ / /.   .\n", BRIGHT_RED);
    printf("%s|                            | ==========  - -\n", BRIGHT_RED);
    printf(" %s\\____________________________\\_/     / / \\ \\    /\n", BRIGHT_RED);
    printf("      %s______________________________   / |\\  | /  .\n", BRIGHT_RED);
    printf("     %s/                            / \\     \\ \\ / /\n", BRIGHT_RED);
    printf("    %s|                            | ==========  -  - -\n", BRIGHT_RED);
    printf("     %s\\____________________________\\_/     / / \\ \\\n", BRIGHT_RED);
    printf("                                        .  / | \\  .\n");

    SLEEP_MS(1000);
    CLEAR_SCREEN();

    printf("     %s ______________________________    . \\  | / .\n", RED);
    printf("     %s/                            / \\     \\ \\ / /\n", RED);
    printf("    %s|                            | =====  - -\n", RED);
    printf("     %s\\____________________________\\_/     / / \\ \\\n", RED);
    printf("  %s______________________________      \\  | / | \\\n", RED);
    printf(" %s/                            / \\     \\ \\ / /.   .\n", RED);
    printf("%s|                            | =====  - -\n", RED);
    printf(" %s\\____________________________\\_/     / / \\ \\    /\n", RED);
    printf("      %s______________________________   / |\\  | /  .\n", RED);
    printf("     %s/                            / \\     \\ \\ / /\n", RED);
    printf("    %s|                            | =====  -  - -\n", RED);
    printf("     \\____________________________\\_/     / / \\ \\\n");
    printf("                                        .  / | \\  .\n");

    SLEEP_MS(1000);
    CLEAR_SCREEN();

    printf("     %s______________________________    . \\  | / .\n", RED);
    printf("     %s/                            / \\     \\ \\ / /\n", RED);
    printf("    %s|                            | =  - -\n", RED);
    printf("     %s\\____________________________\\_/     / / \\ \\\n", RED);
    printf("  %s______________________________      \\  | / | \\\n", RED);
    printf(" %s/                            / \\     \\ \\ / /.   .\n", RED);
    printf("%s|                            | =  - -\n", RED);
    printf(" %s\\____________________________\\_/     / / \\ \\    /\n", RED);
    printf("      %s______________________________   / |\\  | /  .\n", RED);
    printf("     %s/                            / \\     \\ \\ / /\n", RED);
    printf("    %s|                            | = -  - -\n", RED);
    printf("     %s\\____________________________\\_/     / / \\ \\\n", RED);
    printf("                                        .  / | \\  .\n");


    SLEEP_MS(1000);
    CLEAR_SCREEN();

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
    }
}

#endif // UI_ATTACK_TERRORISTE_H
