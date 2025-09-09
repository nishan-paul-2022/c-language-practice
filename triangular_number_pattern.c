// Purpose: Prints a triangular pattern of sequential numbers and calculates their sum.
// Topic: Nested Loops and Pattern Generation

#include <stdio.h>

int main() {
    int input_limit;
    int row;
    int column;
    int current_number = 0; // Counter for sequential numbers, starting from 0 to be incremented first.
    int total_sum = 0;      // Accumulator for the sum of printed numbers.

    // Prompt the user for input and validate it.
    printf("Enter a positive integer (determines the number of rows in the pattern): ");
    if (scanf("%d", &input_limit) != 1) {
        printf("Invalid input. Please enter an integer.\n");
        return 0;
    }

    // Ensure the input is positive.
    if (input_limit <= 0) {
        printf("Input must be a positive integer.\n");
        return 1;
    }

    printf("Triangular number pattern:\n");

    // Outer loop controls the number of rows.
    for (row = 1; row <= input_limit; row++) {
        // Inner loop controls the number of elements in each row.
        // Each row 'row' has 'row' number of elements.
        for (column = 1; column <= row; column++) {
            // Increment the counter to get the next sequential number.
            current_number++;
            // Print the current number followed by a space.
            printf("%d ", current_number);
            // Add the current number to the total sum.
            total_sum += current_number;
        }
        // After printing all numbers in a row, move to the next line.
        printf("\n");
    }

    // Print the total sum of all numbers printed in the pattern.
    printf("Sum of all numbers in the pattern: %d\n", total_sum);

    return 0;
}
