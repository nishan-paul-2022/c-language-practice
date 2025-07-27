#include <stdio.h>

// Purpose: Calculates the sum of the first n natural numbers using recursion.
// Topic: Recursion, Functions, Input/Output
int sum_natural_numbers_recursive(int n) {
    // Base case: If n is 0, the sum is 0.
    if (n == 0) {
        return 0;
    } 
    // Recursive step: Sum is n plus the sum of the first (n-1) natural numbers.
    else {
        // Ensure n is positive for this calculation, though the original code didn't explicitly handle negative n.
        // If n is negative, this would lead to infinite recursion.
        if (n < 0) {
            // In a real-world scenario, we'd handle this error.
            // For this task, we'll assume valid non-negative input based on typical use cases.
            // If we were to handle it, we might return an error code or a specific value.
            // For now, let's proceed assuming n >= 0.
            return 0; // Or handle error appropriately
        }
        return n + sum_natural_numbers_recursive(n - 1);
    }
}

int main(void) {
    int n; // The number up to which to sum
    int result_sum; // The calculated sum
    int input_status;

    // Prompt user for input
    printf("Enter a non-negative integer (n) to calculate the sum of the first n natural numbers: ");
    
    // Read input and validate
    input_status = scanf("%d", &n);

    if (input_status != 1) {
        printf("Invalid input. Please enter an integer.\n");
        return 1; // Indicate an error
    }

    // Check for negative input, which would cause infinite recursion
    if (n < 0) {
        printf("Input must be a non-negative integer.\n");
        return 1; // Indicate an error
    }

    // Calculate the sum using the recursive function
    result_sum = sum_natural_numbers_recursive(n);

    // Print the result
    printf("The sum of the first %d natural numbers is: %d\n", n, result_sum);

    return 0; // Indicate successful execution
}
