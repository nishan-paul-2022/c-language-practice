/*
 * Purpose: Calculates the sum of multiples of given divisors up to a specified limit with detailed output.
 * Topic: Mathematical Algorithms and Array Processing
 */

#include <stdio.h>

int sum_of_multiples(int limit, int divisiors[], int n) {
    int sum = 0;

    for (int i = 1; i <= limit; i++) {
        int divisible = 0;
        for (int j = 0; j < n; j++) {
            if (i % divisiors[j] == 0) {
                divisible = 1;
                printf("%d is divisible by %d\n", i, divisiors[j]);
                break;
            }
        }
        if (divisible) {
            sum += i;
        }
    }

    return sum;
}

int main(void) {
    int limit;
    printf("Enter the limit: ");
    scanf("%d", &limit);

    int n;
    printf("Enter the number of divisiors: ");
    scanf("%d", &n);

    int divisiors[n];
    for (int i = 0; i < n; i++) {
        printf("Enter divisor %d: ", i + 1);
        scanf("%d", &divisiors[i]);
    }

    int sum = sum_of_multiples(limit, divisiors, n);

    printf("\nSum of multiples up to %d: %d\n", limit, sum);

    return 0;
}
