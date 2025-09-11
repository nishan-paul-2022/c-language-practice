/*
 * Purpose: Prints a diamond pattern using numbers.
 * Topic: Nested Loops, Diamond Patterns, Number Sequences
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int size;
    int current_number;

    // Prompt user for input
    printf("Enter the size of the diamond (number of rows in the upper half): ");
    // Input validation for size
    if (scanf("%d", &size) != 1 || size <= 0) {
        fprintf(stderr, "Error: Invalid input for size. Please enter a positive integer.\n");
        return 0;
    }

    // Print the upper half of the diamond
    current_number = 1; // Start with 1 for the first row
    for (int row = 1; row <= size; row++) {
        // Print leading spaces
        for (int col = 1; col <= size - row; col++) {
            printf(" ");
        }
        // Print numbers
        for (int col = 1; col <= row; col++) {
            printf(" %d", current_number); // Print number with a leading space
            current_number++; // Increment for the next number
        }
        printf("\n"); // Move to the next line
    }

    // Print the lower half of the diamond (inverted triangle)
    current_number = size - 1; // Start with size-1 for the first row of the lower half
    for (int row = size - 1; row >= 1; row--) {
        // Print leading spaces
        for (int col = 1; col <= size - row; col++) {
            printf(" ");
        }
        // Print numbers
        for (int col = 1; col <= row; col++) {
            printf(" %d", current_number); // Print number with a leading space
            current_number--; // Decrement for the next number
        }
        printf("\n"); // Move to the next line
    }

    return 0;
}
