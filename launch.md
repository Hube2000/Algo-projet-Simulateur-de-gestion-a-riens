# 🚀 Lancement Rapide du Simulateur

## Prérequis

Assurez-vous que `make` est installé et ajouté au PATH :

```powershell
# Vérifier si make est installé
make --version

# Si make n'est pas reconnu, installez-le avec winget :
winget install -e --id GnuWin32.Make

# Puis ajoutez-le au PATH pour la session actuelle :
$env:Path += ";C:\Program Files (x86)\GnuWin32\bin"
```

## Démarrage de la simulation multi-terminaux

**Depuis le répertoire du projet :**

```bash
make CC=gcc run-simulation
```

Cette commande va :

- Compiler automatiquement le projet
- Lancer 4 terminaux simultanément :
- **Terminal principal** (`test.exe`) - Gestion globale
- **Terminal visuel** (`terminal_visuel.exe`) - Logs colorés
- **Terminal info** (`terminal_info.exe`) - Statistiques en temps réel
- **Terminal events** (`terminal_events.exe`) - Animations UI des événements

> **Note :** Assurez-vous d'être dans le répertoire racine du projet avant de lancer cette commande.

## Autres commandes utiles

**Compiler seulement :**

```bash
make CC=gcc
```

**Lancer le simulateur simple (1 terminal) :**

```bash
make CC=gcc run
```

**Nettoyer les fichiers compilés :**

```bash
make clean
```

**Voir toutes les options :**

```bash
make help
```
