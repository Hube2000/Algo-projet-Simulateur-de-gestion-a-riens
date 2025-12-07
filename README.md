# Simulateur de Gestion d'Aéroport

Bienvenue dans notre simulateur de gestion d'aéroport ! Ce projet vous permet de gérer en temps réel toutes les opérations d'un aéroport : parking des avions, décollages, atterrissages, ravitaillement en carburant, et même des événements surprises comme des tempêtes ou des attaques terroristes.

## Sommaire

- [À propos](#à-propos)
- [Fonctionnalités](#fonctionnalités)
- [Installation et démarrage](#installation-et-démarrage)
- [Comment ça marche ?](#comment-ça-marche-)
- [Structure du projet](#structure-du-projet)
- [Améliorations futures](#améliorations-futures)

---

## À propos

Ce simulateur a été développé en C dans le cadre d'un projet académique. Il simule les opérations quotidiennes d'un aéroport avec une interface multi-terminaux pour visualiser différents aspects de la simulation en temps réel.

---

## Fonctionnalités

### Ce que vous pouvez faire

**Gérer votre aéroport**

- Voir en temps réel le nombre d'avions au parking (50 places maximum)
- Suivre les avions en vol et ceux en attente pour atterrir
- Gérer 3 pistes de différentes tailles (petite, moyenne, grande)

**Types d'avions**

- Avions de ligne : pour les vols commerciaux avec beaucoup de passagers
- Avions d'affaires : plus petits, pour les vols privés
- Avions légers : pour les vols courts

**Événements imprévisibles**

- Météo difficile : pluie, orages ou neige qui retardent les décollages
- Attaques terroristes : peuvent détruire un avion en vol (rare mais possible)
- Animations visuelles : décollages, atterrissages et crashs affichés en ASCII art

**Sauvegarde automatique**

- Votre progression est sauvegardée tous les 10 cycles
- Vous pouvez fermer et reprendre plus tard exactement où vous en étiez

---

## Installation et démarrage

### Ce dont vous avez besoin

- Un compilateur C (comme GCC)
- Make (pour compiler facilement)
- Windows, Linux ou macOS

### Étapes pour commencer

**1. Télécharger le projet**

```bash
git clone https://github.com/Hube2000/Algo-projet-Simulateur-de-gestion-a-riens.git
cd Algo-projet-Simulateur-de-gestion-a-riens
```

**2. Compiler le programme**

```bash
make
```

C'est tout ! Le programme est prêt.

**3. Lancer la simulation**

Pour lancer avec les terminaux multiples (affichage visuel) :

```bash
cd MultiTerminal
.\lancer_simulation.bat
```

Ou pour lancer le simulateur simple :

```bash
./simulateur.exe    # Windows
```

**4. Première fois**
Au premier lancement, un aéroport sera créé automatiquement avec quelques avions. Les fois suivantes, votre aéroport sauvegardé sera chargé.

**5. Arrêter la simulation**
Appuyez sur `Ctrl + C` - tout sera sauvegardé automatiquement.

**6. Recommencer à zéro**
Supprimez le fichier `aeroport.bin` et relancez le programme.

---

## Comment ça marche ?

### Le système multi-terminaux

Quand vous lancez la simulation avec `lancer_simulation.bat`, trois terminaux s'ouvrent :

**Terminal Visuel (Cyan)**

- Affiche les logs de la simulation cycle par cycle
- Montre les arrivées et départs d'avions
- Signale les événements spéciaux

**Terminal Info (Vert)**

- Affiche les statistiques en temps réel
- Nombre d'avions au parking, en vol, en attente
- État des pistes et niveau de carburant

**Terminal Events (Magenta)**

- Affiche les animations ASCII art
- Décollages, atterrissages, crashs
- Événements spéciaux (attaques, météo)

### Les cycles de simulation

Chaque "cycle" représente 1 minute dans la simulation. À chaque cycle :

1. Les avions en vol consomment du carburant
2. De nouveaux avions peuvent arriver pour atterrir
3. Des avions peuvent décoller du parking
4. Des événements aléatoires peuvent survenir
5. Toutes les 10 minutes, la progression est sauvegardée

### La gestion automatique

Le simulateur gère intelligemment :

- Attribution automatique des pistes selon la taille de l'avion
- Priorisation des atterrissages selon le niveau de carburant
- Ravitaillement en carburant au parking
- Retards de décollage en cas de mauvais temps

---

## Structure du projet

Voici comment le projet est organisé :

```
Algo-projet-Simulateur-de-gestion-a-riens/
├── main.c                          # Programme principal
├── Makefile                        # Pour compiler le projet
├── README.md                       # Ce guide
│
├── MultiTerminal/                  # Version avec affichage multi-terminaux
│   ├── lancer_simulation.bat      # Lance les 3 terminaux
│   ├── terminal_visuel.c          # Terminal des logs
│   ├── terminal_info.c            # Terminal des statistiques
│   ├── terminal_events.c          # Terminal des animations
│   └── Makefile                   # Compilation des terminaux
│
├── UI/                            # Animations ASCII art
│   ├── couleur.h                  # Palette de couleurs
│   ├── atterissage.h              # Animation d'atterrissage
│   ├── Decollage.h                # Animation de décollage
│   ├── crash.h                    # Animation de crash
│   ├── Attack_Terroriste.h        # Animation d'attaque
│   └── Hack.h                     # Animation de hack
│
├── controllers/                   # Gestion des opérations
│   ├── airportController.c        # Opérations sur l'aéroport
│   ├── avionController.c          # Opérations sur les avions
│   └── file.c                     # File d'attente des avions
│
├── fonctionnement/                # Logique de simulation
│   ├── gestion.c                  # Boucle principale
│   ├── gestionAtt.c               # Gestion des atterrissages
│   ├── gestionDec.c               # Gestion des décollages
│   ├── gestionEssence.c           # Gestion du carburant
│   ├── events.c                   # Événements aléatoires
│   └── bdd.c                      # Sauvegarde/Chargement
│
├── headers/                       # Fichiers d'en-tête
│   └── ...                        # Définitions des structures
│
└── verifications/                 # Vérifications
    └── verif.c                    # Compatibilité avion/piste
```

---

## Améliorations futures

Des idées pour améliorer le simulateur :

- [ ] Ajouter une interface graphique moderne
- [ ] Système de coûts et revenus pour chaque vol
- [ ] Intelligence artificielle pour les décisions
- [ ] Mode multijoueur en réseau
- [ ] Graphiques et statistiques avancées
- [ ] Différents niveaux de difficulté
- [ ] Support multilingue
- [ ] Effets sonores

---

## Conseils d'utilisation

**Pour bien profiter du simulateur :**

- Laissez tourner quelques minutes pour voir la simulation évoluer
- Observez les trois terminaux en même temps pour tout comprendre
- En cas de crash d'avion, pas de panique ! C'est rare mais fait partie de la simulation
- Surveillez le niveau de carburant des avions en vol

**En cas de problème :**

- Si la compilation échoue : vérifiez que GCC est bien installé
- Si les couleurs ne s'affichent pas : votre terminal ne supporte peut-être pas les codes ANSI
- Si les exécutables sont bloqués : fermez tous les terminaux avant de recompiler

---

## Développement

Ce projet a été développé en C comme projet académique. Il utilise :

- Des structures de données dynamiques (listes chaînées)
- La gestion de fichiers binaires pour la persistance
- Des codes ANSI pour les couleurs dans le terminal
- Une architecture modulaire pour faciliter la maintenance

---

## Licence

Projet à but éducatif.

---

**Bon vol avec votre simulateur d'aéroport !**
