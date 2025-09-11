/*
 * Purpose: Prints a pyramid pattern using asterisks.
 * Topic: Nested Loops, Star Patterns
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int total_rows = 10; // Fixed number of rows for the pattern

    // Print the star pyramid pattern
    for (int row = 1; row <= total_rows; row++) {
        int stars_to_print;

        // Determine the number of stars based on the row number
        if (row <= (total_rows + 1) / 2) {
            // For the upper half, print 'row' number of stars
            stars_to_print = row;
        } else {
            // For the lower half, print stars in decreasing order
            stars_to_print = total_rows - row + 1;
        }

        // Print leading spaces for alignment (optional, but common for pyramids)
        // For a centered pyramid, spaces would be (total_rows - stars_to_print) / 2
        // For a right-aligned pyramid, spaces would be total_rows - stars_to_print
        // Let's aim for a simple right-aligned pyramid for now.
        for (int space_col = 1; space_col <= total_rows - stars_to_print; space_col++) {
            printf(" ");
        }

        // Print the asterisks
        for (int col = 1; col <= stars_to_print; col++) {
            printf("*");
        }
        printf("\n"); // Move to the next line
    }

    return 0;
}
