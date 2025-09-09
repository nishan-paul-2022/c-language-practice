// Purpose: Finds and prints the first 'n' perfect numbers.
//          A perfect number is a positive integer that is equal to the sum of its proper positive divisors.
// Topic: Number Theory, Loops, Divisibility

#include <stdio.h>

int main() {
    int count_needed; // The number of perfect numbers the user wants to find.
    int current_number_to_check = 6; // Start checking for perfect numbers from 6 (the first perfect number).
    int sum_of_divisors; // Accumulator for the sum of proper divisors of current_number_to_check.
    int divisor; // Loop variable to check for divisors.
    int perfect_numbers_found = 0; // Counter for how many perfect numbers have been found.

    // --- Input Handling ---
    printf("Enter the number of perfect numbers to find: ");
    // Read the desired count and validate it.
    if (scanf("%d", &count_needed) != 1) {
        printf("Invalid input. Please enter an integer.\n");
        return 1; // Indicate an error
    }

    // Ensure the input is positive.
    if (count_needed <= 0) {
        printf("Please enter a positive integer to find perfect numbers.\n");
        return 1;
    }

    printf("The first %d perfect numbers are:\n", count_needed);

    // --- Finding Perfect Numbers ---
    // Loop until the desired number of perfect numbers have been found.
    while (perfect_numbers_found < count_needed) {
        sum_of_divisors = 0; // Reset sum for each new number being checked.

        // Find all proper divisors of current_number_to_check and sum them.
        // We only need to check divisors up to half of the number.
        // Note: For efficiency, we could check up to sqrt(k), but k/2 is simpler and sufficient here.
        for (divisor = 1; divisor <= current_number_to_check / 2; divisor++) {
            // If 'divisor' divides 'current_number_to_check' evenly, it's a proper divisor.
            if (current_number_to_check % divisor == 0) {
                sum_of_divisors += divisor;
            }
        }

        // Check if the sum of proper divisors equals the number itself.
        if (sum_of_divisors == current_number_to_check) {
            // If it is a perfect number, print it.
            printf("%d ", current_number_to_check);
            // Increment the count of perfect numbers found.
            perfect_numbers_found++;
        }

        // Move to the next number to check.
        current_number_to_check++;
    }
    printf("\n"); // Print a newline at the end for better formatting.

    return 0;
}
