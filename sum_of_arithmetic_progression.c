/*
 * Purpose: Calculate the sum of the first (n-1) terms of the progression 2, 6, 10, ...
 * Topic: Loops, Arithmetic Progression, Functions
 */

#include <stdio.h>

// Function to compute sum of first (n-1) terms of the progression
long int compute_sum(long int n) {
    long int sum = 0, term = 2;
    for (long int i = 1; i < n; i++) {
        sum += term;
        term += 4; // Common difference
    }
    return sum;
}

int main(void) {
    int test_cases;
    long int n;

    scanf("%d", &test_cases);

    while (test_cases--) {
        scanf("%ld", &n);
        printf("%ld\n", compute_sum(n));
    }

    return 0;
}
