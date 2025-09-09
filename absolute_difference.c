/*
 * Purpose: To continuously read two long integers and print their absolute difference.
 * Topic: Math functions, Loops, Basic I/O
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
    long int x, y, z;

    printf("Enter two long integers (or non-integer to quit):\n");
    while (scanf("%ld %ld", &x, &y) == 2) {
        z = labs(y - x); // Use labs for long integers
        printf("Absolute difference: %ld\n", z);
    }

    return 0;
}
