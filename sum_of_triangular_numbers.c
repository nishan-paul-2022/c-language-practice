/*
 * Purpose: Calculates the sum of the first n triangular numbers.
 * Topic: Loops and Mathematical Series (Triangular Numbers)
 */

#include <stdio.h>

int main(void) {
    int input_number;
    int counter;
    int triangular_number;
    int sum_of_triangular_numbers = 0;

    // Prompt the user for input and validate it.
    printf("Enter a positive integer (n): ");
    if (scanf("%d", &input_number) != 1) {
        printf("Invalid input. Please enter an integer.\n");
        return 0;
    }

    // Ensure the input is positive.
    if (input_number <= 0) {
        printf("Input must be a positive integer.\n");
        return 0;
    }

    // Calculate the sum of the first n triangular numbers.
    // A triangular number T_k is calculated as k * (k + 1) / 2.
    // We sum these T_k values for k from 1 to input_number.
    for (counter = 1; counter <= input_number; counter++) {
        // Calculate the current triangular number.
        triangular_number = counter * (counter + 1) / 2;
        // Add it to the total sum.
        sum_of_triangular_numbers += triangular_number;
    }

    // Print the calculated sum.
    printf("The sum of the first %d triangular numbers is: %d\n", input_number, sum_of_triangular_numbers);

    // Note: The sum of the first n triangular numbers can also be calculated directly
    // using the formula: n * (n + 1) * (n + 2) / 6.
    // For example, for n=3, the triangular numbers are 1, 3, 6. Their sum is 10.
    // Using the formula: 3 * (3 + 1) * (3 + 2) / 6 = 3 * 4 * 5 / 6 = 60 / 6 = 10.

    return 0;
}
