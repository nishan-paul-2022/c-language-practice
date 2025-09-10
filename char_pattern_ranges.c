/*
 * Purpose: Reads three characters to define a pattern.
 *          It prints characters from the start character up to the row-end character for each row,
 *          and repeats this for the number of columns determined by 'A' up to the column-end character.
* Topic: Character Input, Nested Loops, Character Arithmetic, Pattern Printing, Input Handling
 */

#include <stdio.h>
#include <ctype.h>

// Helper function to consume leftover newline character in input buffer
void consume_newline() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    char start_char_for_rows; // Starting character for rows
    char end_char_for_rows;   // Ending character for rows
    char end_char_for_cols;   // Ending character for columns
    char current_row_char;    // Character to print in current row
    char current_col_char;    // Loop variable for columns

    printf("Enter pattern parameters in the format: START_CHAR, ROW_END_CHAR, COLUMN_END_CHAR\n");
    printf("Example: A, E, G\n");
    
    printf("Enter START_CHAR, ROW_END_CHAR, COLUMN_END_CHAR (e.g., A, E, G): ");
    
    // Read three characters with scanf and spaces to consume leading whitespace
    if (scanf(" %c", &start_char_for_rows) != 1) {
        fprintf(stderr, "Error: Invalid input for START_CHAR.\n");
        consume_newline();
        return 0;
    }
    // Consume comma and whitespace after first character
    if (scanf(" , %c", &end_char_for_rows) != 1) {
        fprintf(stderr, "Error: Invalid input for ROW_END_CHAR.\n");
        consume_newline();
        return 0;
    }
    // Consume comma and whitespace after second character
    if (scanf(" , %c", &end_char_for_cols) != 1) {
        fprintf(stderr, "Error: Invalid input for COLUMN_END_CHAR.\n");
        consume_newline();
        return 0;
    }
    consume_newline(); // Consume remaining newline character

    // Validate character ranges
    if (start_char_for_rows > end_char_for_rows) {
        fprintf(stderr, "Error: START_CHAR must be less than or equal to ROW_END_CHAR.\n");
        return 0;
    }
    if ('A' > end_char_for_cols) { // Columns start from 'A'
        fprintf(stderr, "Error: COLUMN_END_CHAR must be 'A' or later.\n");
        return 0;
    }

    // Print pattern with nested loops
    for (current_row_char = start_char_for_rows; current_row_char <= end_char_for_rows; current_row_char++) {
        // Print leading tabs for indentation
        printf("\t\t\t");
        
        // Print columns from 'A' to end_char_for_cols
        for (current_col_char = 'A'; current_col_char <= end_char_for_cols; current_col_char++) {
            // Print character for current row
            printf(" %c ", current_row_char);
        }
        printf("\n"); // New line after completing row
    }

    return 0;
}
