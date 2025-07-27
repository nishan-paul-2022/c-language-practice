/*
 * Purpose: To print a pyramid pattern using asterisks.
 * Topic: Loops, Nested Loops
 */

#include <stdio.h>

int main() {
    int i, j, n;

    printf("ENTER YOUR VALUES: ");
    scanf("%d", &n);

    // Upper part of the pyramid
    for (i = 1; i <= n; i++) {
        for (j = i; j < n; j++) {
            printf(" ");
        }
        for (j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }

    // Lower part of the pyramid
    for (i = n; i >= 1; i--) {
        for (j = i; j <= n; j++) {
            printf(" ");
        }
        for (j = 1; j < i; j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
