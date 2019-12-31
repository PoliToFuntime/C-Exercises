/*
### Esercizio ###
Si scriva un programma C che:
    a. definisca due variabili di tipo carattere;
    b. ne acquisisca il contenuto da tastiera;
    c. stabilisca se i caratteri sono entrambi alfabetici:

i.  in caso positivo, controlli se sono uguali e, se non lo sono, stampi i due caratteri in ordine alfabetico;
ii. in caso negativo, specifichi tramite messaggio se almeno uno dei caratteri è una cifra.
*/

#include <stdio.h>
#include <ctype.h>

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

int main(void) {
    char c1, c2;

    printf("insert 2 characters: ");
    scanf("%c %c", &c1, &c2);

    if (isalpha(c1) && isalpha(c2)) {
        if (c1 == c2)
            puts("chars are the same");
        else
            printf("chars are: %c %c\n", min(c1, c2), max(c1, c2));
    } else {
        if (isdigit(c1) || isdigit(c2))
            puts("at least one is a digit");
        else
            puts("nope");
    }

    return 0;
}
