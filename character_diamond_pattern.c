/*
 * Purpose: Prints a diamond pattern using characters.
 * Topic: Nested Loops, Diamond Patterns, Character Manipulation
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int size;

    printf("Enter the size of the diamond (number of rows in the upper half): ");

    if (scanf("%d", &size) != 1 || size <= 0) {
        fprintf(stderr, "Invalid input for size. Please enter a positive integer.\n");
        return 0;
    }
    while (getchar() != '\n'); 

    char fill_char;
    printf("Enter the character to use for the diamond: ");
    if (scanf("%c", &fill_char) != 1) {
        fprintf(stderr, "Invalid input for fill character.\n");
        return 0;
    }
    
    for (int row = 1; row <= size; row++) {
        for (int col = 1; col <= size - row; col++) {
            printf(" ");
        }
        for (int col = 1; col <= row; col++) {
            printf(" %c", fill_char);
        }
        printf("\n");
    }
    
    for (int row = size - 1; row >= 1; row--) {
        for (int col = 1; col <= size - row; col++) {
            printf(" ");
        }
        for (int col = 1; col <= row; col++) {
            printf(" %c", fill_char);
        }
        printf("\n");
    }

    return 0;
}
