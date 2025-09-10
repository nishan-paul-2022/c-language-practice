/*
 * Purpose: Prints a diamond pattern using characters.
* Topic: Nested Loops, Diamond Patterns, Character Manipulation
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int size;
    char fill_char;

    // Get diamond size
    printf("Enter the size of the diamond (number of rows in the upper half): ");
    if (scanf("%d", &size) != 1 || size <= 0) {
        fprintf(stderr, "Error: Invalid input for size. Please enter a positive integer.\n");
        return EXIT_FAILURE;
    }

    // Get fill character
    printf("Enter the character to use for the diamond: ");
    // Consume newline character left by scanf
    while (getchar() != '\n');
    if (scanf("%c", &fill_char) != 1) {
        fprintf(stderr, "Error: Invalid input for fill character.\n");
        return EXIT_FAILURE;
    }

    // Print upper half of diamond
    for (int row = 1; row <= size; row++) {
        // Print leading spaces
        for (int col = 1; col <= size - row; col++) {
            printf(" ");
        }
        // Print characters with leading space
        for (int col = 1; col <= row; col++) {
            printf(" %c", fill_char);
        }
        printf("\n");
    }

    // Print lower half of diamond (inverted triangle)
    for (int row = size - 1; row >= 1; row--) {
        // Print leading spaces
        for (int col = 1; col <= size - row; col++) {
            printf(" ");
        }
        // Print characters with leading space
        for (int col = 1; col <= row; col++) {
            printf(" %c", fill_char);
        }
        printf("\n");
    }

    return EXIT_SUCCESS;
}
