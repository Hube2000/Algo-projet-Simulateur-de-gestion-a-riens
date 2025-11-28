







#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

void ouvrir_terminal(const char* titre, int x, int y, int largeur, int hauteur, const char* programme) {
    char cmd[1024]; //Déclare un buffer cmd de 1024 caractères qui contiendra la commande complète à passer à system().
    
    sprintf(cmd, "start powershell -NoExit -Command " "\"$host.UI.RawUI.WindowTitle='%s'; "
        "$host.UI.RawUI.WindowPosition = New-Object System.Management.Automation.Host.Coordinates %d, %d; "
        "$host.UI.RawUI.WindowSize = New-Object System.Management.Automation.Host.Size %d, %d; "
        "cd '%s'; "
        "%s\"",
        titre, x, y, largeur, hauteur,
        "c:\\Users\\hugob\\OneDrive\\Bureau\\help\\Algo-projet-Simulateur-de-gestion-a-riens",
        programme
    );// c une liste de commande shell qui sont effectuees dans un terminal powershell. Elle configure le titre, la position, la taille de la fenêtre, change le répertoire de travail et exécute un programme spécifié.
    system(cmd);
}


int main(void){
    printf("Lancement du centre de controle aeroportuaire...\n\n");

    int choix;
    int choix2;

    printf("Ouvrire terminal 1 (actions) ? (1=oui / 0=non) : ");
    scanf("%d", &choix);
    printf("Ouvrire terminal 2 (statistiques) ? (1=oui / 0=non) : ");
    scanf("%d", &choix2);
    

    if (choix == 1) {
        ouvrir_terminal("ACTIONS", 0, 0, 80, 20,);
        sleep(500);
    }
    if (choix2 == 1) {
        ouvrir_terminal("STATISTIQUES", 81, 0, 80, 20,);    
        sleep(500);    
    }
    

    system("cls");
    
    return 0;
}
