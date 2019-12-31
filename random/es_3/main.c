/*
### Esercizio ###
Si scriva un programma C che:
        a. nel main chieda all’utente di inserire N valori e li metta in un vettore vett, quindi chieda un ulteriore valore x
        b. passi sia il vettore sia x ad una funzione che moltiplichi ciascuno degli elementi del vettore per x e il cui prototipo sia
           void mult(int v[], int n, int x);

Il main poi visualizzi il vettore dopo la moltiplicazione.

Nota bene: la funzione riceve il vettore per riferimento e quindi può modificare i valori stessi del vettore.
*/

#include <stdio.h>

#define N 3

void mult(int v[], int n, int x) {
    int i, new_val;
    for (i = 0; i < n; ++i) {
        new_val = v[i] * x;
        printf("(v[%d]: %d) * (x: %d) = %d\n", i, v[i], x, new_val);
        v[i] = new_val;
    }
}

int main(void) {
    int vett[N], x;
    int i;

    printf("insert %d number(s):\n", N);
    for (i = 0; i < N; ++i) {
        scanf("%d", &vett[i]);
    }

    printf("insert x: ");
    scanf("%d", &x);

    mult(vett, N, x);

    return 0;
}
