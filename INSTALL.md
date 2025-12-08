# 🚀 Guide d'Installation et d'Utilisation

Ce guide vous aide à compiler et lancer la simulation multi-terminal sur **tous les systèmes d'exploitation**.

---

## 📋 Table des matières

1. [Prérequis](#prérequis)
2. [Installation sur Windows](#-windows)
3. [Installation sur Linux](#-linux)
4. [Installation sur macOS](#-macos)
5. [Utilisation](#utilisation)
6. [Dépannage](#dépannage)

---

## Prérequis

Tous les systèmes nécessitent **GCC** (GNU Compiler Collection).

### Vérifier si GCC est installé

```bash
gcc --version
```

Si cette commande affiche une version, GCC est installé. Sinon, suivez les instructions ci-dessous.

---

## 🪟 Windows

### Option A: Utiliser Make (Recommandé)

#### 1. Installer Chocolatey (gestionnaire de paquets)

Ouvrez PowerShell **en tant qu'administrateur** et exécutez:

```powershell
Set-ExecutionPolicy Bypass -Scope Process -Force
[System.Net.ServicePointManager]::SecurityProtocol = [System.Net.ServicePointManager]::SecurityProtocol -bor 3072
iex ((New-Object System.Net.WebClient).DownloadString('https://community.chocolatey.org/install.ps1'))
```

#### 2. Installer GCC et Make

```powershell
choco install mingw make -y
```

#### 3. Redémarrer le terminal

Fermez et rouvrez PowerShell pour appliquer les changements.

#### 4. Utiliser le Makefile

```powershell
make          # Compiler
make run      # Compiler et lancer
make clean    # Nettoyer
make help     # Aide
```

### Option B: Script automatique

Exécutez le script d'installation fourni:

```powershell
.\setup-make.ps1
```

Ce script détecte votre configuration et installe Make automatiquement si possible.

### Option C: Sans Make (Scripts alternatifs)

Si vous ne pouvez pas installer Make, utilisez les scripts fournis:

#### PowerShell (Recommandé)

```powershell
.\build.ps1          # Compiler
.\build.ps1 -Run     # Compiler et lancer
.\build.ps1 -Clean   # Nettoyer
.\build.ps1 -Help    # Aide
```

#### Batch

```batch
build.bat            # Compiler
build.bat run        # Compiler et lancer
build.bat clean      # Nettoyer
build.bat help       # Aide
```

### Installer GCC uniquement (MinGW-w64)

Si vous n'avez que besoin de GCC:

1. Téléchargez **MSYS2**: https://www.msys2.org/
2. Installez-le et ouvrez "MSYS2 MSYS"
3. Exécutez:
   ```bash
   pacman -S mingw-w64-x86_64-gcc make
   ```
4. Ajoutez au PATH: `C:\msys64\mingw64\bin`

---

## 🐧 Linux

### 1. Installer GCC et Make

#### Debian/Ubuntu

```bash
sudo apt update
sudo apt install gcc make
```

#### Fedora/RHEL

```bash
sudo dnf install gcc make
```

#### Arch Linux

```bash
sudo pacman -S gcc make
```

### 2. Rendre le script bash exécutable (optionnel)

```bash
chmod +x build.sh
```

### 3. Utiliser le Makefile ou le script

#### Avec Make (Recommandé)

```bash
make          # Compiler
make run      # Compiler et lancer
make clean    # Nettoyer
make help     # Aide
```

#### Avec le script bash

```bash
./build.sh           # Compiler
./build.sh run       # Compiler et lancer
./build.sh clean     # Nettoyer
./build.sh help      # Aide
```

---

## 🍎 macOS

### 1. Installer Xcode Command Line Tools

```bash
xcode-select --install
```

Cela installe automatiquement GCC et Make.

### 2. Utiliser le Makefile ou le script

#### Avec Make (Recommandé)

```bash
make          # Compiler
make run      # Compiler et lancer
make clean    # Nettoyer
make help     # Aide
```

#### Avec le script bash

```bash
chmod +x build.sh    # Rendre exécutable (une seule fois)
./build.sh           # Compiler
./build.sh run       # Compiler et lancer
./build.sh clean     # Nettoyer
```

---

## 🎮 Utilisation

### Compilation

```bash
make
```

Compile les 4 programmes:

1. `terminal_visuel` - Affichage des cycles
2. `terminal_info` - Informations générales
3. `terminal_events` - Événements visuels
4. `test` - Programme principal de simulation

### Lancement de la simulation

```bash
make run
```

Lance automatiquement **4 terminaux indépendants** :

- **Terminal 1**: Cycles de simulation (visuel)
- **Terminal 2**: Informations générales
- **Terminal 3**: Événements visuels
- **Terminal 4**: Programme principal

### Nettoyage

```bash
make clean
```

Supprime tous les fichiers exécutables compilés.

---

## 🔧 Dépannage

### "make: command not found" (Windows)

➡️ Utilisez les scripts alternatifs:

- `.\build.ps1 -Run` (PowerShell)
- `build.bat run` (Batch)

Ou installez Make via Chocolatey:

```powershell
choco install make -y
```

### "gcc: command not found"

➡️ GCC n'est pas installé. Suivez les instructions d'installation pour votre OS.

### Erreurs de compilation

➡️ Vérifiez que tous les fichiers source sont présents:

```bash
ls -R controllers/ fonctionnement/ verifications/ headers/
```

### Les terminaux ne s'ouvrent pas (Linux)

➡️ Le Makefile utilise `gnome-terminal` par défaut. Pour d'autres terminaux:

**KDE (Konsole):**
Modifiez le Makefile, ligne ~145, remplacez `gnome-terminal` par:

```makefile
konsole --new-tab -e bash -c "cd $(MULTITERMINAL_DIR) && ./terminal_visuel; exec bash" &
```

**XFCE (xfce4-terminal):**

```makefile
xfce4-terminal --tab -e "bash -c 'cd $(MULTITERMINAL_DIR) && ./terminal_visuel; exec bash'" &
```

### Permissions refusées (Linux/macOS)

➡️ Rendez les scripts exécutables:

```bash
chmod +x build.sh
chmod +x MultiTerminal/terminal_*
chmod +x MultiTerminal/test
```

---

## 📁 Structure du Projet

```
.
├── Makefile              # Makefile universel (tous OS)
├── build.ps1             # Script PowerShell (Windows)
├── build.bat             # Script Batch (Windows)
├── build.sh              # Script Bash (Linux/macOS)
├── setup-make.ps1        # Installation automatique de Make (Windows)
├── INSTALL.md            # Ce guide
├── README_BUILD.md       # Documentation de compilation
│
├── MultiTerminal/        # Programmes multi-terminaux
│   ├── terminal_visuel.c
│   ├── terminal_info.c
│   ├── terminal_events.c
│   └── test.c
│
├── fonctionnement/       # Logique métier
├── controllers/          # Contrôleurs
├── verifications/        # Vérifications
└── headers/              # Fichiers d'en-tête (.h)
```

---

## 💡 Conseils

- **Windows**: Préférez PowerShell à CMD pour une meilleure expérience
- **Linux**: Installez `build-essential` pour avoir tous les outils de compilation
- **macOS**: Xcode Command Line Tools est suffisant, pas besoin de Xcode complet
- **Tous**: Utilisez `make help` pour voir toutes les commandes disponibles

---

## 🆘 Support

Si vous rencontrez des problèmes:

1. Vérifiez que GCC est installé: `gcc --version`
2. Vérifiez que Make est installé: `make --version` (ou utilisez les scripts)
3. Consultez ce guide: `README_BUILD.md`
4. Lisez les messages d'erreur attentivement

---

## ✅ Récapitulatif rapide

| OS          | Commande recommandée             |
| ----------- | -------------------------------- |
| **Windows** | `.\build.ps1 -Run` ou `make run` |
| **Linux**   | `make run`                       |
| **macOS**   | `make run`                       |

**Profitez de votre simulation !** 🎉
