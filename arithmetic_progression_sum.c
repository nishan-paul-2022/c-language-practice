/*
 * Purpose: Calculates the sum of the first 'n' terms of an arithmetic progression.
 *          The progression starts at 2 and has a common difference of 4.
 * Topic: Arithmetic Progression, Loops, Summation, Input/Output
 */

#include <stdio.h>

int main(void) {
    int num_terms;
    long int current_term = 2; // First term
    long int total_sum = 0; // Running sum

    // Validate input
    printf("Enter the number of terms for the arithmetic progression (starting with 2, difference of 4): ");
    if (scanf("%d", &num_terms) != 1) {
        printf("Invalid input. Please enter an integer for the number of terms.\n");
        return 0;
    }

    // Check for negative terms
    if (num_terms < 0) {
        printf("Number of terms cannot be negative.\n");
        return 0;
    }

    // Calculate sum using iterative approach
    for (int i = 0; i < num_terms; i++) {
        total_sum += current_term; // Add term to sum
        current_term += 4; // Next term
    }

    printf("The sum of the first %d terms is %ld\n", num_terms, total_sum);

    return 0;
}
