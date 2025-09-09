// Purpose: Prints a diamond pattern using characters.
// Topic: Nested Loops, Diamond Patterns, Character Manipulation

#include <stdio.h>
#include <stdlib.h> // For EXIT_SUCCESS

int main(void) {
    int size;
    char fill_char;

    // Prompt user for input
    printf("Enter the size of the diamond (number of rows in the upper half): ");
    // Input validation for size
    if (scanf("%d", &size) != 1 || size <= 0) {
        fprintf(stderr, "Error: Invalid input for size. Please enter a positive integer.\\n");
        return EXIT_FAILURE;
    }

    printf("Enter the character to use for the diamond: ");
    // Consume the newline character left by scanf for the integer input
    while (getchar() != '\n'); 
    // Input validation for fill character
    if (scanf("%c", &fill_char) != 1) {
        fprintf(stderr, "Error: Invalid input for fill character.\\n");
        return EXIT_FAILURE;
    }

    // Print the upper half of the diamond
    for (int row = 1; row <= size; row++) {
        // Print leading spaces
        for (int col = 1; col <= size - row; col++) {
            printf(" ");
        }
        // Print characters
        for (int col = 1; col <= row; col++) {
            printf(" %c", fill_char); // Print character with a leading space
        }
        printf("\n"); // Move to the next line
    }

    // Print the lower half of the diamond (inverted triangle)
    for (int row = size - 1; row >= 1; row--) {
        // Print leading spaces
        for (int col = 1; col <= size - row; col++) {
            printf(" ");
        }
        // Print characters
        for (int col = 1; col <= row; col++) {
            printf(" %c", fill_char); // Print character with a leading space
        }
        printf("\n"); // Move to the next line
    }

    return EXIT_SUCCESS;
}
