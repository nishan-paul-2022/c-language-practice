/*
 * Purpose: Demonstrates matrix transpose and summing elements of a specified row or column.
 * Topic: 2D Arrays, Matrix Transpose, Loops, Input/Output
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 100 // Maximum number of rows
#define MAX_COLS 100 // Maximum number of columns

int main(void) {
    int rows, cols;
    int row_index_to_sum, col_index_to_sum;
    int sum = 0;

    // Prompt for and read the dimensions of the matrix
    printf("Enter the number of rows and columns (e.g., 3 4): ");
    if (scanf("%d %d", &rows, &cols) != 2) {
        fprintf(stderr, "Error: Invalid input for dimensions.\n");
        return 0;
    }

    // Consume the newline character left by scanf
    while (getchar() != '\n');

    // Validate dimensions
    if (rows <= 0 || rows > MAX_ROWS || cols <= 0 || cols > MAX_COLS) {
        fprintf(stderr, "Error: Dimensions out of range. Rows: 1-%d, Cols: 1-%d\n", MAX_ROWS, MAX_COLS);
        return 0;
    }

    // Declare a 2D array with Variable Length Arrays (VLA) feature (C99 standard)
    // For simplicity, we use fixed-size arrays here, but VLAs are also an option.
    int matrix[MAX_ROWS][MAX_COLS];

    printf("Enter the elements of the %d x %d matrix:\n", rows, cols);
    // Read matrix elements
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            if (scanf("%d", &matrix[i][j]) != 1) {
                fprintf(stderr, "Error: Invalid input for element [%d][%d].\n", i, j);
                return 0;
            }
        }
    }

    // Consume the newline character left by the last scanf
    while (getchar() != '\n');

    printf("\nOriginal Matrix:\n");
    // Print the original matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }

    printf("\nTransposed Matrix:\n");
    // Print the transposed matrix
    for (int j = 0; j < cols; j++) { // Iterate through columns of original matrix
        for (int i = 0; i < rows; i++) { // Iterate through rows of original matrix
            printf("%4d", matrix[i][j]); // Print element at [row][col] as [col][row]
        }
        printf("\n"); // Newline after each row of the transposed matrix
    }

    // Prompt for row or column index to sum
    printf("\nEnter a row index (0 to %d) to sum its elements, or -1 to skip row sum: ", rows - 1);
    scanf("%d", &row_index_to_sum);
    while (getchar() != '\n'); // Consume newline

    if (row_index_to_sum != -1) {
        // Validate row index
        if (row_index_to_sum < 0 || row_index_to_sum >= rows) {
            fprintf(stderr, "Error: Row index out of bounds.\n");
        } else {
            // Sum elements of the specified row
            for (int j = 0; j < cols; j++) {
                sum += matrix[row_index_to_sum][j];
            }
            printf("Sum of elements in row %d: %d\n", row_index_to_sum, sum);
        }
    }

    // Reset sum for column sum calculation
    sum = 0;

    printf("\nEnter a column index (0 to %d) to sum its elements, or -1 to skip column sum: ", cols - 1);
    scanf("%d", &col_index_to_sum);
    while (getchar() != '\n'); // Consume newline

    if (col_index_to_sum != -1) {
        // Validate column index
        if (col_index_to_sum < 0 || col_index_to_sum >= cols) {
            fprintf(stderr, "Error: Column index out of bounds.\n");
        } else {
            // Sum elements of the specified column
            for (int i = 0; i < rows; i++) {
                sum += matrix[i][col_index_to_sum];
            }
            printf("Sum of elements in column %d: %d\n", col_index_to_sum, sum);
        }
    }

    return 0;
}
