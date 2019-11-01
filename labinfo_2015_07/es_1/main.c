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