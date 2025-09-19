/*
 * Purpose: Prints a right-aligned triangle pattern using characters.
 * Topic: Nested Loops, Character Manipulation
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    printf("Enter the number of rows: ");
    int num_rows;
    if (scanf("%d", &num_rows) != 1 || num_rows <= 0) {
        fprintf(stderr, "Invalid input for number of rows. Please enter a positive integer.\n");
        return 0;
    }
    
    while (getchar() != '\n'); // Consume newline character left by scanf

    printf("Enter the starting character: ");
    char start_char;
    if (scanf("%c", &start_char) != 1) {
        fprintf(stderr, "Invalid input for starting character.\n");
        return 0;
    }

    // Print right-aligned triangle pattern
    for (int row = 1; row <= num_rows; row++) {
        // Print leading spaces for right alignment
        for (int space = 1; space <= num_rows - row; space++) {
            printf("  ");
        }

        // Print characters for current row
        char current_char = start_char;
        for (int col = 1; col <= row; col++) {
            printf(" %c", current_char);
            current_char++;
        }

        printf("\n");
    }

    return 0;
}
