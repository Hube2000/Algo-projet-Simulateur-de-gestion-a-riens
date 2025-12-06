#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../models/avion.h"
#include "../models/aeroport.h"
#include "../models/piste.h"
#include "../controllers/airportController.h"

void genererAvionsAleatoires(Aeroport *aeroport, int nombre_avions)
{
    if (!aeroport || !aeroport->parking)
        return;

    // Générer le nombre d'avions demandé et les ajouter au parking
    for (int i = 0; i < nombre_avions; i++)
    {
        avion *nouvel_avion = creerAvion(aeroport);
        if (nouvel_avion)
        {
            // Donner une heure aléatoire pour le créneau de décollage
            // Entre l'heure actuelle et +50 (pour espacer les décollages)
            nouvel_avion->heure = aeroport->heure + (rand() % 50) + 5;
            // Donner aussi un nombre de passagers aléatoire
            nouvel_avion->nombre_de_passagers = rand() % 200 + 1;
            ajouterFinFile(aeroport->parking, nouvel_avion);
            // Mettre à jour le compteur total d'avions
            aeroport->total_avions++;
        }
    }
}

void sauvegarderAvion(FILE *f, avion *a)
{
    if (!f || !a)
        return;

    fwrite(&a->id, sizeof(int), 1, f);
    int categorie = (int)a->categorie;
    fwrite(&categorie, sizeof(int), 1, f);
    fwrite(&a->etat, sizeof(int), 1, f);
    fwrite(&a->nombre_de_passagers, sizeof(int), 1, f);
    fwrite(&a->heure, sizeof(int), 1, f);
}

avion *chargerAvion(FILE *f)
{
    if (!f)
        return NULL;

    avion *a = malloc(sizeof(avion));
    if (!a)
        return NULL;

    int id, categorie, etat, nombre_de_passagers, heure;

    if (fread(&id, sizeof(int), 1, f) != 1 ||
        fread(&categorie, sizeof(int), 1, f) != 1 ||
        fread(&etat, sizeof(int), 1, f) != 1 ||
        fread(&nombre_de_passagers, sizeof(int), 1, f) != 1 ||
        fread(&heure, sizeof(int), 1, f) != 1)
    {
        free(a);
        return NULL;
    }

    a->id = id;
    a->categorie = (CATEGORIE_AVION)categorie;
    a->etat = etat;
    a->nombre_de_passagers = nombre_de_passagers;
    a->heure = heure;
    a->next = NULL;
    a->prev = NULL;

    return a;
}

void sauvegarderFileAvions(FILE *f, AvionFile *file)
{
    int nombre = 0;

    if (file)
    {
        nombre = file->nbElement;
    }

    fwrite(&nombre, sizeof(int), 1, f);

    if (file && nombre > 0)
    {
        avion *current = file->premier;
        while (current != NULL)
        {
            sauvegarderAvion(f, current);
            current = current->next;
        }
    }
}

void chargerFileAvions(FILE *f, AvionFile *file)
{
    if (!f || !file)
        return;

    int nombre_avions;
    if (fread(&nombre_avions, sizeof(int), 1, f) != 1)
    {
        nombre_avions = 0;
    }

    for (int i = 0; i < nombre_avions; i++)
    {
        avion *a = chargerAvion(f);
        if (a)
        {
            ajouterFinFile(file, a);
        }
    }
}

Aeroport *initAeroportBDD(const char *nom_fichier)
{
    FILE *f = fopen(nom_fichier, "rb");

    // Si le fichier n'existe pas -> créer un nouveau airport
    if (!f)
    {
        printf("Fichier %s introuvable. Création d'un nouvel aéroport...\n", nom_fichier);

        Aeroport *aeroport = creerAeroport();
        if (!aeroport)
        {
            printf("ERREUR: Impossible de créer l'aéroport.\n");
            return NULL;
        }

        srand(time(NULL));
        int nombre_avions = rand() % 11 + 5; // 5 à 15 avions
        genererAvionsAleatoires(aeroport, nombre_avions);

        printf("Aéroport créé avec %d avions dans le parking.\n", nombre_avions);

        // Sauvegarder le nouvel aéroport
        sauvegarderAeroportBDD(aeroport, nom_fichier);

        return aeroport;
    }

    // Si le fichier existe, charger l'aéroport
    printf("Chargement de l'aéroport depuis %s...\n", nom_fichier);

    // Créer un aéroport de base
    Aeroport *aeroport = creerAeroport();
    if (!aeroport)
    {
        fclose(f);
        printf("ERREUR: Impossible de créer l'aéroport.\n");
        return NULL;
    }

    // Load les données de base de l'aéroport
    if (fread(&aeroport->places, sizeof(int), 1, f) != 1 ||
        fread(&aeroport->passagers, sizeof(int), 1, f) != 1 ||
        fread(&aeroport->departs, sizeof(int), 1, f) != 1 ||
        fread(&aeroport->retours, sizeof(int), 1, f) != 1 ||
        fread(&aeroport->heure, sizeof(int), 1, f) != 1 ||
        fread(&aeroport->total_avions, sizeof(int), 1, f) != 1)
    {
        printf("ERREUR: Impossible de lire les données de l'aéroport.\n");
        detruireAeroport(aeroport);
        fclose(f);
        return NULL;
    }

    // Load toutes les files d'avions
    chargerFileAvions(f, aeroport->parking);
    chargerFileAvions(f, aeroport->liste_avions_en_vol);
    chargerFileAvions(f, aeroport->file_attente_aerienne);

    // Load les avions sur les pistes
    for (int i = 0; i < 3; i++)
    {
        if (aeroport->pistes[i] && aeroport->pistes[i]->liste_avions_attente)
        {
            chargerFileAvions(f, aeroport->pistes[i]->liste_avions_attente);
        }
        else
        {
            // Lire le nombre d'avions même si la piste n'existe pas
            int nombre_avions;
            if (fread(&nombre_avions, sizeof(int), 1, f) != 1)
            {
                printf("ATTENTION: Erreur lors de la lecture de la piste %d\n", i + 1);
            }
            // Ignorer les données des avions si la piste n'existe pas
            for (int j = 0; j < nombre_avions; j++)
            {
                avion *a_ignore = chargerAvion(f);
                if (a_ignore)
                {
                    free(a_ignore); // Libérer la mémoire de l'avion ignoré
                }
            }
        }
    }

    fclose(f);

    // Verif la cohérence de total_avions avec le nombre d'avions load
    int avions_reels = aeroport->parking->nbElement +
                       aeroport->liste_avions_en_vol->nbElement +
                       aeroport->file_attente_aerienne->nbElement;
    for (int i = 0; i < 3; i++)
    {
        if (aeroport->pistes[i] && aeroport->pistes[i]->liste_avions_attente)
        {
            avions_reels += aeroport->pistes[i]->liste_avions_attente->nbElement;
        }
    }

    if (aeroport->total_avions != avions_reels)
    {
        printf("ATTENTION: Incohérence détectée. total_avions=%d mais %d avions chargés.\n",
               aeroport->total_avions, avions_reels);
        printf("Correction de total_avions...\n");
        aeroport->total_avions = avions_reels;
    }

    printf("Aéroport chargé avec succès:\n");
    printf("  - Parking: %d avions\n", aeroport->parking->nbElement);
    printf("  - En vol: %d avions\n", aeroport->liste_avions_en_vol->nbElement);
    printf("  - File aérienne: %d avions\n", aeroport->file_attente_aerienne->nbElement);
    for (int i = 0; i < 3; i++)
    {
        if (aeroport->pistes[i] && aeroport->pistes[i]->liste_avions_attente)
        {
            printf("  - Piste %d: %d avions\n", i + 1, aeroport->pistes[i]->liste_avions_attente->nbElement);
        }
    }
    printf("  - Total avions: %d\n", aeroport->total_avions);

    return aeroport;
}

