/*
 * Purpose: To generate the 3n+1 sequence (Collatz conjecture) for a given number.
 * Topic: Recursion, Conditional Statements
 */

#include <stdio.h>

void collatz_sequence(int n) {
    printf("%d ", n);
    if (n == 1) {
        return;
    }
    if (n % 2) {
        collatz_sequence(3 * n + 1);
    } else {
        collatz_sequence(n / 2);
    }
}

int main() {
    int n;
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    collatz_sequence(n);
    printf("\n");
    return 0;
}
