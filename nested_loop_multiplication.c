// Purpose: Demonstrates nested loops to generate a pattern of numbers
//          based on row and column indices, and calculates their sum.
// Topic: Nested Loops and Pattern Generation with Multiplication

#include <stdio.h>

int main() {
    int input_limit;
    int row;
    int column;
    int current_value;
    int total_sum = 0;

    // Prompt the user for input and validate it.
    printf("Enter a positive integer (determines the number of rows): ");
    if (scanf("%d", &input_limit) != 1) {
        printf("Invalid input. Please enter an integer.\n");
        return 1; // Indicate an error
    }

    // Ensure the input is positive.
    if (input_limit <= 0) {
        printf("Input must be a positive integer.\n");
        return 1;
    }

    printf("Pattern:\n");

    // Outer loop controls the number of rows.
    for (row = 1; row <= input_limit; row++) {
        // Inner loop controls the number of elements in each row.
        // Each row 'row' has 'row' number of elements.
        for (column = 1; column <= row; column++) {
            // Calculate the value for the current cell: row * column.
            current_value = row * column;
            // Print the calculated value followed by a space.
            printf("%d ", current_value);
            // Add the current value to the total sum.
            total_sum += current_value;
        }
        // After printing all numbers in a row, move to the next line.
        printf("\n");
    }

    // Print the total sum of all numbers printed in the pattern.
    printf("Sum of all numbers in the pattern: %d\n", total_sum);

    return 0;
}
