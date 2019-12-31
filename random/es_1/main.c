/*
### Esercizio ###
Si scriva un programma C che
        a. nel main chieda all’utente di inserire N valori e li metta in un vettore vett, quindi chieda un ulteriore valore x
        b. passi sia il vettore sia x ad una funzione che moltiplichi ciascuno degli elementi del vettore per x e il cui
           prototipo sia void mult(int v[], int n, int x);

Il main poi visualizzi il vettore dopo la moltiplicazione.

Nota bene: la funzione riceve il vettore per riferimento e quindi può modificare i valori stessi del vettore.
*/

#include <stdio.h>
#include <math.h>

#define N 3

int power(int base, int exponent) {
    return (int)pow(base, exponent);
}

int main(void) {
    int vbase[N], vexponent[N], vris[N];
    int i;

    printf("Il vettore vbase contiene i seguenti elementi:\n");
    for (i = 0; i < N; i++) {
        scanf("%d", &vbase[i]);
        printf("vbase[%d] = %d\n", i, vbase[i]);
    }

    printf("Il vettore vexponent contiene i seguenti elementi:\n");
    for (i = 0; i < N; i++) {
        scanf("%d", &vexponent[i]);
        printf("vexponent[%d] = %d\n", i, vexponent[i]);
    }

    for (i = 0; i < N; i++) {
        vris[i] = power(vbase[i], vexponent[i]);
        printf("vris[%d] e': %d\n", i, vris[i]);
    }

    return 0;
}

