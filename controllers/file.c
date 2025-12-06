#include "../models/avion.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

AvionFile *creerAvionFile()
{
  AvionFile *file = malloc(sizeof(AvionFile));
  if (!file)
    return NULL;
  file->nbElement = 0;
  file->premier = NULL;
  file->dernier = NULL;
  return file;
}

void ajouterDebutFile(AvionFile *file, avion *a)
{
  if (!file || !a)
  {
    printf("\n Donnée manquantes dans les inputs. ajouterDebutFile (file.c)\n");
    return;
  }
  if (file->nbElement == 0)
  {
    file->premier = a;
    file->dernier = a;
    a->next = NULL;
    a->prev = NULL;
  }
  else
  {
    a->next = file->premier;
    a->prev = NULL;
    file->premier->prev = a;
    file->premier = a;
  }
  file->nbElement++;
  return;
}

void ajouterFinFile(AvionFile *file, avion *a)
{
  if (!file || !a)
  {
    printf("\n Donnée manquantes dans les inputs. ajouterFinFile (file.c)\n");
    return;
  }
  if (file->nbElement == 0)
  {
    file->premier = a;
    file->dernier = a;
    a->next = NULL;
    a->prev = NULL;
  }
  else
  {
    a->prev = file->dernier;
    a->next = NULL;
    file->dernier->next = a;
    file->dernier = a;
  }
  file->nbElement++;
  return;
}

void supprimerDebutFile(AvionFile *file)
{
  if (!file || file->nbElement == 0)
  {
    printf("\n Donnée manquantes dans les inputs ou file vide. "
           "supprimerDebutFile (file.c)\n");
    return;
  }
  avion *toRemove = file->premier;
  if (file->nbElement == 1)
  {
    file->premier = NULL;
    file->dernier = NULL;
  }
  else
  {
    file->premier = toRemove->next;
    if (file->premier)
      file->premier->prev = NULL;
  }
  free(toRemove);
  file->nbElement--;
  return;
}

void supprimerFinFile(AvionFile *file)
{
  if (!file || file->nbElement == 0)
  {
    printf("\n Donnée manquantes dans les inputs ou file vide. "
           "supprimerFinFile (file.c)\n");
    return;
  }
  avion *toRemove = file->dernier;
  if (file->nbElement == 1)
  {
    file->premier = NULL;
    file->dernier = NULL;
  }
  else
  {
    file->dernier = toRemove->prev;
    if (file->dernier)
      file->dernier->next = NULL;
  }
  free(toRemove);
  file->nbElement--;
  return;
}

/* Libère tous les avions d'une file puis la file elle‑même. */
void detruireAvionFile(AvionFile *file)
{
  if (!file)
  {
    printf("\n Erreur file vide. detruireAvionFile (file.c)\n");
    return;
  }

  avion *courant = file->premier;
  while (courant)
  {
    avion *suivant = courant->next;
    free(courant);
    courant = suivant;
  }
  free(file);
}
