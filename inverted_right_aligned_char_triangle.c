/*
 * Purpose: Prints an inverted right-aligned triangle pattern using characters.
 * Topic: Nested Loops, Character Manipulation, Spacing
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int num_rows;
    char start_char;
    int space_count = 1; // Number of leading spaces

    // Prompt user for input
    printf("Enter the number of rows: ");
    // Validate number of rows input
    if (scanf("%d", &num_rows) != 1 || num_rows <= 0) {
        fprintf(stderr, "Error: Invalid input for number of rows. Please enter a positive integer.\n");
        return EXIT_FAILURE;
    }

    printf("Enter the starting character: ");
    // Consume newline character left by scanf for integer input
    while (getchar() != '\n');
    // Validate starting character input
    if (scanf("%c", &start_char) != 1) {
        fprintf(stderr, "Error: Invalid input for starting character.\n");
        return EXIT_FAILURE;
    }

    // Print inverted triangle pattern
    for (int row = num_rows; row >= 1; row--) {
        // Print leading spaces for right alignment
        for (int space_col = 1; space_col <= space_count; space_col++) {
            printf(" "); // Print single space
        }

        // Print characters for current row
        char current_char = start_char;
        for (int col = 1; col <= row; col++) {
            printf("%c", current_char); // Print character
            current_char++; // Move to next character
        }
        
        printf("\n"); // Move to next line
        space_count++; // Increment space count for next row
    }

    return EXIT_SUCCESS;
}
