#include <stdio.h>
/*
 * Purpose: Calculates the sum of squares of the first N odd numbers.
 *          The input N determines the upper limit of the odd numbers to be squared and summed.
 * Topic: Iteration, Arithmetic Series, Squares, Input Validation
 */

int main(void) {
    int input_n; // The number provided by the user, determining the range of odd numbers.
    int upper_odd_limit; // The largest odd number to consider (2*input_n - 1).
    long long sum_of_squares = 0; // Use long long to prevent overflow for larger sums.
    int current_odd_number;
    int i;

    // Prompt user for input
    printf("Enter a positive integer N to calculate the sum of squares of the first N odd numbers: ");
    // Use " %d" to consume any leading whitespace, including newlines
    if (scanf(" %d", &input_n) != 1 || input_n <= 0) {
        printf("Invalid input. Please enter a positive integer for N.\n");
        return 0;
    }

    // Calculate the largest odd number to consider.
    // If input_n is 1, we sum 1^2. If input_n is 2, we sum 1^2 + 3^2.
    // The k-th odd number is 2*k - 1. So for N terms, the last odd number is 2*N - 1.
    upper_odd_limit = 2 * input_n - 1;

    // Iterate through odd numbers from 1 up to upper_odd_limit
    // and sum their squares.
    for (current_odd_number = 1; current_odd_number <= upper_odd_limit; current_odd_number += 2) {
        sum_of_squares += (long long)current_odd_number * current_odd_number;
    }

    // Print the result
    printf("The sum of squares of the first %d odd numbers (up to %d) is: %lld\n", input_n, upper_odd_limit, sum_of_squares);

    return 0;
}
