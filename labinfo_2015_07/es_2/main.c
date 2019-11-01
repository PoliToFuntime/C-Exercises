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