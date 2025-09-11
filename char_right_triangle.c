/*
 * Purpose: Prints a right-angled triangle pattern of characters, starting from 'A'.
 *          The number of rows is determined by user input. Each row prints characters from 'A' up to the current row number.
 * Topic: Nested Loops, Character Arithmetic, Pattern Printing, Input Handling
*/

#include <stdio.h>

int main(void) {
    printf("Enter the number of rows for the character triangle: ");
    
    // Read and validate number of rows
    int num_rows;
    if (scanf("%d", &num_rows) != 1) {
        fprintf(stderr, "Error: Invalid input. Please enter an integer for the number of rows.\n");
        // Clear input buffer
        while (getchar() != '\n');
        return 0;
    }
    
    while (getchar() != '\n'); // Consume newline character left by scanf

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
    for (int row_index = 1; row_index <= num_rows; row_index++) {
        printf("\t\t\t"); // Print leading tabs for indentation
        
        // Print characters for current row
        char current_char = 'A'; // Initialize character for current row to 'A'
        for (int col_index = 1; col_index <= row_index; col_index++) {
            printf(" %c ", current_char);
            current_char++;
        }

        printf("\n"); // New line after completing row
    }

    return 0;
}
