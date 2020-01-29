/*
### Esercizio ###
Si scriva un programma in linguaggio C che legga il contenuto di un file dopo
averne ricevuto il nome da linea di comando. Il numero di righe del file sia al
massimo 80 e ciascuna riga del file contenga i seguenti campi, ciascuno composto
al massimo da 20 caratteri e privo di spazi.
    <materia> <nome prof> <cognome prof> <periodo> <crediti> <% superamento esame>
Il programma dovrà stampare a video:
 a) il nome della materia che assegna più crediti in assoluto
 b) per ciascun periodo didattico (considerare max 4), la materia più difficile
    da superare.
Il programma dovrà infine richiedere l'inserimento da tastiera di un cognome di
professore (max 20 caratteri) e stampare a video:
 c) la somma dei crediti assegnati dalle materie che insegna
 d) la media di superamento degli esami da lui tenuti
## Approfondimento ##
in a) e b), se si verificasse il caso in cui siano presenti due o più materie che
assegnano il numero massimo di crediti o abbiano nello stesso periodo il minor tasso,
di superamento, il programma dovrà stampare l'elenco completo delle materie
identificate
*/

#include <stdio.h>
#include <string.h>

#define MAX_STR 20
#define MAX_LINES 80
#define MAX_SUBJECTS_COUNT 4

typedef struct Line {
    char subject[MAX_STR];
    char prof_name[MAX_STR];
    char prof_surname[MAX_STR];
    int period;
    int credits;
    int percent_sup;
} Line;

void point_a(Line *lines, int lines_count) {
    int i, found_count = 0, highest = 0;
    Line *best[MAX_LINES];
    for (i = 0; i < lines_count; ++i) {
        if (lines[i].credits > highest) {
            highest = lines[i].credits;
            best[0] = &lines[i];
            found_count = 1;
        } else if (lines[i].credits == highest) {
            best[found_count++] = &lines[i];
        }
    }
    for (i = 0; i < found_count; ++i)
        printf("materia che assegna più crediti in assoluto: %s\n", best[i]->subject);
}

int point_b_find_periods(Line *lines, int lines_count, int *periods_found) {
    int i, j, periods_count = 0;
    int periods[MAX_SUBJECTS_COUNT];
    for (i = 0; i < lines_count; ++i) {
        if (periods_count >= MAX_SUBJECTS_COUNT)
            break;
        for (j = 0; j < periods_count; ++j) {
            if (periods[j] == lines[i].period)
                goto next_no_new_period;
        }
        periods[periods_count++] = lines[i].period;
        next_no_new_period:;
    }
    if (periods_found) {
        memcpy(periods_found, periods, MAX_SUBJECTS_COUNT * sizeof(int));
        return periods_count;
    }
    return 0;
}

typedef struct HardestSubjects {
    Line *subjects[MAX_SUBJECTS_COUNT][MAX_LINES];
    int count[MAX_SUBJECTS_COUNT];
} HardestSubjects;

void point_b_get_hardest_subjects(Line *lines, int lines_count, int *periods, int periods_count, HardestSubjects *hardest) {
    int i, j, hardest_count = 0, worst_percent;
    HardestSubjects hardest_subjects = {0};
    for (i = 0; i < periods_count; ++i) {
        worst_percent = 999;
        for (j = 0; j < lines_count; ++j) {
            if (lines[j].period != periods[i])
                continue;
            if (lines[j].percent_sup < worst_percent) {
                worst_percent = lines[j].percent_sup;
                hardest_subjects.subjects[i][0] = &lines[j];
                hardest_subjects.count[i] = 1;
            } else if (lines[j].percent_sup == worst_percent) {
                hardest_subjects.subjects[i][hardest_subjects.count[i]++] = &lines[j];
            }
        }
    }
    if (hardest)
        memcpy(hardest, &hardest_subjects, sizeof(HardestSubjects));
}

void point_b(Line *lines, int lines_count) {
    int i, j;
    int periods[MAX_SUBJECTS_COUNT], periods_count;
    HardestSubjects hardest_subjects = {0};
    periods_count = point_b_find_periods(lines, lines_count, periods);
    point_b_get_hardest_subjects(lines, lines_count, periods, periods_count, &hardest_subjects);
    for (i = 0; i < MAX_SUBJECTS_COUNT; ++i) {
        for (j = 0; j < hardest_subjects.count[i]; ++j) {
            printf("[periodo: %d] materia piu' difficile: %s\n",
                    hardest_subjects.subjects[i][j]->period, hardest_subjects.subjects[i][j]->subject);
        }
    }
}

void points_c_d(Line *lines, int lines_count) {
    char prof_surname[20];
    int i, credits_sum = 0, percent_sum = 0;
    printf("inserire cognome prof: ");
    scanf("%s", prof_surname);
    for (i = 0; i < lines_count; ++i) {
        if (strcmp(lines[i].prof_surname, prof_surname) == 0) {
            credits_sum += lines[i].credits;
            percent_sum += lines[i].percent_sup;
        }
    }
    printf("somma dei crediti assegnati: %d\n", credits_sum);
    printf("media di superamento degli esami: %d\n", percent_sum / i);
}

// NOTA: il punto b + approfondimento e' fuori dal mondo.
int main(int argc, char **argv) {
    FILE *fd;
    int i;

    int lines_count = 0;
    Line line[MAX_LINES];

    if (argc < 2)
        return 1;

    fd = fopen(argv[1], "r");
    if (!fd)
        return 1;

    for (i = 0; i < MAX_LINES; ++i) {
        if ((fscanf(fd, "%s %s %s %d %d %d",
                    line[i].subject, line[i].prof_name, line[i].prof_surname, &line[i].period, &line[i].credits, &line[i].percent_sup) == EOF)) {
            break;
        }
    }
    lines_count = i;

    point_a(line, lines_count);
    point_b(line, lines_count);
    points_c_d(line, lines_count);

    return 0;
}
