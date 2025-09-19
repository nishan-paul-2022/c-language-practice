/*
 * Purpose: Calculate the sum of the first n terms of the progression 2, 6, 10, ...
 * Topic: Loops, Arithmetic Progression, Functions
 */

#include <stdio.h>

int compute_sum(int n) {
    int sum = 0, term = 2;

    for (int i = 1; i <= n; i++) {
        printf("%d ", term);
        sum += term;
        term += 4;
    }

    printf("\n");

    return sum;
}

int main(void) {
    int test_cases;
    printf("Enter the number of test cases: ");
    scanf("%d", &test_cases);

    while (test_cases--) {
        int n;
        printf("\nEnter the number of terms: ");
        scanf("%d", &n);

        int sum = compute_sum(n);
        printf("Sum of the first %d terms: %d\n", n, sum);
    }

    return 0;
}
