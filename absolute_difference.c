/*
 * Purpose: Reads two long integers and print their absolute difference.
 * Topic: Math functions, Loops, Basic I/O
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    long int x, y;

    printf("Enter two long integers (Ctrl+D to exit):\n");
    while (scanf("%ld %ld", &x, &y) == 2) {
        long int z = labs(y - x); 
        printf("Absolute difference: %ld\n", z);
    }

    return 0;
}
