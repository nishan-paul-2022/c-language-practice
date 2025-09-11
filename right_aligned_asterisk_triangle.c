/*
 * Purpose: Prints a right-aligned triangle pattern using asterisks with leading spaces.
 * Topic: Nested Loops, Spacing
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int num_rows;
    int space_count_decrement; // Controls the number of leading spaces

    // Prompt user for input
    printf("Enter the number of rows: ");
    // Input validation for number of rows
    if (scanf("%d", &num_rows) != 1 || num_rows <= 0) {
        fprintf(stderr, "Error: Invalid input for number of rows. Please enter a positive integer.\n");
        return EXIT_FAILURE;
    }

    space_count_decrement = num_rows; // Initialize space count for the first row

    // Print the triangle pattern
    for (int row = 1; row <= num_rows; row++) {
        // Print leading spaces for right alignment
        for (int space_col = 1; space_col < space_count_decrement; space_col++) {
            printf(" "); // Print a single space
        }

        // Print asterisks for the current row
        for (int col = 1; col <= row; col++) {
            printf(" *"); // Print asterisk with a leading space
        }
        
        space_count_decrement--; // Decrement space count for the next row
        printf("\n"); // Move to the next line after printing a row
    }

    return 0;
}
