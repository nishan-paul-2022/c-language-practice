/*
 * Purpose: Calculates the sum of the first 'n' terms of an arithmetic progression. 
 *          The progression starts at 2 and has a common difference of 4.
 * Topic: Arithmetic Progression, Loops, Summation, Input/Output
 */

#include <stdio.h>

int main() {
    int num_terms;
    long int current_term = 2; // First term of the progression
    long int total_sum = 0; // Initialize sum

    printf("Enter the number of terms for the arithmetic progression (starting with 2, difference of 4): ");
    // Read the number of terms and validate input
    if (scanf("%d", &num_terms) != 1) {
        printf("Error: Invalid input. Please enter an integer for the number of terms.\n");
        return 1; // Indicate an error
    }

    // Ensure the number of terms is non-negative
    if (num_terms < 0) {
        printf("Error: Number of terms cannot be negative.\n");
        return 1; // Indicate an error
    }

    // Calculate the sum of the arithmetic progression
    // The progression is 2, 6, 10, 14, ...
    // The formula for the sum is S_n = n/2 * [2a + (n-1)d]
    // Here, a = 2, d = 4. So, S_n = n/2 * [4 + (n-1)4] = n/2 * [4 + 4n - 4] = n/2 * [4n] = 2*n^2
    // We will use an iterative approach as in the original code.
    for (int i = 0; i < num_terms; i++) {
        total_sum += current_term; // Add the current term to the sum
        current_term += 4; // Calculate the next term (add common difference)
    }

    printf("The sum of the first %d terms is: %ld\n", num_terms, total_sum);

    return 0; // Indicate successful execution
}
