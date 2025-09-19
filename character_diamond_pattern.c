/*
 * Purpose: Prints a diamond pattern using characters.
 * Topic: Nested Loops, Diamond Patterns, Character Manipulation
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    printf("Enter the size of the diamond (number of rows in the upper half): ");
    int size;
    if (scanf("%d", &size) != 1 || size <= 0) {
        fprintf(stderr, "Invalid input for size. Please enter a positive integer.\n");
        return 0;
    }

    printf("Enter the character to use for the diamond: ");
    char fill_char;
    while (getchar() != '\n'); // Consume newline character left by scanf
    if (scanf("%c", &fill_char) != 1) {
        fprintf(stderr, "Invalid input for fill character.\n");
        return 0;
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

    return 0;
}
