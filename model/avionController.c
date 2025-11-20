#include "avion.h"

avion * rechercherAvion(AvionFile *file, int id){ 
    if(!file) return NULL;
    avion *current = file->premier;
    while(current != NULL){
        if(current->id == id){
            return current;
        }
        current = current->next;
    }
    return NULL;
}

avion* retirerAvion(AvionFile *file,int id){
    if(!file) return NULL;
    avion *aSupprimer = rechercherAvion(file, id);
    if(!aSupprimer) return NULL;

    // Debut de la liste
    if(aSupprimer == file->premier){
        file->premier = NULL;
        file->dernier = NULL;
        free(aSupprimer);
    }
    
    // Au millieu de la liste
    aSupprimer->prev->next = aSupprimer->next;
    aSupprimer->next->prev = aSupprimer->prev;

    // Fin de la liste
    if(aSupprimer == file->dernier){
        file->dernier = aSupprimer->prev;
        free(aSupprimer);
    }

    file->nbElement--;
    return aSupprimer;

}