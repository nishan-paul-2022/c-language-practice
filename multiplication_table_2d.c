/*
 * Purpose: Demonstrates creating and printing a 2D array with values based on row and column indices.
 * Topic: 2D Arrays, Nested Loops, Input/Output
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int rows, cols;

    // Prompt for and read the dimensions of the 2D array
    printf("Enter the number of rows and columns (e.g., 3 4): ");
    if (scanf("%d %d", &rows, &cols) != 2) {
        fprintf(stderr, "Error: Invalid input for dimensions.\n");
        return 0;
    }

    // Consume the newline character left by scanf
    while (getchar() != '\n');

    // Declare a 2D array with Variable Length Arrays (VLA) feature (C99 standard)
    // Note: For very large dimensions, dynamic allocation might be preferred.
    int array_grid[rows][cols];

    printf("\nGenerated Multiplication Table:\n");
    // Populate and print the 2D array
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // Calculate the value for each element: (row_index + 1) * (column_index + 1)
            array_grid[i][j] = (i + 1) * (j + 1);
            // Print the element with formatting for alignment
            printf("%4d", array_grid[i][j]);
        }
        printf("\n"); // Newline after each row
    }

    return 0;
}
