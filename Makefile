# Compilateur et flags
CC      ?= gcc
CFLAGS  ?= -Wall -Wextra -Wpedantic -std=c11 -I. -Iheaders
LDFLAGS ?=

# Configuration de l'application
APP := simulateur
BUILD_DIR := build

# Extension selon l'OS
ifeq ($(OS),Windows_NT)
	EXE := .exe
	MKDIR := mkdir
	RM := del /Q
	RM_DIR := rmdir /S /Q
	START_CMD := start cmd /k
else
	EXE :=
	MKDIR := mkdir -p
	RM := rm -f
	RM_DIR := rm -rf
	START_CMD := gnome-terminal --
endif

TARGET := $(APP)$(EXE)

# Terminaux de la simulation
TERMINAL_MAIN := Terminal/test$(EXE)
TERMINAL_VISUEL := MultiTerminal/terminal_visuel$(EXE)
TERMINAL_INFO := MultiTerminal/terminal_info$(EXE)
TERMINAL_EVENTS := MultiTerminal/terminal_events$(EXE)

ALL_TERMINALS := $(TERMINAL_MAIN) $(TERMINAL_VISUEL) $(TERMINAL_INFO) $(TERMINAL_EVENTS)

# Liste des fichiers sources
# Note: Tous les fichiers .h sont dans le dossier headers/
SRC := \
	controllers/airportController.c \
	controllers/avionController.c \
	controllers/file.c \
	fonctionnement/gestion.c \
	fonctionnement/bdd.c \
	fonctionnement/events.c \
	fonctionnement/gestionAtt.c \
	fonctionnement/gestionDec.c \
	fonctionnement/gestionEssence.c \
	verifications/verif.c \
	main.c

# Créer les chemins des fichiers .o dans le dossier build
OBJ := $(SRC:%.c=$(BUILD_DIR)/%.o)

.PHONY: all clean run simulation terminals help

# Cible par défaut - compile tout
all: $(TARGET) terminals

# Compile uniquement les terminaux de simulation
simulation: terminals

# Compile tous les terminaux
terminals: $(ALL_TERMINALS)
	@echo Tous les terminaux ont ete compiles avec succes !

# Règle de compilation pour les fichiers dans controllers/
$(BUILD_DIR)/controllers/%.o: controllers/%.c
	@mkdir -p $(BUILD_DIR)/controllers
	@echo Compilation de $<...
	$(CC) $(CFLAGS) -c $< -o $@

# Règle de compilation pour les fichiers dans fonctionnement/
$(BUILD_DIR)/fonctionnement/%.o: fonctionnement/%.c
	@mkdir -p $(BUILD_DIR)/fonctionnement
	@echo Compilation de $<...
	$(CC) $(CFLAGS) -c $< -o $@

# Règle de compilation pour les fichiers dans verifications/
$(BUILD_DIR)/verifications/%.o: verifications/%.c
	@mkdir -p $(BUILD_DIR)/verifications
	@echo Compilation de $<...
	$(CC) $(CFLAGS) -c $< -o $@

# Règle de compilation pour les fichiers à la racine (main.c)
$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(BUILD_DIR)
	@echo Compilation de $<...
	$(CC) $(CFLAGS) -c $< -o $@

# Linkage de l'exécutable
$(TARGET): $(OBJ)
	@echo Linkage de $(TARGET)...
	$(CC) $(OBJ) -o $@ $(LDFLAGS)
	@echo Compilation terminée !

# Terminal principal (test.c)
$(TERMINAL_MAIN): Terminal/test.c $(OBJ)
	@echo Compilation du terminal principal...
	$(CC) $(CFLAGS) Terminal/test.c $(filter-out $(BUILD_DIR)/main.o,$(OBJ)) -o $@ $(LDFLAGS)

# Terminal visuel (logs colorés)
$(TERMINAL_VISUEL): MultiTerminal/terminal_visuel.c
	@echo Compilation du terminal visuel...
	$(CC) $(CFLAGS) MultiTerminal/terminal_visuel.c -o $@ $(LDFLAGS)

# Terminal info (statistiques)
$(TERMINAL_INFO): MultiTerminal/terminal_info.c
	@echo Compilation du terminal info...
	$(CC) $(CFLAGS) MultiTerminal/terminal_info.c -o $@ $(LDFLAGS)

# Terminal events (animations UI)
$(TERMINAL_EVENTS): MultiTerminal/terminal_events.c
	@echo Compilation du terminal events...
	$(CC) $(CFLAGS) MultiTerminal/terminal_events.c -o $@ $(LDFLAGS)

# Lancer l'application principale uniquement
run: $(TARGET)
	./$(TARGET)

# Lancer la simulation complète avec tous les terminaux
run-simulation: terminals
	@echo Lancement de la simulation multi-terminaux...
ifeq ($(OS),Windows_NT)
	@start cmd /k "cd Terminal && test.exe"
	@start cmd /k "cd MultiTerminal && terminal_visuel.exe"
	@start cmd /k "cd MultiTerminal && terminal_info.exe"
	@start cmd /k "cd MultiTerminal && terminal_events.exe"
else
	@gnome-terminal -- bash -c "cd Terminal && ./test; exec bash" &
	@gnome-terminal -- bash -c "cd MultiTerminal && ./terminal_visuel; exec bash" &
	@gnome-terminal -- bash -c "cd MultiTerminal && ./terminal_info; exec bash" &
	@gnome-terminal -- bash -c "cd MultiTerminal && ./terminal_events; exec bash" &
endif
	@echo Simulation lancee avec 4 terminaux !

# Nettoyer les fichiers générés
clean:
	@echo Nettoyage...
ifeq ($(OS),Windows_NT)
	@if exist $(BUILD_DIR) $(RM_DIR) $(BUILD_DIR)
	@if exist $(TARGET) $(RM) $(TARGET)
	@if exist $(TERMINAL_MAIN) $(RM) $(TERMINAL_MAIN)
	@if exist $(TERMINAL_VISUEL) $(RM) $(TERMINAL_VISUEL)
	@if exist $(TERMINAL_INFO) $(RM) $(TERMINAL_INFO)
	@if exist $(TERMINAL_EVENTS) $(RM) $(TERMINAL_EVENTS)
else
	@$(RM_DIR) $(BUILD_DIR)
	@$(RM) $(TARGET)
	@$(RM) $(ALL_TERMINALS)
endif
	@echo Nettoyage termine.

# Aide
help:
	@echo ========================================
	@echo Makefile - Simulateur de gestion aerienne
	@echo ========================================
	@echo.
	@echo Cibles disponibles:
	@echo   make              - Compile tout (simulateur + terminaux)
	@echo   make all          - Identique a make
	@echo   make simulation   - Compile uniquement les terminaux
	@echo   make terminals    - Compile uniquement les terminaux
	@echo   make run          - Lance le simulateur principal
	@echo   make run-simulation - Lance la simulation complete (4 terminaux)
	@echo   make clean        - Nettoie les fichiers compiles
	@echo   make help         - Affiche cette aide
	@echo.
