/*
### Esercizio ###
Si scriva un programma C che:
        a. legga 2 vettori di N elementi interi (con N costante predefinita)
        b. stabilisca se i due vettori contengono gli stessi elementi, anche disposti in ordine differente

Esempio: siano dati i due vettori seguenti:
v1 = 15  3  12  13  29
v2 = 15  29  13  3  12
questi contengono gli stessi valori, anche se in posizioni differenti.

Invece, i due vettori seguenti:
v1 = 11  3  12  18  29
v2 = 12  29  13  4  12
non contengono gli stessi valori.

## Approfondimento ##

considerare la possibilità che ci siano valori ripetuti tra quelli memorizzati nei vettori. Ad esempio:
v1 = 12  3  12  13  29
v2 = 12  29  13  3  12
contengono gli stessi valori ed il 12 compare 2 volte per vettore.

Invece, i due vettori seguenti:
v1 = 12  3  13  13  29
v2 = 12  29  13  3  12
non contengono gli stessi valori.
*/

#include <stdio.h>
#define N 3

int fill_array(int *vec) {
    int i, j, n, sz = 0;
    for (i = 0; i < N; ++i) {
        scanf("%d", &n);
        for (j = 0; j < sz; ++j) {
            if (vec[j] == n) {
                goto skip;
            }
        }
        vec[sz] = n;
        ++sz;
        skip:;
    }
    return sz;
}

void print_array(int *arr, int sz) {
    int i;
    for (i = 0; i < sz; ++i) {
        printf("vec[%d] = %d\n", i, arr[i]);
    }
}

void check(const int *min_arr, int min_sz, const int *maj_arr, int maj_sz) {
    int i, j, found;
    for (i = 0; i < maj_sz; ++i) {
	    found = 0;
        for (j = 0; j < min_sz; ++j) {
			if (maj_arr[i] == min_arr[j]) {
			    found = 1;
                break;
			}
		}
        if (!found) {
            printf("numeri diversi");
            return;
        }
	}
    printf("Stessi numeri");
}

int main(void) {
	int v1[N], v2[N], sz1, sz2;

	sz1 = fill_array(v1);
	sz2 = fill_array(v2);

	print_array(v1, sz1);
	print_array(v2, sz2);

	if (sz1 < sz2) {
	    check(v1, sz1, v2, sz2);
	} else {
	    check(v2, sz2, v1, sz1);
	}

	return 0;
}
