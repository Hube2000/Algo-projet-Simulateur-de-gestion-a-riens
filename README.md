# ✈️ Simulateur de Gestion d'Aéroport

Un simulateur en temps réel pour gérer les opérations d'un aéroport, incluant le parking des avions, les décollages, les atterrissages, la gestion du carburant, et les événements imprévisibles.

## 📋 Table des matières

- [Fonctionnalités](#fonctionnalités)
- [Architecture](#architecture)
- [Installation](#installation)
- [Compilation](#compilation)
- [Utilisation](#utilisation)
- [Structure du projet](#structure-du-projet)
- [API Principale](#api-principale)

---

## ✨ Fonctionnalités

### Gestion de l'Aéroport
- 🅿️ **Parking** : Gestion de l'espace disponible pour les avions au sol
- ✈️ **Avions en vol** : Suivi des avions en cours de vol
- 🛬 **Attente aérienne** : File d'attente pour l'atterrissage
- 🛫 **Pistes** : 3 pistes avec capacités différentes (petite, moyenne, grande)

### Gestion des Avions
- **Types d'avions** : Ligne, Affaire, Léger
- **Passagers** : Suivi du nombre de passagers par avion
- **Carburant** : Gestion du carburant et consommation en vol
- **ID unique** : Identification automatique de chaque avion

### Événements
- 🌧️ **Météo** : Pluie, Orage, Neige (décalage des décollages)
- 💥 **Attaque terroriste** : Destruction aléatoire d'un avion en vol

### Persistance
- 💾 **Sauvegarde automatique** : Tous les 10 cycles
- 📂 **Base de données binaire** : Fichier `aeroport.bin` pour charger l'état précédent
- 🔄 **Charger/Reprendre** : Reprenez votre simulation exactement où vous l'aviez laissée

---

## 🏗️ Architecture

### Couches du Projet

```
┌─────────────────────────────────┐
│        main.c (Boucle)          │  Gestion de la simulation
├─────────────────────────────────┤
│    Gestionnaires (gestion.*)    │  Logique métier
├─────────────────────────────────┤
│   Contrôleurs (controllers/)    │  Manipulation des structures
├─────────────────────────────────┤
│   Modèles (headers/*.h)         │  Définitions de structures
└─────────────────────────────────┘
```

### Modules Principaux

| Module | Description |
|--------|-------------|
| `aeroport.h / airportController.c` | Création et gestion de l'aéroport |
| `avion.h / avionController.c` | Création et manipulation des avions |
| `file.h / file.c` | File doublement chaînée pour les avions |
| `gestion.c` | Boucle principale de simulation |
| `gestionAtt.c` | Gestion des atterrissages |
| `gestionDec.c` | Gestion des décollages |
| `gestionEssence.c` | Gestion du carburant |
| `events.c` | Événements météo et terroristes |
| `verif.c` | Vérifications de compatibilité |
| `bdd.c` | Persistance (sauvegarde/chargement) |

---

## 🔧 Installation

### Prérequis
- **Compilateur C** : GCC ou Clang (C11 minimum)
- **Make** : Pour automatiser la compilation
- **Système d'exploitation** : Windows, Linux, macOS

### Étapes

1. **Cloner le dépôt**
```bash
git clone https://github.com/votre-utilisateur/Algo-projet-Simulateur-de-gestion-a-riens.git
cd Algo-projet-Simulateur-de-gestion-a-riens
```

2. **Vérifier les fichiers**
```bash
ls
# Doit contenir: main.c, Makefile, README.md, controllers/, fonctionnement/, headers/, verifications/
```

---

## 🔨 Compilation

### Compiler le projet
```bash
make
```

### Nettoyer les fichiers compilés
```bash
make clean
```

### Recompiler à partir de zéro
```bash
make clean && make
```

### Compiler avec flags personnalisés (optionnel)
```bash
make CC=clang CFLAGS="-Wall -Wextra -O2"
```

---

## ▶️ Utilisation

### Lancer le simulateur
```bash
./simulateur.exe    # Windows
./simulateur        # Linux/macOS
```

### Première exécution
- ✅ Un aéroport est créé automatiquement
- ✅ 5 à 15 avions aléatoires sont générés
- ✅ La base de données `aeroport.bin` est créée

### Exécutions suivantes
- 📂 L'aéroport sauvegardé est automatiquement chargé
- 🔄 Vous pouvez continuer votre simulation
- 🗑️ Pour recommencer, supprimez `aeroport.bin`

### Arrêt du simulateur
```bash
Ctrl + C    # Sauvegarde automatique avant arrêt
```

---

## 📁 Structure du projet

```
Algo-projet-Simulateur-de-gestion-a-riens/
├── main.c                          # Point d'entrée principal
├── Makefile                         # Automatisation de la compilation
├── README.md                        # Ce fichier
├── aeroport.bin                     # Base de données (créée dynamiquement)
│
├── controllers/                     # Contrôleurs (manipulation)
│   ├── airportController.c         # Gestion aéroport
│   ├── avionController.c           # Gestion avions
│   └── file.c                      # File chaînée
│
├── fonctionnement/                  # Logique métier
│   ├── gestion.c                   # Boucle principale
│   ├── gestionAtt.c                # Gestion atterrissages
│   ├── gestionDec.c                # Gestion décollages
│   ├── gestionEssence.c            # Gestion carburant
│   ├── bdd.c                       # Persistance données
│   └── events.c                    # Événements
│
├── headers/                         # Fichiers d'en-têtes (interfaces)
│   ├── aeroport.h
│   ├── airportController.h
│   ├── avion.h
│   ├── avionController.h
│   ├── bdd.h
│   ├── events.h
│   ├── file.h
│   ├── gestion.h
│   ├── gestionAtt.h
│   ├── gestionDec.h
│   ├── gestionEssence.h
│   ├── piste.h
│   └── verif.h
│
├── verifications/                   # Vérifications
│   └── verif.c                     # Compatibilité avion/piste
│
└── build/                           # Dossier de compilation (créé par make)
    ├── controllers/
    ├── fonctionnement/
    └── verifications/
```

---

## 🎯 API Principale

### Initialisation
```c
Aeroport *initAeroportBDD(const char *nom_fichier);
void sauvegarderAeroportBDD(Aeroport *aeroport, const char *nom_fichier);
```

### Gestion Avions
```c
avion *creerAvion(Aeroport *airport);
avion *rechercherAvion(AvionFile *file, int id);
void retirerAvion(AvionFile *file, int id);
```

### Gestion Files
```c
AvionFile *creerAvionFile(void);
void ajouterDebutFile(AvionFile *file, avion *a);
void ajouterFinFile(AvionFile *file, avion *a);
void supprimerDebutFile(AvionFile *file);
void supprimerFinFile(AvionFile *file);
```

### Événements
```c
void MeteoEvent(Aeroport *aeroport);
void AttaqueTerroristeEvent(Aeroport *aeroport);
void triggerRandomEvent(Aeroport *airport);
```

### Gestion Opérations
```c
void manageAirport(Aeroport *aeroport);
void displayAirport(Aeroport *aeroport);
void consume_carburant_vol(Aeroport *aeroport);
```

---

## 📊 Exemple de Sortie

```
Fichier aeroport.bin introuvable. Création d'un nouvel aéroport...
Aéroport créé avec 8 avions dans le parking.
Aéroport sauvegardé dans aeroport.bin:
  - Parking: 8 avions
  - En vol: 0 avions
  - File aérienne: 0 avions

======================================================================
                    SIMULATEUR DE GESTION
                         D'AEROPORT
======================================================================

----------------------------------------------------------------------
HEURE ACTUELLE : 0 minutes
----------------------------------------------------------------------

STATISTIQUES:
   - Passagers totaux: 0
   - Départs: 0
   - Retours: 0
   - Total avions créés: 8

----------------------------------------------------------------------
PARKING (8/50 places)
----------------------------------------------------------------------
   - Avion #0 [Ligne] | Passagers: 148 | Carburant: 100%
   - Avion #1 [Affaire] | Passagers: 75 | Carburant: 100%
   ...
```

---

## 🚀 Améliorations Futures

- [ ] Interface graphique (GTK, SDL)
- [ ] Système de coûts et revenus
- [ ] IA pour les décisions des avions
- [ ] Réseau multijoueur
- [ ] Statistiques détaillées et graphiques
- [ ] Modes de difficulté

---

## 📝 Notes de Développement

### Compilation Flags
- `-Wall -Wextra -Wpedantic` : Tous les avertissements activés
- `-std=c11` : Norme C11
- `-I. -Iheaders` : Chemins d'inclusion

### Gestion de Mémoire
- Allocation dynamique avec `malloc`
- Libération avec `free` ou `detruireAeroport()`
- Vérifications NULL systématiques

### Base de Données
- Format : Binaire pour rapidité et compacité
- Persistance : `aeroport.bin`
- Sauvegarde automatique : Tous les 10 cycles + Ctrl+C

---

## 👨‍💻 Auteur

Développé comme projet académique en C.

---

## 📄 Licence

Ce projet est fourni à titre éducatif.

---

**Bon amusement avec votre simulateur d'aéroport ! 🛫✈️🛬**# Algo-projet-Simulateur-de-gestion-aeriens
