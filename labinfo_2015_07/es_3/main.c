#include <stdio.h>
#include <ctype.h>

#define N 512

int main(void) {
    char buff[N];
    char c;
    int count = 0, alpha_count = 0, upper_count = 0, nums_count = 0,
        spaces_count = 0, words_count = 0;

    int is_last_alpha = 0;

    printf("insert sentence(s) max %d characters:\n", N);
    while ((c = getchar()) != '\n') {
        ++count;
        if (isspace(c)) {
            ++spaces_count;
            if (is_last_alpha) {
                ++words_count;
                is_last_alpha = 0;
            }
            continue;
        }
        if (isalpha(c)) {
            is_last_alpha = 1;
            ++alpha_count;
            if (isupper(c)) {
                ++upper_count;
            }
            continue;
        }
        if (isdigit(c)) {
            ++nums_count;
            continue;
        }
    }
    if (alpha_count != 0)
        ++words_count;

    printf("chars count  : %d\n", count);
    printf("alphas count : %d\n", alpha_count);
    printf("uppers count : %d\n", upper_count);
    printf("digits count : %d\n", nums_count);
    printf("spaces count : %d\n", spaces_count);
    printf("words count  : %d\n", words_count);

    return 0;
}