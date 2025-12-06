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
else
	EXE :=
endif

TARGET := $(APP)$(EXE)

# Liste des fichiers sources
# Note: Tous les fichiers .h sont dans le dossier headers/
SRC := \
	controllers/airportController.c \
	controllers/avionController.c \
	controllers/file.c \
	fonctionnement/gestion.c \
	fonctionnement/gestionAtt.c \
	fonctionnement/gestionDec.c \
	fonctionnement/gestionEssence.c \
	verifications/verif.c \
	main.c

# Créer les chemins des fichiers .o dans le dossier build
OBJ := $(SRC:%.c=$(BUILD_DIR)/%.o)

.PHONY: all clean run

all: $(TARGET)

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

# Lancer l'application
run: $(TARGET)
	./$(TARGET)

# Nettoyer les fichiers générés
clean:
	@echo Nettoyage...
	@rm -rf $(BUILD_DIR)
	@rm -f $(TARGET)
	@echo Nettoyage terminé.
