/*
 * Purpose: Prints a diamond-like number pattern with leading spaces.
 * Topic: Nested Loops, Number Patterns, Spacing
 */

#include <stdio.h>
#include <stdlib.h> // For EXIT_SUCCESS

int main(void) {
    int num_rows;
    int space_count_decrement; // Controls the number of leading spaces
    int desc_start_num = 0; // Starting number for the descending sequence

    // Prompt user for input
    printf("Enter the number of rows: ");
    // Input validation for number of rows
    if (scanf("%d", &num_rows) != 1 || num_rows <= 0) {
        fprintf(stderr, "Error: Invalid input for number of rows. Please enter a positive integer.\\n");
        return EXIT_FAILURE;
    }

    space_count_decrement = num_rows; // Initialize space count for the first row

    // Print the number pattern
    for (int row = 1; row <= num_rows; row++) {
        // Print leading spaces for right alignment
        for (int space_col = 1; space_col < space_count_decrement; space_col++) {
            printf(" "); // Print a single space
        }

        // Print descending numbers
        int current_desc_num = desc_start_num;
        for (int desc_col = 1; desc_col <= row; desc_col++) {
            printf("%d", current_desc_num); // Print descending number
            current_desc_num--; // Decrement for the next number in sequence
        }

        // Print ascending numbers (starting from 1)
        int asc_start_num = 1;
        for (int asc_col = 1; asc_col < space_count_decrement - 1; asc_col++) {
            printf("%d", asc_start_num); // Print ascending number
            asc_start_num++; // Increment for the next number in sequence
        }
        
        space_count_decrement--; // Decrement space count for the next row
        desc_start_num++; // Increment the starting number for the descending sequence for the next row
        printf("\n"); // Move to the next line after printing a row
    }

    return EXIT_SUCCESS;
}
