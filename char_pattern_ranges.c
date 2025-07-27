// Purpose: Reads three characters to define a pattern.
// It prints characters from the start character up to the row-end character for each row,
// and repeats this for the number of columns determined by 'A' up to the column-end character.
// Topic: Character Input, Nested Loops, Character Arithmetic, Pattern Printing, Input Handling

#include <stdio.h>
#include <ctype.h> // For isspace, to help clean up input

// Helper function to consume any leftover newline character in the input buffer
void consume_newline() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    char start_char_for_rows; // The starting character for the rows
    char end_char_for_rows;   // The ending character for the rows
    char end_char_for_cols;   // The ending character for the columns (determines number of columns)
    char current_row_char;    // The character to print in the current row
    char current_col_char;    // Loop variable for columns

    printf("Enter pattern parameters in the format: START_CHAR, ROW_END_CHAR, COLUMN_END_CHAR\n");
    printf("Example: A, E, G\n");
    
    // Read the three characters with specific format.
    // Using scanf for this specific format, but need to be careful with buffer.
    // The format string " START = %c, ROW = %c, COLUMN = %c" is very specific.
    // Let's try to read them more flexibly and then validate.
    
    printf("Enter START_CHAR, ROW_END_CHAR, COLUMN_END_CHAR (e.g., A, E, G): ");
    
    // Read the three characters. Using scanf with spaces to consume potential leading whitespace.
    if (scanf(" %c", &start_char_for_rows) != 1) {
        fprintf(stderr, "Error: Invalid input for START_CHAR.\n");
        consume_newline();
        return 1;
    }
    // Consume the comma and any whitespace after the first character
    if (scanf(" , %c", &end_char_for_rows) != 1) {
        fprintf(stderr, "Error: Invalid input for ROW_END_CHAR.\n");
        consume_newline();
        return 1;
    }
    // Consume the comma and any whitespace after the second character
    if (scanf(" , %c", &end_char_for_cols) != 1) {
        fprintf(stderr, "Error: Invalid input for COLUMN_END_CHAR.\n");
        consume_newline();
        return 1;
    }
    consume_newline(); // Consume any remaining newline character

    // Validate that the characters define valid ranges
    if (start_char_for_rows > end_char_for_rows) {
        fprintf(stderr, "Error: START_CHAR must be less than or equal to ROW_END_CHAR.\n");
        return 1;
    }
    if ('A' > end_char_for_cols) { // Assuming columns start from 'A'
        fprintf(stderr, "Error: COLUMN_END_CHAR must be 'A' or later.\n");
        return 1;
    }

    // Outer loop iterates through rows, from start_char_for_rows to end_char_for_rows
    for (current_row_char = start_char_for_rows; current_row_char <= end_char_for_rows; current_row_char++) {
        // Print leading tabs for indentation
        printf("\t\t\t");
        
        // Inner loop iterates through columns, from 'A' up to end_char_for_cols
        for (current_col_char = 'A'; current_col_char <= end_char_for_cols; current_col_char++) {
            // Print the character for the current row
            printf(" %c ", current_row_char);
        }
        printf("\n"); // Move to the next line after completing a row
    }

    return 0; // Indicate successful execution
}
