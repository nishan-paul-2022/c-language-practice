// Purpose: Generates and prints Pascal's triangle up to a specified number of rows using recursion.
// Topic: Recursion, Binomial Coefficients, Nested Loops, Input Handling

#include <stdio.h>
// #include <math.h> // math.h is not needed for this implementation

// Recursive function to calculate the value at a specific position (row, col) in Pascal's triangle.
// This is equivalent to calculating the binomial coefficient C(row-1, col-1).
// The function uses 1-based indexing for row and column as in the original code.
// Base cases:
// - If col is 1 (first element of a row), the value is 1.
// - If col equals row (last element of a row), the value is 1.
// Recursive step: The value is the sum of the two elements directly above it in the previous row.
int calculate_pascal_value(int row, int col) {
    // Validate input: row and col should be positive, and col should not exceed row.
    // Although the main loop handles this, defensive programming is good.
    if (col < 1 || row < 1 || col > row) {
        return 0; // Invalid position, return 0 or handle as error
    }

    // Base cases for Pascal's triangle: edges are always 1.
    if (col == 1 || col == row) {
        return 1;
    }
    
    // Recursive step: C(n, k) = C(n-1, k) + C(n-1, k-1)
    // Here, row corresponds to n and col corresponds to k.
    return calculate_pascal_value(row - 1, col) + calculate_pascal_value(row - 1, col - 1);
}

int main() {
    int num_rows; // The number of rows to print for Pascal's triangle
    int row_index; // Loop variable for rows
    int col_index; // Loop variable for columns

    printf("Enter the number of rows for Pascal's triangle: ");
    
    // Read the number of rows and validate input
    if (scanf("%d", &num_rows) != 1) {
        fprintf(stderr, "Error: Invalid input. Please enter an integer for the number of rows.\n");
        // Clear the input buffer
        while (getchar() != '\n');
        return 1; // Indicate an error
    }

    // Validate that the number of rows is non-negative
    if (num_rows < 0) {
        fprintf(stderr, "Error: Number of rows cannot be negative.\n");
        return 1; // Indicate an error
    }
    
    // If num_rows is 0, print nothing or a message. For this task, we'll just exit.
    if (num_rows == 0) {
        printf("No rows to display.\n");
        return 0;
    }

    // Outer loop iterates through each row of the triangle
    // row_index starts from 1 up to num_rows
    for (row_index = 1; row_index <= num_rows; row_index++) {
        // Inner loop iterates through each element in the current row
        // col_index goes from 1 up to the current row_index
        for (col_index = 1; col_index <= row_index; col_index++) {
            // Calculate and print the Pascal value for the current position
            printf("%d ", calculate_pascal_value(row_index, col_index));
        }
        printf("\n"); // Move to the next line after printing all elements of a row
    }

    return 0; // Indicate successful execution
}
