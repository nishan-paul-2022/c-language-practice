/*
 * Purpose: Calculates the sum of squares of the first N odd numbers with input validation.
 * Topic: Mathematical Computation and Loop Constructs
 */

#include <stdio.h>

int read_positive_int(const char *prompt) {
    int n;

    printf("%s", prompt);

    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input. Please enter a positive integer.\n");
        return -1;
    }

    return n;
}

long long sum_squares_of_odds(int n) {
    long long sum = 0;

    for (int i = 1; i <= 2 * n - 1; i += 2) {
        sum += (long long)i * i;
    }
    
    return sum;
}

int main(void) {
    int n = read_positive_int("Enter a positive integer N to calculate the sum of squares of the first N odd numbers: ");
    if (n == -1) {
        return 0;
    }

    long long sum = sum_squares_of_odds(n);

    printf("The sum of squares of the first %d odd numbers is: %lld\n", n, sum);

    return 0;
}
