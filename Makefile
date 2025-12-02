CC      ?= gcc
CFLAGS  ?= -Wall -Wextra -Wpedantic -std=c11 -I.
LDFLAGS ?=

APP := simulateur
EXE :=
RM ?= rm -f

ifeq ($(OS),Windows_NT)
	EXE := .exe
endif

TARGET := $(APP)$(EXE)

SRC := \
	controllers/airportController.c \
	controllers/avionController.c \
	controllers/file.c \
	fonctionnement/bdd.c \
	fonctionnement/event.c \
	fonctionnement/gestion.c \
	verifications/verif.c \
	main.c

OBJ := $(SRC:.c=.o)

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $@ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	$(RM) $(OBJ) $(TARGET)
