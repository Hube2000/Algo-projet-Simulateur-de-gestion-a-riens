# Makefile pour le Simulateur de Gestion Aérienne
# Compilateur et options
CC      ?= gcc
CFLAGS  ?= -Wall -Wextra -Wpedantic -std=c11 -I.
LDFLAGS ?=

# Nom de l'application
APP := simulateur
EXE :=
RM ?= rm -f

# Gestion Windows/Linux
ifeq ($(OS),Windows_NT)
	EXE := .exe
endif

TARGET := $(APP)$(EXE)

# Sources du projet
SRC := \
	controllers/airportController.c \
	controllers/avionController.c \
	controllers/file.c \
	fonctionnement/bdd.c \
	fonctionnement/event.c \
	fonctionnement/gestion.c \
	verifications/verif.c \
	main.c

# Fichiers objets
OBJ := $(SRC:.c=.o)

# Cibles phony
.PHONY: all clean run help

# Cible par défaut
all: $(TARGET)
	@echo "Compilation terminée : $(TARGET)"

# Compilation de l'exécutable
$(TARGET): $(OBJ)
	@echo "Liaison des fichiers objets..."
	$(CC) $(OBJ) -o $@ $(LDFLAGS)

# Règle générique pour compiler les .c en .o
%.o: %.c
	@echo "Compilation de $<..."
	$(CC) $(CFLAGS) -c $< -o $@

# Exécuter le programme
run: $(TARGET)
	@echo "Exécution du simulateur..."
	./$(TARGET)

# Nettoyer les fichiers compilés
clean:
	@echo "Nettoyage des fichiers compilés..."
	$(RM) $(OBJ) $(TARGET)
	@echo "Nettoyage terminé."

# Nettoyage complet (inclut les fichiers de sauvegarde)
clean-all: clean
	@echo "Nettoyage complet..."
	$(RM) aeroport.bin test_aeroport.bin log
	@echo "Nettoyage complet terminé."

# Aide
help:
	@echo "Makefile pour le Simulateur de Gestion Aérienne"
	@echo ""
	@echo "Cibles disponibles :"
	@echo "  make          - Compile le projet"
	@echo "  make run      - Compile et exécute le simulateur"
	@echo "  make clean    - Supprime les fichiers compilés (.o et exécutable)"
	@echo "  make clean-all - Supprime aussi les fichiers de sauvegarde (.bin, log)"
	@echo "  make help     - Affiche cette aide"
	@echo ""
