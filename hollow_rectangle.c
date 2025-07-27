// Purpose: Prints a hollow rectangle pattern using a specified number.
// Topic: Nested Loops, Rectangle Patterns

#include <stdio.h>
#include <stdlib.h> // For EXIT_SUCCESS

int main(void) {
    int num_rows;
    int num_cols;
    int fill_number;

    // Prompt user for input
    printf("Enter the number of rows: ");
    // Input validation for number of rows
    if (scanf("%d", &num_rows) != 1 || num_rows <= 0) {
        fprintf(stderr, "Error: Invalid input for number of rows. Please enter a positive integer.\\n");
        return EXIT_FAILURE; // Indicate failure
    }

    printf("Enter the number of columns: ");
    // Input validation for number of columns
    if (scanf("%d", &num_cols) != 1 || num_cols <= 0) {
        fprintf(stderr, "Error: Invalid input for number of columns. Please enter a positive integer.\\n");
        return EXIT_FAILURE; // Indicate failure
    }

    printf("Enter the number to fill the rectangle with: ");
    // Input validation for fill number
    if (scanf("%d", &fill_number) != 1) {
        fprintf(stderr, "Error: Invalid input for fill number.\\n");
        return EXIT_FAILURE; // Indicate failure
    }

    // Print the hollow rectangle
    for (int row = 1; row <= num_rows; row++) {
        for (int col = 1; col <= num_cols; col++) {
            // Print the fill number for the border rows/columns
            if (row == 1 || row == num_rows || col == 1 || col == num_cols) {
                printf("%d ", fill_number);
            } else {
                // Print spaces for the inside of the rectangle
                printf("  "); // Two spaces to match the width of "%d "
            }
        }
        printf("\n"); // Move to the next line after printing a row
    }

    return EXIT_SUCCESS; // Indicate successful execution
}
