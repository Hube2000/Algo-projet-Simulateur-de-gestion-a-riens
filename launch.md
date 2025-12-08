# 🚀 Lancement Rapide du Simulateur

## Démarrage de la simulation multi-terminaux

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
