# merci copilot
CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g
LDFLAGS = 

MODELS_DIR = models
VERIF_DIR = verif
TESTE_DIR = teste
DIST_DIR = .dist


MODELS_SOURCES = $(wildcard $(MODELS_DIR)/*.c)
VERIF_SOURCES = $(wildcard $(VERIF_DIR)/*.c)

MODELS_OBJECTS = $(patsubst $(MODELS_DIR)/%.c,$(DIST_DIR)/%.o,$(MODELS_SOURCES))
VERIF_OBJECTS = $(patsubst $(VERIF_DIR)/%.c,$(DIST_DIR)/%.o,$(VERIF_SOURCES))


INCLUDES = -I$(MODELS_DIR) -I$(VERIF_DIR)


TEST_VERIF = $(DIST_DIR)/test-verif.exe

all: $(DIST_DIR) $(TEST_VERIF)


$(DIST_DIR):
	@if not exist $(DIST_DIR) mkdir $(DIST_DIR)


$(DIST_DIR)/%.o: $(MODELS_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@


$(DIST_DIR)/%.o: $(VERIF_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@


$(TEST_VERIF): $(MODELS_OBJECTS) $(VERIF_OBJECTS) $(TESTE_DIR)/test-verif.c
	$(CC) $(CFLAGS) $(INCLUDES) $(TESTE_DIR)/test-verif.c $(MODELS_OBJECTS) $(VERIF_OBJECTS) -o $@ $(LDFLAGS)

test: $(TEST_VERIF)
	@echo.
	@echo === Execution des tests de verification ===
	@$(TEST_VERIF)


clean:
	@if exist $(DIST_DIR)\*.o del /Q $(DIST_DIR)\*.o
	@if exist $(DIST_DIR)\*.exe del /Q $(DIST_DIR)\*.exe
	@echo Nettoyage termine


distclean: clean
	@if exist $(DIST_DIR) rmdir /S /Q $(DIST_DIR)
	@echo Nettoyage complet termine


rebuild: distclean all


help:
	@echo Makefile pour le Simulateur de Gestion Aeroportuaire
	@echo.
	@echo Cibles disponibles:
	@echo   all       - Compile tout le projet (par defaut)
	@echo   test      - Compile et execute les tests
	@echo   clean     - Supprime les fichiers objets et executables
	@echo   distclean - Supprime completement le repertoire .dist
	@echo   rebuild   - Nettoie et recompile tout
	@echo   help      - Affiche cette aide
	@echo.
	@echo Exemples:
	@echo   make          - Compile le projet
	@echo   make test     - Execute les tests
	@echo   make clean    - Nettoie les fichiers compiles

.PHONY: all test clean distclean rebuild help
