#include <stdio.h>
#include <ctype.h>

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

int main(void) {
    char c1, c2;

    printf("insert 2 characters: ");
    scanf("%c %c", &c1, &c2);

    if (isalpha(c1) && isalpha(c2)) {
        if (c1 == c2)
            puts("chars are the same");
        else
            printf("chars are: %c %c\n", min(c1, c2), max(c1, c2));
    } else {
        if (isdigit(c1) || isdigit(c2))
            puts("at least one is a digit");
        else
            puts("nope");
    }

    return 0;
}