/*
### Esercizio ###
Si scriva un programma C che
    a. nel main chieda all’utente di inserire N valori e li metta in un vettore vett, quindi chieda un ulteriore valore x
    b. passi sia il vettore sia x ad una funzione che moltiplichi ciascuno degli elementi del vettore per x e il cui prototipo sia
       void mult(int v[], int n, int x);

Il main poi visualizzi il vettore dopo la moltiplicazione.

Nota bene: la funzione riceve il vettore per riferimento e quindi può modificare i valori stessi del vettore.
*/

#include <stdio.h>

#define N 4

void print_vec(int vec[]) {
    int i;
    for (i = 0; i < N; ++i) {
        printf("vec[%d]: %d\n", i, vec[i]);
    }
}

void mult(int v[], int n, int x) {
    int i;
    for (i = 0; i < n; ++i) {
        v[i] *= x;
    }
}

int main(void) {
    int vett[N];
    int i, x;

    printf("insert %d numbers: ", N);
    for (i = 0; i < N; ++i) {
        scanf("%d", &vett[i]);
    }

    printf("insert x: ");
    scanf("%d", &x);

    mult(vett, N, x);

    puts("== vett ==");
    print_vec(vett);

    return 0;
}
