#ifndef UI_ATTACK_TERRORISTE_H
#define UI_ATTACK_TERRORISTE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include <time.h>

// Codes de couleur ANSI
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define BRIGHT_RED     "\033[91m"
#define BRIGHT_YELLOW  "\033[93m"
#define BRIGHT_WHITE   "\033[97m"

void Attack_Terroriste_UI(){
    system("cls");
    
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

    Sleep(1000);
    system("cls");

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

    Sleep(1000);
    system("cls");

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


    Sleep(1000);
    system("cls");


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
}
#endif // UI_ATTACK_TERRORISTE_H