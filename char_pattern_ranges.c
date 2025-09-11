/*
 * Purpose: Reads three characters to define a pattern.
 *          Prints characters from start to row-end for each row,
 *          with columns from start to column-end character.
 * Topic: Character Input, Nested Loops, Character Arithmetic, Pattern Printing
 */

#include <stdio.h>
#include <ctype.h>

// Function to consume leftover newline character in input buffer
void consume_newline() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main(void) {
    printf("Enter pattern parameters in the format: start_char_for_rows, end_char_for_rows, end_char_for_cols\n");
    printf("Example: A, E, G\n");
    
    printf("Enter start_char_for_rows, end_char_for_rows, end_char_for_cols (e.g., A, E, G): ");
    
    // Read start_char_for_rows
    char start_char_for_rows;
    if (scanf(" %c", &start_char_for_rows) != 1) {
        fprintf(stderr, "Invalid input for start_char_for_rows.\n");
        consume_newline();
        return 0;
    }
    // Read end_char_for_rows
    char end_char_for_rows;
    if (scanf(" , %c", &end_char_for_rows) != 1) {
        fprintf(stderr, "Invalid input for end_char_for_rows.\n");
        consume_newline();
        return 0;
    }
    // Read end_char_for_cols
    char end_char_for_cols;
    if (scanf(" , %c", &end_char_for_cols) != 1) {
        fprintf(stderr, "Invalid input for end_char_for_cols.\n");
        consume_newline();
        return 0;
    }
    
    consume_newline(); // Consume remaining newline character

    // Validate character ranges
    if (start_char_for_rows > end_char_for_rows) {
        fprintf(stderr, "start_char_for_rows must be <= end_char_for_rows.\n");
        return 0;
    }
    if (start_char_for_rows > end_char_for_cols) {
        fprintf(stderr, "start_char_for_rows must be <= end_char_for_cols.\n");
        return 0;
    }

    // Generate pattern using nested loops
    for (char current_row_char = start_char_for_rows; current_row_char <= end_char_for_rows; current_row_char++) {
        // Print leading tabs for indentation
        printf("\t\t\t");
        
        // Print characters from current row character to end_char_for_cols
        for (char current_col_char = current_row_char; current_col_char <= end_char_for_cols; current_col_char++) {
            printf(" %c ", current_col_char);
        }
        
        // Fill remaining positions with end_char_for_cols
        for (char fill_char = 0; fill_char < (current_row_char - start_char_for_rows); fill_char++) {
            printf(" %c ", end_char_for_cols);
        }

        printf("\n"); // New line after completing row
    }

    return 0;
}
