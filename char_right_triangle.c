/*
 * Purpose: Prints a right-angled triangle pattern of characters, starting from 'A'.
 *          The number of rows is determined by user input. Each row prints characters from 'A' up to the current row number.
 * Topic: Nested Loops, Character Arithmetic, Pattern Printing, Input Handling
 */

#include <stdio.h>

int main() {
    int num_rows;           // The number of rows for the triangle pattern
    int row_index;          // Loop variable for rows
    int col_index;          // Loop variable for columns
    char current_char;      // The character to print, starting from 'A' and incrementing

    printf("Enter the number of rows for the character triangle: ");
    
    // Read the number of rows and validate input
    if (scanf("%d", &num_rows) != 1) {
        fprintf(stderr, "Error: Invalid input. Please enter an integer for the number of rows.\n");
        // Clear the input buffer
        while (getchar() != '\n');
        return 0;
    }
    // Consume the newline character left by scanf
    while (getchar() != '\n');

    // Validate that the number of rows is non-negative
    if (num_rows < 0) {
        fprintf(stderr, "Error: Number of rows cannot be negative.\n");
        return 0;
    }
    
    // If num_rows is 0, print nothing or a message. For this task, we'll just exit.
    if (num_rows == 0) {
        printf("No rows to display.\n");
        return 0;
    }

    // Outer loop iterates through each row of the triangle
    // row_index goes from 1 up to num_rows
    for (row_index = 1; row_index <= num_rows; row_index++) {
        // Print leading tabs for indentation
        printf("\t\t\t");
        
        // Initialize the character for the current row to 'A'
        current_char = 'A';
        
        // Inner loop iterates through each column in the current row
        // col_index goes from 1 up to the current row_index
        for (col_index = 1; col_index <= row_index; col_index++) {
            // Print the current character
            printf(" %c ", current_char);
            // Increment the character for the next position in the row
            current_char++;
        }
        printf("\n"); // Move to the next line after completing a row
    }

    return 0;
}
