/*
 * Purpose: Calculates the sum of natural numbers from 1 up to a given integer 'n' using a recursive function.
 * Topic: Recursion, Arithmetic Operations
 */

#include <stdio.h> // Required for printf and scanf

// Recursive function to calculate the sum of natural numbers
// n: the upper limit of the natural numbers to sum
int calculate_sum_recursive(int n) {
    // Base case: if n is 0, the sum is 0
    if (n == 0) {
        return 0;
    }
    // Recursive step: n + sum_of_natural_numbers(n-1)
    else {
        return n + calculate_sum_recursive(n - 1);
    }
}

int main() {
    int input_number; // The number up to which to calculate the sum
    int sum_result;   // Stores the calculated sum

    // Prompt user for input
    printf("Enter a non-negative integer to calculate the sum of natural numbers up to it: ");
    scanf("%d", &input_number);

    // Validate input: sum is typically defined for non-negative integers
    if (input_number < 0) {
        printf("Error: Input must be a non-negative integer.\n");
        return 1; // Indicate an error
    }

    // Call the recursive function to calculate the sum
    sum_result = calculate_sum_recursive(input_number);

    // Print the calculated result
    printf("The sum of natural numbers up to %d is: %d\n", input_number, sum_result);

    return 0;
}
