/*
### Esercizio ###
Si scriva un programma C che acquisisca caratteri da tastiera fino alla ricezione di un “a capo”.

Dopo tale evento il programma deve fornire all’utente le seguenti statistiche:
    a. il numero di caratteri introdotti;
    b. il numero di caratteri alfabetici;
    c. il numero di caratteri maiuscoli;
    d. il numero di cifre decimali;
    e. il numero di caratteri di spaziatura;
    f. Il numero di parole digitate, dove per parola si intende una sequenza di caratteri alfabetici contigui
       (“ciao 123 mondo !” dà 2 parole).

Suggerimento: Si utilizzino le funzioni della libreria standard dichiarate nell’header file <ctype.h> e si utilizzi una
singola variabile di tipo carattere per l’acquisizione.
*/

#include <stdio.h>
#include <ctype.h>

int main(void) {
    char c;
    int count = 0, alpha_count = 0, upper_count = 0, nums_count = 0,
        spaces_count = 0, words_count = 0;

    int is_last_alpha = 0;

    puts("insert sentence(s):");
    while ((c = getchar()) != '\n') {
        ++count;
        if (isspace(c)) {
            ++spaces_count;
            if (is_last_alpha) {
                ++words_count;
                is_last_alpha = 0;
            }
            continue;
        }
        if (isalpha(c)) {
            is_last_alpha = 1;
            ++alpha_count;
            if (isupper(c)) {
                ++upper_count;
            }
            continue;
        }
        if (isdigit(c)) {
            ++nums_count;
            continue;
        }
    }
    if (alpha_count != 0)
        ++words_count;

    printf("chars count  : %d\n", count);
    printf("alphas count : %d\n", alpha_count);
    printf("uppers count : %d\n", upper_count);
    printf("digits count : %d\n", nums_count);
    printf("spaces count : %d\n", spaces_count);
    printf("words count  : %d\n", words_count);

    return 0;
}
