/*
### Esercizio ###
Si scriva un programma in grado di manipolare gli elementi di un vettore di interi.
Tale programma, dopo aver acquisito il contenuto del vettore, invoca due funzioni:
    a. mediaVett: calcola la media degli elementi del vettore, restituendo tale valore alla funzione chiamante;
    b. superanoLimite: conta il numero di elementi che hanno valore superiore ad un certo limite, restituendolo alla funzione chiamante.

Il programma deve infine visualizzare la media dei valori del vettore e il numero di elementi che superano la media.

Suggerimento: per la funzione mediaVett il prototipo sarà: float mediaVett (int v[], int n);
mentre per la funzione superanoLimite il prototipo sarà:
   int superanoLimite (int v[], int n, float limite);

Approfondimento: si condensino le due funzioni descritte in un’unica funzione che restituisca il valore medio e che
memorizzi nella variabile corrispondente al parametro superiori del prototipo il numero di elementi di valore superiore alla media:
   float oltreMedia(int v[], int n, int *superiori);
*/

#include <stdio.h>

#define N 8

float mediaVett(int vec[], int n) {
    int i, avg = 0;
    for (i = 0; i < n; ++i) {
        avg += vec[i];
    }
    return avg / n;
}

int superanoLimite(int vec[], int n, float limit) {
    int i, count = 0;
    for (i = 0; i < n; ++i) {
        if (vec[i] > (int)limit)
            ++count;
    }
    return count;
}

int main(void) {
    int i, over_count;
    float avg;
    int vec[N];

    printf("insert %d integer(s):\n", N);
    for (i = 0; i < N; ++i) {
        scanf("%d", &vec[i]);
    }

    avg = mediaVett(vec, N);
    over_count = superanoLimite(vec, N, avg);

    printf("average  : %f\n", avg);
    printf("over avg : %d\n", over_count);

    return 0;
}
