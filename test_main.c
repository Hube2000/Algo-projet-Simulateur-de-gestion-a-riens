#include <stdio.h>
#include <stdlib.h>
#include "model/avion.h"

int main(void){
    AvionFile *f = creerAvionFile();
    if(!f){
        fprintf(stderr, "Erreur: creerAvionFile()\n");
        return 1;
    }

    // Crée quelques avions et fixe des IDs connus pour les tests
    avion *a1 = creerAvion();
    avion *a2 = creerAvion();
    avion *a3 = creerAvion();
    if(!a1 || !a2 || !a3){
        fprintf(stderr, "Erreur: creerAvion()\n");
        return 1;
    }
    a1->id = 10; a2->id = 20; a3->id = 30;

    // Ajouts
    ajouterFinFile(f, a1);
    ajouterFinFile(f, a2);
    ajouterDebutFile(f, a3);

    printf("Après ajouts : nbElement = %d\n", f->nbElement);

    // Recherche
    avion *found = rechercherAvion(f, 20);
    printf("Recherche id=20 : %s\n", found ? "trouvé" : "pas trouvé");

    // Retirer un avion (retourne l'avion retiré sans free)
    avion *ret = retirerAvion(f, 20);
    printf("Retirer id=20 : %s, nbElement = %d\n", ret ? "retiré" : "non retiré", f->nbElement);
    if(ret) free(ret);

    // Supprimer du début et de la fin (les fonctions internes free les avions)
    f = supprimerDebutFile(f);
    printf("Après supprimerDebutFile : nbElement = %d\n", f->nbElement);

    f = supprimerFinFile(f);
    printf("Après supprimerFinFile : nbElement = %d\n", f->nbElement);

    // Nettoyage final
    while(f->nbElement > 0){
        f = supprimerDebutFile(f);
    }
    free(f);
    printf("Test terminé.\n");
    return 0;
}
