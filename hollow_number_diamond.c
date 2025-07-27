// Purpose: Prints a hollow diamond pattern using numbers.
// Topic: Nested Loops, Diamond Patterns, Number Sequences, Hollow Patterns

#include <stdio.h>
#include <stdlib.h> // For EXIT_SUCCESS

int main(void) {
    int size;
    int effective_size; // Ensures the pattern works with odd dimensions
    int space_offset; // Controls the number of leading spaces
    int current_number; // The number to print

    // Prompt user for input
    printf("Enter the size of the diamond (number of rows in the upper half): ");
    // Input validation for size
    if (scanf("%d", &size) != 1 || size <= 0) {
        fprintf(stderr, "Error: Invalid input for size. Please enter a positive integer.\\n");
        return EXIT_FAILURE; // Indicate failure
    }

    // Ensure effective_size is odd for proper diamond centering
    effective_size = (size % 2 == 0) ? size - 1 : size;
    if (effective_size <= 0) { // Handle case where input size was 1 and became 0
        effective_size = 1;
    }

    // Print the upper half of the diamond
    space_offset = 1;
    current_number = 1;
    for (int row = 1; row <= effective_size; row += 2) {
        // Print leading spaces
        for (int col = 1; col < space_offset; col++) {
            printf(" ");
        }
        // Print numbers for the diamond's sides
        for (int col = 1; col <= row; col++) {
            if (col == 1 || col == row) {
                printf("%d", current_number); // Print number at the edges
            } else {
                printf(" "); // Print space inside
            }
        }
        space_offset++; // Increase space offset for the next row
        current_number++; // Increment number for the next row
        printf("\n"); // Move to the next line
    }

    // Print the lower half of the diamond (inverted triangle)
    space_offset = (effective_size + 1) / 2; // Reset space offset for the middle row
    current_number = (effective_size + 1) / 2 - 1; // Reset number for the row below the middle
    for (int row = effective_size - 2; row >= 1; row -= 2) {
        // Print leading spaces
        for (int col = 1; col <= space_offset; col++) {
            printf(" ");
        }
        // Print numbers for the diamond's sides
        for (int col = 1; col <= row; col++) {
            if (col == 1 || col == row) {
                printf("%d", current_number); // Print number at the edges
            } else {
                printf(" "); // Print space inside
            }
        }
        space_offset++; // Increase space offset for the next row
        current_number--; // Decrement number for the next row
        printf("\n"); // Move to the next line
    }

    return EXIT_SUCCESS; // Indicate successful execution
}
