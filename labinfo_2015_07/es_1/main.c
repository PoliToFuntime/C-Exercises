/*
### Esercizio ###
Si scriva un programma C che, dati due vettori di uguale dimensione N (vbase e vexponent), elevi ciascun elemento del
vettore vbase alla potenza indicata nell’elemento di vexponent avente lo stesso indice (ossia
vbase[i] elevato a vexponent[i]).

I risultati dovranno essere memorizzati
nella corrispondente posizione di un terzo vettore denominato vris. Si utilizzi la
funzione power definita nel corso del precedente laboratorio e avente il seguente prototipo:

   int power(int base, int exponent);

- Vengano inseriti prima i valori delle N basi e poi quelli degli N esponenti;
- vengano alla fine visualizzati i valori di vris.

Esempio:
Siano inseriti dall’utente i valori seguenti (per N pari a 5):
vbase = 5 2 7 4 9
vexponent = 2 6 1 8 3

Il vettore risultato sarà il seguente:
vris = 25 64 7 65536 729

Suggerimento: richiamare tante volte la funzione power quanti sono gli elementi
dei vettori e ogni volta salvare il contenuto in una posizione opportuna di vris.
*/

#include <stdio.h>
#include <math.h>

#define N 8

void fill(int vec[]) {
    int i;
    for (i = 0; i < N; ++i) {
        vec[i] = i;
    }
}

void print_vec(int vec[]) {
    int i;
    for (i = 0; i < N; ++i) {
        printf("vec[%d]: %d\n", i, vec[i]);
    }
}

int power(int base, int exponent) {
    /* perche' sarebbe troppo ezy usare
     * direttamente la libreria eh poli?
     */
    return pow(base, exponent);
}

int main(void) {
    int vbase[N], vexponent[N], vris[N];
    int i;

    /* insert values here */
    fill(vbase);
    fill(vexponent);

    for (i = 0; i < N; ++i) {
        vris[i] = power(vbase[i], vexponent[i]);
    }

    puts("== vbase ==");
    print_vec(vbase);
    puts("== vexponent ==");
    print_vec(vexponent);
    puts("== vris ==");
    print_vec(vris);

    return 0;
}
