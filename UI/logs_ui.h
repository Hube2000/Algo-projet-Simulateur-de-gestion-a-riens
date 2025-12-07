#ifndef LOGS_UI_H
#define LOGS_UI_H

#include <stdio.h>
#include <time.h>

static inline void ecrire_log_activite(const char* type, const char* message) {
    FILE *f = fopen("../MultiTerminal/data_cycles.txt", "a");
    if (f) {
        time_t now = time(NULL);
        struct tm *t = localtime(&now);
        fprintf(f, "[%02d:%02d:%02d] %s: %s\n", 
                t->tm_hour, t->tm_min, t->tm_sec, 
                type, message);
        fclose(f);
    }
}

#endif // LOGS_UI_H
