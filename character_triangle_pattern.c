/*
 * Purpose: Prints a right-aligned triangle pattern using characters.
 * Topic: Nested Loops, Character Manipulation
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int num_rows;
    char start_char;
    char current_char;

    // Get number of rows
    printf("Enter the number of rows: ");
    if (scanf("%d", &num_rows) != 1 || num_rows <= 0) {
        fprintf(stderr, "Error: Invalid input for number of rows. Please enter a positive integer.\n");
        return EXIT_FAILURE;
    }

    // Get starting character
    printf("Enter the starting character: ");
    // Consume newline character left by scanf
    while (getchar() != '\n');
    if (scanf("%c", &start_char) != 1) {
        fprintf(stderr, "Error: Invalid input for starting character.\n");
        return EXIT_FAILURE;
    }

    // Print right-aligned triangle pattern
    for (int row = 1; row <= num_rows; row++) {
        // Print leading spaces for right alignment
        for (int space = 1; space <= num_rows - row; space++) {
            printf("  "); // Two spaces for better character spacing
        }

        current_char = start_char; // Reset character for each row
        // Print characters for current row
        for (int col = 1; col <= row; col++) {
            printf(" %c", current_char); // Print character with leading space
            current_char++; // Move to next character
        }
        printf("\n"); // New line after each row
    }

    return 0;
}
