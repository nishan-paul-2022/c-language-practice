/*
 * Purpose: Calculates the sum of the first N natural numbers using recursion.
 * Topic: Recursion, Function Definition, Input Handling
 */

#include <stdio.h>

int sum_natural_numbers(int n) {
    if (n == 0) {
        return 0; // base case
    } else {
        return n + sum_natural_numbers(n - 1); // recursive step
    }
}

int read_non_negative_int(const char *prompt) {
    int n;
    printf("%s", prompt);
    if (scanf("%d", &n) != 1) {
        fprintf(stderr, "Invalid input. Please enter an integer.\n");
        return -1;
    }
    if (n < 0) {
        fprintf(stderr, "Please enter a non-negative integer.\n");
        return -1;
    }
    return n;
}

int main(void) {
    int n = read_non_negative_int("Enter a non-negative integer to calculate the sum: ");
    if (n == -1) {
        return 0;
    }

    int sum = sum_natural_numbers(n);
    printf("The sum of the first %d natural numbers is: %d\n", n, sum);

    return 0;
}
