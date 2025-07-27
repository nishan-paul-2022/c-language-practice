/*
 * Purpose: Generates and prints Pascal's triangle up to a specified number of rows.
 * Topic: Pascal's Triangle, Combinatorics
 */

#include <stdio.h>

// Function to calculate binomial coefficients iteratively for Pascal's triangle
// C(n, k) = C(n, k-1) * (n - k + 1) / k
long long calculate_next_coefficient(long long current_coeff, int n, int k) {
    // Ensure k is within bounds and current_coeff is valid
    if (k < 0 || k > n || current_coeff < 0) {
        return -1; // Indicate error or invalid state
    }
    // For k=0, the coefficient is 1. For subsequent terms:
    // C(n, k) = C(n, k-1) * (n - (k-1)) / k
    // C(n, k) = C(n, k-1) * (n - k + 1) / k
    
    // Check for potential overflow before multiplication
    // Using __builtin_mul_overflow for safety, requires GCC/Clang
    long long next_coeff;
    if (__builtin_mul_overflow(current_coeff, (n - k + 1), &next_coeff)) {
        return -2; // Indicate overflow
    }
    return next_coeff / k;
}

int main(void) {
    int num_rows;
    int row_label = 0; // To display row numbers

    // Prompt user for the number of rows
    printf("Enter the number of rows for Pascal's triangle: ");
    
    // Read input
    if (scanf("%d", &num_rows) != 1) {
        printf("Invalid input. Please enter an integer.\n");
        return 1; // Indicate input error
    }

    // Validate input: Pascal's triangle is typically for non-negative rows.
    if (num_rows < 0) {
        printf("Number of rows cannot be negative.\n");
        return 1; // Indicate invalid input
    }

    printf("\n"); // Add a blank line for better formatting

    // Print header for columns
    printf("Row\\Col");
    for (int i = 0; i <= num_rows; ++i) {
        printf("%4d", i); // Print column numbers
    }
    printf("\n");

    // Generate and print Pascal's triangle
    for (int m = 0; m <= num_rows; ++m) { // m represents the current row number (0-indexed)
        long long coefficient = 1; // The first coefficient in any row (C(m, 0)) is 1
        
        printf("%4d ", row_label++); // Print the row label

        // Print coefficients for the current row
        for (int k = 0; k <= m; ++k) { // k represents the element index in the current row
            printf("%4lld", coefficient); // Print the current coefficient

            // Calculate the next coefficient for the next iteration
            // Only calculate if it's not the last element in the row
            if (k < m) {
                coefficient = calculate_next_coefficient(coefficient, m, k + 1);
                if (coefficient < 0) { // Check for errors (invalid input or overflow)
                    if (coefficient == -1) printf(" ERR"); // Invalid state
                    else printf(" OVFL"); // Overflow
                    // Break inner loop if error occurs, but continue to next row if possible
                    break; 
                }
            }
        }
        printf("\n"); // Move to the next line after printing a row
    }

    return 0; // Indicate successful execution
}
