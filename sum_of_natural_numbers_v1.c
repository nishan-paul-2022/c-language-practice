/*
 * Purpose: Calculates the sum of natural numbers from 1 up to a given integer 'n' using an iterative while loop.
 * Topic: Loops, Arithmetic Operations
 */

#include <stdio.h>

int read_non_negative_int(const char *prompt) {
    int n;

    printf("%s", prompt);

    if (scanf("%d", &n) != 1) {
        printf("Invalid input. Please enter an integer.\n");
        return -1;
    }

    if (n < 0) {
        printf("Input must be a non-negative integer.\n");
        return -1;
    }

    return n;
}

int sum_natural_numbers_iterative(int n) {
    int sum = 0;

    while (n > 0) {
        sum += n;
        n--;
    }
    
    return sum;
}

int main(void) {
    int n = read_non_negative_int("Enter a non-negative integer to calculate the sum of natural numbers up to it: ");
    if (n == -1) {
        return 0;
    }

    int sum = sum_natural_numbers_iterative(n);

    printf("The sum of natural numbers up to %d is: %d\n", n, sum);

    return 0;
}
