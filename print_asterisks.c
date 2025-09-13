/*
 * Purpose: Prints a user-specified number of asterisks in a single line.
 * Topic: Loops, User Input, Output Formatting
 */

#include <stdio.h>

int main(void) {
    int num_asterisks;

    // Prompt the user
    printf("Enter the number of asterisks to print: ");
    if (scanf("%d", &num_asterisks) != 1 || num_asterisks <= 0) {
        fprintf(stderr, "Invalid input. Please enter a positive integer.\n");
        return 0;
    }

    // Print the asterisks
    for (int i = 0; i < num_asterisks; i++) {
        printf("* ");
    }
    printf("\n");

    return 0;
}
