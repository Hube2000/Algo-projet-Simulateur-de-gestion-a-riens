# ================================================================
# Makefile Universel - Simulation Multi-Terminal
# Compatible: Windows, Linux, macOS
# ================================================================
#
# Utilisation:
#   make          - Compile le projet
#   make run      - Compile et lance la simulation
#   make clean    - Nettoie les fichiers compilés
#   make help     - Affiche l'aide
#
# ================================================================

.PHONY: all build run clean help check-gcc

# Détection automatique de l'OS
ifeq ($(OS),Windows_NT)
    DETECTED_OS := Windows
    EXE_EXT := .exe
    RM := del /Q 2>nul
    WHICH := where
    SEP := \\
else
    UNAME_S := $(shell uname -s)
    ifeq ($(UNAME_S),Linux)
        DETECTED_OS := Linux
    endif
    ifeq ($(UNAME_S),Darwin)
        DETECTED_OS := macOS
    endif
    EXE_EXT :=
    RM := rm -f
    WHICH := which
    SEP := /
endif

# Configuration du compilateur
CC := gcc
CFLAGS := -std=c11 -Wall -Wextra
INCLUDES := -Iheaders

# Répertoires du projet
MULTITERMINAL_DIR := MultiTerminal
FONCTIONNEMENT_DIR := fonctionnement
CONTROLLERS_DIR := controllers
VERIFICATIONS_DIR := verifications

# Fichiers source
TERMINAL_VISUEL_SRC := $(MULTITERMINAL_DIR)/terminal_visuel.c
TERMINAL_INFO_SRC := $(MULTITERMINAL_DIR)/terminal_info.c
TERMINAL_EVENTS_SRC := $(MULTITERMINAL_DIR)/terminal_events.c
TEST_SRC := $(MULTITERMINAL_DIR)/test.c

