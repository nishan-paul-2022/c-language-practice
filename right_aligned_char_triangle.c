/*
 * Purpose: Prints a right-aligned triangle pattern using characters with leading spaces.
 * Topic: Nested Loops, Character Manipulation, Spacing
 */

#include <stdio.h>
#include <stdlib.h> // For EXIT_SUCCESS

int main(void) {
    int num_rows;
    char start_char;
    char current_char;
    int space_count_decrement = 1; // Controls the number of leading spaces

    // Prompt user for input
    printf("Enter the number of rows: ");
    // Input validation for number of rows
    if (scanf("%d", &num_rows) != 1 || num_rows <= 0) {
        fprintf(stderr, "Error: Invalid input for number of rows. Please enter a positive integer.\\n");
        return EXIT_FAILURE;
    }

    printf("Enter the starting character: ");
    // Consume the newline character left by scanf for the integer input
    while (getchar() != '\n'); 
    // Input validation for starting character
    if (scanf("%c", &start_char) != 1) {
        fprintf(stderr, "Error: Invalid input for starting character.\\n");
        return EXIT_FAILURE;
    }

    // Print the triangle pattern
    for (int row = 1; row <= num_rows; row++) {
        // Print leading spaces for right alignment
        for (int space_col = 1; space_col <= num_rows - space_count_decrement; space_col++) {
            printf(" "); // Print a single space
        }

        current_char = start_char; // Reset character for each row
        // Print characters for the current row
        for (int col = 1; col <= row; col++) {
            printf("%c", current_char); // Print character
            current_char++; // Move to the next character
        }
        printf("\n"); // Move to the next line after printing a row
        space_count_decrement++; // Increment for the next row's spacing
    }

    return EXIT_SUCCESS;
}
