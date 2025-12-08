# 🚀 Simulateur de Gestion Aérienne - Guide de Lancement

Ce guide détaille comment compiler et lancer la simulation multi-terminal selon votre système d'exploitation.

---

## 📋 Table des matières

- [Vue d'ensemble](#vue-densemble)
- [Prérequis](#prérequis)
- [Windows](#-windows)
- [Linux](#-linux)
- [macOS](#-macos)
- [Utilisation](#utilisation)
- [Dépannage](#dépannage)

---

## Vue d'ensemble

Ce projet est un **simulateur de gestion aérienne** qui s'exécute sur **4 terminaux simultanés** :

1. **Terminal Visuel** - Affichage graphique des cycles de simulation
2. **Terminal Info** - Informations générales sur l'aéroport
3. **Terminal Events** - Événements visuels et logs en temps réel
4. **Programme Principal** - Gestion de la simulation

---

## Prérequis

### Tous les OS

Vous devez avoir **GCC** (GNU Compiler Collection) installé sur votre système.

**Vérifier si GCC est installé :**
```bash
gcc --version
```

Si cette commande retourne une version, GCC est installé. Sinon, suivez les instructions pour votre OS ci-dessous.

---

## 🪟 Windows

### Étape 1 : Installer GCC

#### Option A : Via Chocolatey (Recommandé)

1. **Installer Chocolatey** (si pas déjà installé)
   
   Ouvrez PowerShell **en tant qu'administrateur** et exécutez :
   ```powershell
   Set-ExecutionPolicy Bypass -Scope Process -Force
   [System.Net.ServicePointManager]::SecurityProtocol = [System.Net.ServicePointManager]::SecurityProtocol -bor 3072
   iex ((New-Object System.Net.WebClient).DownloadString('https://community.chocolatey.org/install.ps1'))
   ```

2. **Installer GCC et Make**
   ```powershell
   choco install mingw make -y
   ```

3. **Redémarrer le terminal**
   
   Fermez et rouvrez PowerShell pour appliquer les changements.

#### Option B : Via MSYS2

1. Téléchargez **MSYS2** : https://www.msys2.org/
2. Installez-le et ouvrez "MSYS2 MSYS"
3. Exécutez :
   ```bash
   pacman -S mingw-w64-x86_64-gcc make
   ```
4. Ajoutez au PATH système : `C:\msys64\mingw64\bin`

### Étape 2 : Lancer la simulation

#### Méthode 1 : Avec Make (Recommandé)

```powershell
# Se placer dans le dossier du projet
cd chemin\vers\Algo-projet-Simulateur-de-gestion-a-riens

# Lancer la simulation
make run
```

#### Méthode 2 : Script batch direct

```powershell
cd MultiTerminal
.\lancer_simulation.bat
```

### Étape 3 : Installation automatique de Make (si besoin)

Si Make n'est pas reconnu, utilisez le script fourni :
```powershell
.\installer-make.bat
```

---

## 🐧 Linux

### Étape 1 : Installer GCC et Make

#### Debian / Ubuntu
```bash
sudo apt update
sudo apt install gcc make -y
```

#### Fedora / RHEL / CentOS
```bash
sudo dnf install gcc make -y
```

#### Arch Linux
```bash
sudo pacman -S gcc make
```

### Étape 2 : Lancer la simulation

```bash
# Se placer dans le dossier du projet
cd ~/chemin/vers/Algo-projet-Simulateur-de-gestion-a-riens

# Lancer la simulation
make run
```

### Note pour Linux

Le Makefile utilise `gnome-terminal` par défaut. Si vous utilisez un autre émulateur de terminal :

**Pour KDE Plasma (Konsole) :**
Modifiez le Makefile ligne ~135 et remplacez `gnome-terminal` par :
```makefile
konsole --new-tab -e bash -c "cd $(MULTITERMINAL_DIR) && ./terminal_visuel; exec bash" &
```

**Pour XFCE (xfce4-terminal) :**
```makefile
xfce4-terminal --tab -e "bash -c 'cd $(MULTITERMINAL_DIR) && ./terminal_visuel; exec bash'" &
```

---

## 🍎 macOS

### Étape 1 : Installer Xcode Command Line Tools

```bash
xcode-select --install
```

Cette commande installe automatiquement GCC, Make et tous les outils de développement nécessaires.

### Étape 2 : Lancer la simulation

```bash
# Se placer dans le dossier du projet
cd ~/chemin/vers/Algo-projet-Simulateur-de-gestion-a-riens

# Lancer la simulation
make run
```

Sur macOS, le Makefile utilise AppleScript pour ouvrir de nouveaux onglets Terminal.app automatiquement.

---

## 🎮 Utilisation

### Commandes Make disponibles

| Commande | Description |
|----------|-------------|
| `make` | Compile tous les exécutables |
| `make build` | Compile tous les exécutables (identique à `make`) |
| `make run` | Compile et lance la simulation multi-terminal |
| `make clean` | Supprime tous les fichiers compilés |
| `make help` | Affiche l'aide du Makefile |

### Déroulement de la simulation

1. **Compilation** - Les 4 programmes sont compilés
2. **Lancement** - 4 terminaux s'ouvrent automatiquement :
   - Terminal Visuel (cycles)
   - Terminal Info (informations générales)
   - Terminal Events (événements visuels)
   - Programme Principal (simulation)

3. **Utilisation** - Interagissez avec le programme principal pour gérer l'aéroport

4. **Arrêt** - Fermez les fenêtres de terminal ou utilisez `Ctrl+C` dans chaque terminal

### Structure du projet

```
Algo-projet-Simulateur-de-gestion-a-riens/
├── Makefile                    # Makefile universel (tous OS)
├── launch-terminals.bat        # Script de lancement Windows
├── installer-make.bat          # Installation automatique de Make (Windows)
│
├── MultiTerminal/              # Code des terminaux
│   ├── terminal_visuel.c       # Affichage visuel
│   ├── terminal_info.c         # Informations
│   ├── terminal_events.c       # Événements
│   ├── test.c                  # Programme principal
│   └── lancer_simulation.bat   # Script alternatif Windows
│
├── fonctionnement/             # Logique métier
│   ├── bdd.c
│   ├── events.c
│   ├── gestion.c
│   ├── gestionAtt.c
│   ├── gestionDec.c
│   └── gestionEssence.c
│
├── controllers/                # Contrôleurs
│   ├── airportController.c
│   ├── avionController.c
│   └── file.c
│
├── verifications/              # Vérifications
│   └── verif.c
│
├── headers/                    # Fichiers d'en-tête
│   └── *.h
│
└── UI/                         # Interface utilisateur
    └── *.h
```

---

## 🔧 Dépannage

### Problème : "make: command not found" (Windows)

**Solution 1 :** Installez Make via Chocolatey
```powershell
choco install make -y
```

**Solution 2 :** Utilisez le script batch directement
```powershell
cd MultiTerminal
.\lancer_simulation.bat
```

**Solution 3 :** Utilisez le script d'installation fourni
```powershell
.\installer-make.bat
```

### Problème : "gcc: command not found"

GCC n'est pas installé. Suivez les instructions d'installation pour votre OS (voir sections ci-dessus).

### Problème : Erreurs de compilation

1. **Vérifiez que tous les fichiers sont présents :**
   ```bash
   ls -R controllers/ fonctionnement/ verifications/ headers/
   ```

2. **Vérifiez la version de GCC :**
   ```bash
   gcc --version
   ```
   Le projet nécessite au minimum le support du standard C11.

3. **Nettoyez et recompilez :**
   ```bash
   make clean
   make
   ```

### Problème : Les terminaux ne s'ouvrent pas

**Windows :**
- Vérifiez que les fichiers .exe sont bien compilés dans `MultiTerminal/`
- Essayez le script batch alternatif : `cd MultiTerminal && .\lancer_simulation.bat`

**Linux :**
- Installez gnome-terminal : `sudo apt install gnome-terminal`
- Ou modifiez le Makefile pour utiliser votre émulateur de terminal

**macOS :**
- Vérifiez que Terminal.app est bien installé (par défaut sur macOS)

### Problème : Permissions refusées (Linux/macOS)

Rendez les exécutables exécutables :
```bash
chmod +x MultiTerminal/terminal_*
chmod +x MultiTerminal/test
```

### Problème : Caractères spéciaux mal affichés

Le projet utilise des caractères UTF-8. Assurez-vous que votre terminal supporte l'UTF-8.

**Windows :** Dans PowerShell, exécutez :
```powershell
[Console]::OutputEncoding = [System.Text.Encoding]::UTF8
```

---

## 📞 Support

Si vous rencontrez des problèmes non listés ci-dessus :

1. Vérifiez que GCC est bien installé : `gcc --version`
2. Vérifiez que Make est bien installé : `make --version`
3. Lisez attentivement les messages d'erreur
4. Consultez les fichiers de documentation :
   - `INSTALL.md` - Guide d'installation détaillé
   - `README.md` - Documentation générale du projet

---

## 🎯 Résumé Rapide

### Windows
```powershell
choco install mingw make -y  # Installation
make run                      # Lancement
```

### Linux
```bash
sudo apt install gcc make -y  # Installation (Ubuntu/Debian)
make run                      # Lancement
```

### macOS
```bash
xcode-select --install       # Installation
make run                     # Lancement
```

---

## ✅ Checklist de lancement

- [ ] GCC installé (`gcc --version`)
- [ ] Make installé (`make --version`)
- [ ] Dans le dossier du projet
- [ ] Exécution de `make run`
- [ ] 4 terminaux s'ouvrent
- [ ] La simulation démarre

**Bon vol ! ✈️**