# Collecte automatique des sources
FONCTIONNEMENT_SRCS := $(wildcard $(FONCTIONNEMENT_DIR)/*.c)
CONTROLLERS_SRCS := $(wildcard $(CONTROLLERS_DIR)/*.c)
VERIFICATIONS_SRCS := $(wildcard $(VERIFICATIONS_DIR)/*.c)

# Exécutables cibles
TERMINAL_VISUEL := $(MULTITERMINAL_DIR)/terminal_visuel$(EXE_EXT)
TERMINAL_INFO := $(MULTITERMINAL_DIR)/terminal_info$(EXE_EXT)
TERMINAL_EVENTS := $(MULTITERMINAL_DIR)/terminal_events$(EXE_EXT)
TEST_EXEC := $(MULTITERMINAL_DIR)/test$(EXE_EXT)

# Tous les exécutables
ALL_EXECS := $(TERMINAL_VISUEL) $(TERMINAL_INFO) $(TERMINAL_EVENTS) $(TEST_EXEC)

# ================================================================
# RÈGLES PRINCIPALES
# ================================================================

# Cible par défaut
all: build

# Vérifier que GCC est installé
check-gcc:
	@echo Verification de GCC...
ifeq ($(OS),Windows_NT)
	@where gcc >nul 2>&1 || (echo ERREUR: gcc n'est pas installe! && echo Installez MinGW-w64 ou MSYS2 && exit 1)
else
	@which gcc >/dev/null 2>&1 || (echo "ERREUR: gcc n'est pas installé!" && exit 1)
endif
	@echo GCC trouve: OK

# Compilation complète
build: check-gcc $(ALL_EXECS)
	@echo ================================================
	@echo  COMPILATION REUSSIE - $(DETECTED_OS)
	@echo ================================================

# Compilation du terminal visuel
$(TERMINAL_VISUEL): $(TERMINAL_VISUEL_SRC)
	@echo [1/4] Compilation du terminal visuel...
	@$(CC) $(CFLAGS) $(INCLUDES) $< -o $@

# Compilation du terminal info
$(TERMINAL_INFO): $(TERMINAL_INFO_SRC)
	@echo [2/4] Compilation du terminal info...
	@$(CC) $(CFLAGS) $(INCLUDES) $< -o $@

# Compilation du terminal events
$(TERMINAL_EVENTS): $(TERMINAL_EVENTS_SRC)
	@echo [3/4] Compilation du terminal events...
	@$(CC) $(CFLAGS) $(INCLUDES) $< -o $@

# Compilation du programme principal
$(TEST_EXEC): $(TEST_SRC) $(FONCTIONNEMENT_SRCS) $(CONTROLLERS_SRCS) $(VERIFICATIONS_SRCS)
	@echo [4/4] Compilation du programme principal...
	@$(CC) $(CFLAGS) $(INCLUDES) $^ -o $@

# ================================================================
# LANCEMENT DE LA SIMULATION
# ================================================================

run: build
	@echo ================================================
	@echo  LANCEMENT MULTI-TERMINAL - $(DETECTED_OS)
	@echo ================================================
ifeq ($(OS),Windows_NT)
	@echo Demarrage des terminaux Windows...
	@launch-terminals.bat
	@echo Tous les terminaux sont lances!
else ifeq ($(DETECTED_OS),macOS)
	@echo Demarrage des terminaux macOS...
	@osascript -e 'tell app "Terminal" to do script "cd \"$(shell pwd)/$(MULTITERMINAL_DIR)\" && ./terminal_visuel"'
	@sleep 1
	@osascript -e 'tell app "Terminal" to do script "cd \"$(shell pwd)/$(MULTITERMINAL_DIR)\" && ./terminal_info"'
	@sleep 1
	@osascript -e 'tell app "Terminal" to do script "cd \"$(shell pwd)/$(MULTITERMINAL_DIR)\" && ./terminal_events"'
	@sleep 1
	@osascript -e 'tell app "Terminal" to do script "cd \"$(shell pwd)/$(MULTITERMINAL_DIR)\" && ./test"'
	@echo
	@echo Tous les terminaux sont lances!
else
	@echo Demarrage des terminaux Linux...
	@gnome-terminal --title="Terminal Visuel - Cycles" -- bash -c "cd $(MULTITERMINAL_DIR) && ./terminal_visuel; exec bash" 2>/dev/null &
	@sleep 1
	@gnome-terminal --title="Terminal Info - Informations" -- bash -c "cd $(MULTITERMINAL_DIR) && ./terminal_info; exec bash" 2>/dev/null &
	@sleep 1
	@gnome-terminal --title="Terminal Events - Evenements" -- bash -c "cd $(MULTITERMINAL_DIR) && ./terminal_events; exec bash" 2>/dev/null &
	@sleep 1
	@gnome-terminal --title="Programme Principal - Simulation" -- bash -c "cd $(MULTITERMINAL_DIR) && ./test; exec bash" 2>/dev/null &
	@echo
	@echo Tous les terminaux sont lances!
endif
	@echo ================================================

# ================================================================
# NETTOYAGE
# ================================================================

clean:
	@echo Nettoyage des fichiers compiles...
ifeq ($(OS),Windows_NT)
	@if exist $(MULTITERMINAL_DIR)$(SEP)terminal_visuel.exe $(RM) $(MULTITERMINAL_DIR)$(SEP)terminal_visuel.exe
	@if exist $(MULTITERMINAL_DIR)$(SEP)terminal_info.exe $(RM) $(MULTITERMINAL_DIR)$(SEP)terminal_info.exe
	@if exist $(MULTITERMINAL_DIR)$(SEP)terminal_events.exe $(RM) $(MULTITERMINAL_DIR)$(SEP)terminal_events.exe
	@if exist $(MULTITERMINAL_DIR)$(SEP)test.exe $(RM) $(MULTITERMINAL_DIR)$(SEP)test.exe
else
	@$(RM) $(ALL_EXECS)
endif
	@echo Nettoyage termine!

# ================================================================
# AIDE
# ================================================================

help:
	@echo ================================================================
	@echo  MAKEFILE UNIVERSEL - SIMULATION MULTI-TERMINAL
	@echo  Systeme detecte: $(DETECTED_OS)
	@echo ================================================================
	@echo.
	@echo Commandes disponibles:
	@echo   make          - Compile tous les executables
	@echo   make build    - Compile tous les executables
	@echo   make run      - Compile et lance la simulation multi-terminal
	@echo   make clean    - Supprime les fichiers compiles
	@echo   make help     - Affiche cette aide
	@echo.
	@echo Prerequis:
	@echo   - GCC (GNU Compiler Collection)
	@echo     Windows: MinGW-w64 ou MSYS2
	@echo     Linux:   sudo apt install gcc
	@echo     macOS:   xcode-select --install
	@echo.
	@echo Structure de la simulation:
	@echo   4 terminaux independants seront lances:
	@echo   1. Terminal Visuel  - Affichage des cycles
	@echo   2. Terminal Info    - Informations generales
	@echo   3. Terminal Events  - Evenements visuels
	@echo   4. Programme Principal - Simulation
	@echo.
	@echo ================================================================
