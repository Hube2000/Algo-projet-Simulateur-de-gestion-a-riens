#ifndef EVENTS_UI_H
#define EVENTS_UI_H

#include <stdio.h>
#include <time.h>

// Fonction pour écrire un événement dans le fichier partagé
static inline void ecrire_event_UI(const char* event_type, const char* details) {
    FILE *f = fopen("../MultiTerminal/data_events.txt", "a");
    if (f) {
        time_t now = time(NULL);
        struct tm *t = localtime(&now);
        fprintf(f, "[%02d:%02d:%02d] %s - %s\n", 
                t->tm_hour, t->tm_min, t->tm_sec, 
                event_type, details);
        fclose(f);
    }
}

#endif // EVENTS_UI_H
