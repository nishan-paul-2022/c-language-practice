#include <stdio.h>

/*
 * Purpose: Generates the Fibonacci sequence up to a specified number of terms using an iterative approach.
 * Topic: Iteration, Sequences, Basic Arithmetic
 */
int main(void) {
    int num_terms;
    long long first_term = 0, second_term = 1; // Use long long for larger Fibonacci numbers
    long long next_term;
    int i;

    // Prompt user for number of terms
    printf("Enter the number of Fibonacci terms to generate: ");
    // Use " %d" to consume leading whitespace, including newlines
    if (scanf(" %d", &num_terms) != 1 || num_terms <= 0) {
        printf("Invalid input. Please enter a positive integer for the number of terms.\n");
        return 0;
    }

    printf("Fibonacci Sequence:\n");

    // Handle first two terms separately
    if (num_terms >= 1) {
        printf("%lld", first_term); // Print first term (0)
    }
    if (num_terms >= 2) {
        printf(", %lld", second_term); // Print second term (1)
    }

    // Generate and print remaining terms
    for (i = 3; i <= num_terms; i++) {
        next_term = first_term + second_term;
        printf(", %lld", next_term);
        first_term = second_term;
        second_term = next_term;
    }
    printf("\n");

    return 0;
}
