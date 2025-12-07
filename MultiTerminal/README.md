# Système Multi-Terminal pour la Simulation d'Aéroport

Ce dossier contient les fichiers pour le système multi-terminal qui permet de visualiser la simulation d'aéroport sur plusieurs fenêtres séparées.

## Fichiers

- **terminal_visuel.c** : Affiche les cycles de la simulation en temps réel
- **terminal_info.c** : Affiche les informations générales de l'aéroport (statistiques, état des pistes)
- **lancer_simulation.bat** : Script pour compiler et lancer tous les terminaux automatiquement

## Utilisation

Double-cliquez sur `lancer_simulation.bat` pour :

1. Compiler tous les programmes
2. Lancer 3 fenêtres de terminal :
   - **Terminal Visuel** : Affiche les cycles de simulation
   - **Terminal Info** : Affiche les statistiques et l'état de l'aéroport
   - **Programme Principal** : Exécute la simulation

## Fichiers de données partagés

- `data_cycles.txt` : Contient les informations de chaque cycle
- `data_info.txt` : Contient les statistiques générales de l'aéroport

Ces fichiers sont créés et mis à jour automatiquement par le programme principal (`test.c`).
