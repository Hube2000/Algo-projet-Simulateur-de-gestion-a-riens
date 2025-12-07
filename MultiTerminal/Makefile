CC = gcc
CFLAGS = -Wall -I../headers -I../UI

ifeq ($(OS),Windows_NT)
	EXE = .exe
	RM = del /Q
else
	EXE =
	RM = rm -f
endif

TARGETS = terminal_visuel$(EXE) terminal_info$(EXE) terminal_events$(EXE) test$(EXE)

all: $(TARGETS)

terminal_visuel$(EXE): terminal_visuel.c
	$(CC) $(CFLAGS) -o $@ $<

terminal_info$(EXE): terminal_info.c
	$(CC) $(CFLAGS) -o $@ $<

terminal_events$(EXE): terminal_events.c
	$(CC) $(CFLAGS) -o $@ $<

test$(EXE): ../Terminal/test.c
	$(CC) $(CFLAGS) -I../headers -o $@ $^ \
		../controllers/airportController.c \
		../controllers/avionController.c \
		../controllers/file.c \
		../fonctionnement/gestion.c \
		../fonctionnement/bdd.c \
		../fonctionnement/events.c \
		../fonctionnement/gestionAtt.c \
		../fonctionnement/gestionDec.c \
		../fonctionnement/gestionEssence.c \
		../verifications/verif.c

clean:
	$(RM) $(TARGETS) 2>nul

.PHONY: all clean