void sauvegarderAeroportBDD(Aeroport *aeroport, const char *nom_fichier)
{
    if (!aeroport || !nom_fichier)
    {
        printf("ERREUR: Paramètres invalides pour la sauvegarde.\n");
        return;
    }

    // Veif que toutes les files existent
    if (!aeroport->parking || !aeroport->liste_avions_en_vol ||
        !aeroport->file_attente_aerienne)
    {
        printf("ERREUR: Files d'avions invalides pour la sauvegarde.\n");
        return;
    }

    FILE *f = fopen(nom_fichier, "wb");
    if (!f)
    {
        printf("ERREUR: Impossible de créer le fichier %s.\n", nom_fichier);
        return;
    }

    // Save les datas de l'aéroport
    fwrite(&aeroport->places, sizeof(int), 1, f);
    fwrite(&aeroport->passagers, sizeof(int), 1, f);
    fwrite(&aeroport->departs, sizeof(int), 1, f);
    fwrite(&aeroport->retours, sizeof(int), 1, f);
    fwrite(&aeroport->heure, sizeof(int), 1, f);
    fwrite(&aeroport->total_avions, sizeof(int), 1, f);

    // Save toutes les files d'avions
    sauvegarderFileAvions(f, aeroport->parking);
    sauvegarderFileAvions(f, aeroport->liste_avions_en_vol);
    sauvegarderFileAvions(f, aeroport->file_attente_aerienne);

    // Save les avions sur les pistes
    for (int i = 0; i < 3; i++)
    {
        if (aeroport->pistes[i] && aeroport->pistes[i]->liste_avions_attente)
        {
            sauvegarderFileAvions(f, aeroport->pistes[i]->liste_avions_attente);
        }
        else
        {
            int zero = 0;
            fwrite(&zero, sizeof(int), 1, f);
        }
    }

    fclose(f);
    printf("Aéroport sauvegardé dans %s:\n", nom_fichier);
    printf("  - Parking: %d avions\n", aeroport->parking->nbElement);
    printf("  - En vol: %d avions\n", aeroport->liste_avions_en_vol->nbElement);
    printf("  - File aérienne: %d avions\n", aeroport->file_attente_aerienne->nbElement);

    for (int i = 0; i < 3; i++)
    {
        if (aeroport->pistes[i] && aeroport->pistes[i]->liste_avions_attente)
        {
            printf("  - Piste %d: %d avions\n", i + 1, aeroport->pistes[i]->liste_avions_attente->nbElement);
        }
    }
}

void chargerAvionBDD(AvionFile *file, char *path)
{

    FILE *f = fopen(path, "rb");
    if (!f)
    {
        printf("ERREUR DE BDD %s\n", path);
        return;
    }

    // Load tous les avions jusqu'à la fin du fichier
    int compteur = 0;
    avion *a;
    while ((a = chargerAvion(f)))
    {
        ajouterDebutFile(file, a);
        compteur++;
    }

    // Verif si on a bien atteint la fin du fichier
    if (!feof(f))
    {
        printf("ATTENTION: Fichier %s possiblement corrompu. %d avions chargés.\n", path, compteur);
    }

    fclose(f);
}

void sauvegarderAvionBDD(AvionFile *file)
{
    FILE *f = fopen("log", "wb");
    if (!f)
    {
        printf("ERREUR DE BDD : impossible d'ouvrir le fichier \n");
        return;
    }

    avion *current = file->premier;
    while (current != NULL)
    {
        sauvegarderAvion(f, current);
        current = current->next;
    }

    fclose(f);
}