/*
 * Purpose: Demonstrates initializing a 2D array and setting specific elements to 1.
 * Topic: 2D arrays, loops, input/output, initialization.
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_DIMENSION 100 // Define a maximum dimension for the square matrix to avoid excessively large VLAs

int main(void) {
    int dimension; // Size of the square matrix (n x n)
    int num_elements_to_set; // Number of elements to set to 1
    int matrix[MAX_DIMENSION][MAX_DIMENSION]; // 2D array
    int row, col;
    int i;

    printf("Enter the dimension of the square matrix (max %d): ", MAX_DIMENSION);
    // Read the dimension of the matrix and validate input
    if (scanf("%d", &dimension) != 1 || dimension <= 0 || dimension > MAX_DIMENSION) {
        printf("Invalid input. Please enter a positive integer for dimension up to %d.\\n", MAX_DIMENSION);
        return 0;
    }

    // Consume the newline character left by scanf
    while (getchar() != '\\n');

    printf("Enter the number of elements to set to 1 (e.g., 5): ");
    // Read the number of elements to set and validate input
    if (scanf("%d", &num_elements_to_set) != 1 || num_elements_to_set < 0) {
        printf("Invalid input. Please enter a non-negative integer for the number of elements.\\n");
        return 0;
    }

    // Consume the newline character left by scanf
    while (getchar() != '\\n');

    // Initialize the entire matrix to 0
    for (row = 0; row < dimension; row++) {
        for (col = 0; col < dimension; col++) {
            matrix[row][col] = 0;
        }
    }

    printf("Enter %d pairs of row and column indices (e.g., 'row col' like '0 1'):\\n", num_elements_to_set);
    // Read the row and column indices and set the corresponding matrix elements to 1
    for (i = 0; i < num_elements_to_set; i++) {
        printf("Enter pair %d: ", i + 1);
        if (scanf("%d %d", &row, &col) != 2) {
            printf("Invalid input for pair %d. Please enter two integers separated by a space.\\n", i + 1);
            // Optionally, you could decide to skip this pair or exit. Exiting for now.
            return 0;
        }

        // Consume the newline character left by scanf
        while (getchar() != '\\n');

        // Validate indices before setting the element
        if (row >= 0 && row < dimension && col >= 0 && col < dimension) {
            matrix[row][col] = 1;
        } else {
            printf("Warning: Indices (%d, %d) are out of bounds for a %d x %d matrix. Skipping.\\n", row, col, dimension, dimension);
        }
    }

    printf("\\nMatrix after setting elements to 1:\\n");
    // Print the modified matrix
    for (row = 0; row < dimension; row++) {
        for (col = 0; col < dimension; col++) {
            printf("%d ", matrix[row][col]);
        }
        printf("\\n"); // Newline after each row
    }

    return 0;
}
