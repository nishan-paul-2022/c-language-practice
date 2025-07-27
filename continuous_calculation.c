/*
 * Purpose: To continuously read two integers, calculate a value, and print the result.
 * Topic: Loops, Basic I/O
 */

#include <stdio.h>

int main() {
    int v, t, s;

    printf("Enter two integers (or non-integer to quit): \n");
    while (scanf("%d %d", &v, &t) == 2) {
        s = 2 * v * t;
        printf("Result: %d\n", s);
    }

    return 0;
}
