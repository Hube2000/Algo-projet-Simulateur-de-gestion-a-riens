# Makefile pour la simulation multi-terminal
# Compatible Windows, Linux et macOS

# Détection de l'OS
ifeq ($(OS),Windows_NT)
    # Windows
    RM = del /Q
    RMDIR = rmdir /S /Q
    MKDIR = if not exist $1 mkdir $1
    EXE_EXT = .exe
    PATH_SEP = \\
    CLEAR = cls
    LAUNCH_TERMINAL = start "$(1)" cmd /k "cd /d $(2) && $(3)"
    SLEEP = timeout /t $(1) /nobreak >nul
    CC = gcc
else
    # Unix-like (Linux, macOS)
    RM = rm -f
    RMDIR = rm -rf
    MKDIR = mkdir -p $1
    EXE_EXT =
    PATH_SEP = /
    CLEAR = clear
    UNAME_S := $(shell uname -s)
    ifeq ($(UNAME_S),Darwin)
        # macOS
        LAUNCH_TERMINAL = osascript -e 'tell app "Terminal" to do script "cd $(2) && ./$(3)"'
        SLEEP = sleep $(1)
    else
        # Linux
        LAUNCH_TERMINAL = gnome-terminal --title="$(1)" -- bash -c "cd $(2) && ./$(3); exec bash"
        SLEEP = sleep $(1)
    endif
    CC = gcc
endif

# Compilateur et flags
CFLAGS = -std=c11 -Wall -Wextra
INCLUDES = -Iheaders

# Répertoires
MULTITERMINAL_DIR = MultiTerminal
FONCTIONNEMENT_DIR = fonctionnement
CONTROLLERS_DIR = controllers
VERIFICATIONS_DIR = verifications
BUILD_DIR = build

# Fichiers source
TERMINAL_VISUEL_SRC = $(MULTITERMINAL_DIR)/terminal_visuel.c
TERMINAL_INFO_SRC = $(MULTITERMINAL_DIR)/terminal_info.c
TERMINAL_EVENTS_SRC = $(MULTITERMINAL_DIR)/terminal_events.c
TEST_SRC = $(MULTITERMINAL_DIR)/test.c

