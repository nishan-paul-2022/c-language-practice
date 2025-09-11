/*
 * Purpose: Calculates and displays powers of 2 and their reciprocals for a given number of iterations using the pow() function.
 * Topic: Loops, Math Functions, Powers
 */

#include <stdio.h>
#include <math.h>

int main(void) {
    int num_iterations; // Number of iterations to perform
    int i;
    int power_of_two;    // Stores 2 raised to the power of i
    double reciprocal_power_of_two; // Stores 2 raised to the power of -i (1 / 2^i)

    // Prompt user for the number of iterations
    printf("Enter the number of iterations: ");

    // Read the number of iterations and validate input
    if (scanf("%d", &num_iterations) != 1 || num_iterations <= 0) {
        fprintf(stderr, "Invalid input. Please enter a positive integer for the number of iterations.\n");
        return 0;
    }

    // Consume the newline character left by scanf after reading num_iterations
    while (getchar() != '\n');

    printf("\n--- Power Calculations ---\n");
    printf("Power of 2 | Iteration | Reciprocal Power of 2\n");
    printf("---------------------------------------------\n");

    // Loop to calculate and print powers of 2 and their reciprocals
    for (i = 1; i <= num_iterations; i++) {
        // Calculate 2 raised to the power of i
        power_of_two = (int)pow(2, i); // Cast to int as the result is expected to be an integer

        // Calculate 2 raised to the power of -i (which is 1 / 2^i)
        reciprocal_power_of_two = pow(2, -i);

        // Print the results, formatted as requested
        // %d for integer, %3.5lf for double with specific formatting
        printf("%-10d | %-9d | %10.5lf\n", power_of_two, i, reciprocal_power_of_two);
    }
    printf("\n");

    return 0;
}
