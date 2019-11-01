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