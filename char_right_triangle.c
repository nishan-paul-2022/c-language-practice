/*
 * Purpose: Prints a right-angled triangle pattern of characters, starting from 'A'.
 *          The number of rows is determined by user input. Each row prints characters from 'A' up to the current row number.
 * Topic: Nested Loops, Character Arithmetic, Pattern Printing, Input Handling
*/

#include <stdio.h>

int main() {
    int num_rows;           // Number of rows for triangle pattern
    int row_index;          // Row loop variable
    int col_index;          // Column loop variable
    char current_char;      // Character to print, starts from 'A'

    printf("Enter the number of rows for the character triangle: ");
    
    // Read and validate number of rows
    if (scanf("%d", &num_rows) != 1) {
        fprintf(stderr, "Error: Invalid input. Please enter an integer for the number of rows.\n");
        // Clear input buffer
        while (getchar() != '\n');
        return 0;
    }
    // Consume newline character left by scanf
    while (getchar() != '\n');

    // Validate non-negative rows
    if (num_rows < 0) {
        fprintf(stderr, "Error: Number of rows cannot be negative.\n");
        return 0;
    }
    
    // Handle zero rows case
    if (num_rows == 0) {
        printf("No rows to display.\n");
        return 0;
    }

    // Print triangle pattern with nested loops
    for (row_index = 1; row_index <= num_rows; row_index++) {
        // Print leading tabs for indentation
        printf("\t\t\t");
        
        // Initialize character for current row to 'A'
        current_char = 'A';
        
        // Print characters for current row
        for (col_index = 1; col_index <= row_index; col_index++) {
            // Print current character
            printf(" %c ", current_char);
            // Increment character for next position
            current_char++;
        }
        printf("\n"); // New line after completing row
    }

    return 0;
}
