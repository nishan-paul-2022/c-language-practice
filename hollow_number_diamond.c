/*
 * Purpose: Prints a hollow diamond pattern using numbers.
 * Topic: Nested Loops, Diamond Patterns, Number Sequences, Hollow Patterns
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int size;
    int effective_size; // Ensures pattern works with odd dimensions
    int space_offset;   // Controls leading spaces
    int current_number; // Number to print

    // Prompt user for diamond size
    printf("Enter the size of the diamond (number of rows in the upper half): ");
    // Validate input
    if (scanf("%d", &size) != 1 || size <= 0) {
        fprintf(stderr, "Error: Invalid input for size. Please enter a positive integer.\n");
        return 0;
    }

    // Ensure effective_size is odd for proper diamond centering
    effective_size = (size % 2 == 0) ? size - 1 : size;
    if (effective_size <= 0) { // Handle case where input size was 1
        effective_size = 1;
    }

    // Print upper half of diamond
    space_offset = 1;
    current_number = 1;
    for (int row = 1; row <= effective_size; row += 2) {
        // Print leading spaces
        for (int col = 1; col < space_offset; col++) {
            printf(" ");
        }
        // Print numbers for diamond's sides
        for (int col = 1; col <= row; col++) {
            if (col == 1 || col == row) {
                printf("%d", current_number); // Print number at edges
            } else {
                printf(" "); // Print space inside
            }
        }
        space_offset++;      // Increase space offset for next row
        current_number++;    // Increment number for next row
        printf("\n");        // Move to next line
    }

    // Print lower half of diamond
    space_offset = (effective_size + 1) / 2;       // Reset space offset for middle row
    current_number = (effective_size + 1) / 2 - 1; // Reset number for row below middle
    for (int row = effective_size - 2; row >= 1; row -= 2) {
        // Print leading spaces
        for (int col = 1; col <= space_offset; col++) {
            printf(" ");
        }
        // Print numbers for diamond's sides
        for (int col = 1; col <= row; col++) {
            if (col == 1 || col == row) {
                printf("%d", current_number); // Print number at edges
            } else {
                printf(" "); // Print space inside
            }
        }
        space_offset++;   // Increase space offset for next row
        current_number--; // Decrement number for next row
        printf("\n");     // Move to next line
    }

    return 0;
}
