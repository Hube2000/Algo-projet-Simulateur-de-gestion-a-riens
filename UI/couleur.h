#ifndef COULEUR_H
#define COULEUR_H
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





//easter egg shiny
bool isShiny(void) {
    static bool initialized = false;
    if (!initialized) {
        srand(time(NULL));
        initialized = true;
    }
    return (rand() % 100) < 5; // 5% de chance de proc sur les anims
}


#endif // COULEUR_H