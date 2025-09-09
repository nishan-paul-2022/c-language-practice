/*
 * Purpose: Reads two integers (rows, columns) and prints a rectangle where each cell contains the current row number.
 * Topic: Nested Loops, Integer Output, Input Handling, Pattern Printing
 */

#include <stdio.h>
#include <ctype.h> // For isspace, to help clean up input

// Helper function to consume any leftover newline character in the input buffer
void consume_newline() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    int num_rows;           // The number of rows for the rectangle
    int num_cols;           // The number of columns for the rectangle
    int row_index;          // Loop variable for rows
    int col_index;          // Loop variable for columns

    printf("Enter the number of rows: ");
    
    // Read the number of rows and validate input
    if (scanf("%d", &num_rows) != 1) {
        fprintf(stderr, "Error: Invalid input. Please enter an integer for the number of rows.\n");
        consume_newline(); // Clear buffer
        return 0;
    }
    consume_newline(); // Consume the newline character left by scanf

    printf("Enter the number of columns: ");
    // Read the number of columns and validate input
    if (scanf("%d", &num_cols) != 1) {
        fprintf(stderr, "Error: Invalid input. Please enter an integer for the number of columns.\n");
        consume_newline(); // Clear buffer
        return 0;
    }
    consume_newline(); // Consume the newline character left by scanf

    // Validate that the dimensions are positive
    if (num_rows <= 0 || num_cols <= 0) {
        fprintf(stderr, "Error: Number of rows and columns must be positive.\n");
        return 0;
    }

    // Outer loop iterates through each row
    for (row_index = 1; row_index <= num_rows; row_index++) {
        // Inner loop iterates through each column in the current row
        for (col_index = 0; col_index < num_cols; col_index++) {
            // Print the current row number, formatted to align columns
            printf("%4d", row_index);
        }
        printf("\n"); // Move to the next line after completing a row
    }

    return 0;
}