FONCTIONNEMENT_SRCS = $(wildcard $(FONCTIONNEMENT_DIR)/*.c)
CONTROLLERS_SRCS = $(wildcard $(CONTROLLERS_DIR)/*.c)
VERIFICATIONS_SRCS = $(wildcard $(VERIFICATIONS_DIR)/*.c)

# Exécutables
TERMINAL_VISUEL = $(MULTITERMINAL_DIR)/terminal_visuel$(EXE_EXT)
TERMINAL_INFO = $(MULTITERMINAL_DIR)/terminal_info$(EXE_EXT)
TERMINAL_EVENTS = $(MULTITERMINAL_DIR)/terminal_events$(EXE_EXT)
TEST_EXEC = $(MULTITERMINAL_DIR)/test$(EXE_EXT)

# Cible par défaut
.PHONY: all
all: build

# Compilation de tous les exécutables
.PHONY: build
build: $(TERMINAL_VISUEL) $(TERMINAL_INFO) $(TERMINAL_EVENTS) $(TEST_EXEC)
	@echo ================================================
	@echo  COMPILATION REUSSIE!
	@echo ================================================

# Compilation du terminal visuel
$(TERMINAL_VISUEL): $(TERMINAL_VISUEL_SRC)
	@echo [1/4] Compilation du terminal visuel...
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@

# Compilation du terminal info
$(TERMINAL_INFO): $(TERMINAL_INFO_SRC)
	@echo [2/4] Compilation du terminal info...
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@

# Compilation du terminal events
$(TERMINAL_EVENTS): $(TERMINAL_EVENTS_SRC)
	@echo [3/4] Compilation du terminal events...
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@

# Compilation du programme principal
$(TEST_EXEC): $(TEST_SRC) $(FONCTIONNEMENT_SRCS) $(CONTROLLERS_SRCS) $(VERIFICATIONS_SRCS)
	@echo [4/4] Compilation du programme principal...
	$(CC) $(CFLAGS) $(INCLUDES) $^ -o $@

# Lancer la simulation
.PHONY: run
run: build
	@echo ================================================
	@echo  LANCEMENT DU SYSTEME MULTI-TERMINAL
	@echo ================================================
ifeq ($(OS),Windows_NT)
	@echo Lancement des terminaux dans 2 secondes...
	@timeout /t 2 /nobreak >nul
	@start "Terminal Visuel - Cycles" cmd /k "cd /d $(MULTITERMINAL_DIR) && terminal_visuel$(EXE_EXT)"
	@timeout /t 1 /nobreak >nul
	@start "Terminal Info - Informations Generales" cmd /k "cd /d $(MULTITERMINAL_DIR) && terminal_info$(EXE_EXT)"
	@timeout /t 1 /nobreak >nul
	@start "Terminal Events - Evenements Visuels" cmd /k "cd /d $(MULTITERMINAL_DIR) && terminal_events$(EXE_EXT)"
	@timeout /t 1 /nobreak >nul
	@start "Programme Principal - Simulation" cmd /k "cd /d $(MULTITERMINAL_DIR) && test$(EXE_EXT)"
	@echo ================================================
	@echo  TOUS LES TERMINAUX SONT LANCES!
	@echo ================================================
else ifeq ($(UNAME_S),Darwin)
	@echo Lancement des terminaux...
	@osascript -e 'tell app "Terminal" to do script "cd \"$(shell pwd)/$(MULTITERMINAL_DIR)\" && ./terminal_visuel$(EXE_EXT)"'
	@sleep 1
	@osascript -e 'tell app "Terminal" to do script "cd \"$(shell pwd)/$(MULTITERMINAL_DIR)\" && ./terminal_info$(EXE_EXT)"'
	@sleep 1
	@osascript -e 'tell app "Terminal" to do script "cd \"$(shell pwd)/$(MULTITERMINAL_DIR)\" && ./terminal_events$(EXE_EXT)"'
	@sleep 1
	@osascript -e 'tell app "Terminal" to do script "cd \"$(shell pwd)/$(MULTITERMINAL_DIR)\" && ./test$(EXE_EXT)"'
	@echo ================================================
	@echo  TOUS LES TERMINAUX SONT LANCES!
	@echo ================================================
else
	@echo Lancement des terminaux...
	@gnome-terminal --title="Terminal Visuel - Cycles" -- bash -c "cd $(MULTITERMINAL_DIR) && ./terminal_visuel$(EXE_EXT); exec bash" &
	@sleep 1
	@gnome-terminal --title="Terminal Info - Informations Generales" -- bash -c "cd $(MULTITERMINAL_DIR) && ./terminal_info$(EXE_EXT); exec bash" &
	@sleep 1
	@gnome-terminal --title="Terminal Events - Evenements Visuels" -- bash -c "cd $(MULTITERMINAL_DIR) && ./terminal_events$(EXE_EXT); exec bash" &
	@sleep 1
	@gnome-terminal --title="Programme Principal - Simulation" -- bash -c "cd $(MULTITERMINAL_DIR) && ./test$(EXE_EXT); exec bash" &
	@echo ================================================
	@echo  TOUS LES TERMINAUX SONT LANCES!
	@echo ================================================
endif

# Nettoyage des fichiers compilés
.PHONY: clean
clean:
	@echo Nettoyage des fichiers compiles...
ifeq ($(OS),Windows_NT)
	@if exist $(MULTITERMINAL_DIR)\terminal_visuel$(EXE_EXT) del /Q $(MULTITERMINAL_DIR)\terminal_visuel$(EXE_EXT)
	@if exist $(MULTITERMINAL_DIR)\terminal_info$(EXE_EXT) del /Q $(MULTITERMINAL_DIR)\terminal_info$(EXE_EXT)
	@if exist $(MULTITERMINAL_DIR)\terminal_events$(EXE_EXT) del /Q $(MULTITERMINAL_DIR)\terminal_events$(EXE_EXT)
	@if exist $(MULTITERMINAL_DIR)\test$(EXE_EXT) del /Q $(MULTITERMINAL_DIR)\test$(EXE_EXT)
else
	@rm -f $(TERMINAL_VISUEL) $(TERMINAL_INFO) $(TERMINAL_EVENTS) $(TEST_EXEC)
endif
	@echo Nettoyage termine!

# Aide
.PHONY: help
help:
	@echo ================================================
	@echo  MAKEFILE - SIMULATION MULTI-TERMINAL
	@echo ================================================
	@echo.
	@echo Commandes disponibles:
	@echo   make          - Compile tous les executables
	@echo   make build    - Compile tous les executables
	@echo   make run      - Compile et lance la simulation
	@echo   make clean    - Supprime les fichiers compiles
	@echo   make help     - Affiche cette aide
	@echo.
	@echo ================================================
