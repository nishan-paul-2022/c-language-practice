/*
 * Purpose: Calculates and prints the average of each column in a 2D integer array.
 * Topic: 2D Arrays, Loops, Averages, Input/Output
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 100
#define MAX_COLS 100

int main(void) {
    int rows, cols; // Matrix dimensions
    int matrix[MAX_ROWS][MAX_COLS]; // 2D integer array
    int i, j;
    double column_sum; // Sum of column elements
    double column_averages[MAX_COLS]; // Column averages

    printf("Enter the number of rows and columns (e.g., 'rows cols' like '3 4'): ");
    // Read and validate matrix dimensions
    if (scanf("%d %d", &rows, &cols) != 2) {
        printf("Invalid input for dimensions. Please enter two integers separated by a space.\n");
        return 0;
    }

    // Validate dimensions are within bounds
    if (rows <= 0 || rows > MAX_ROWS || cols <= 0 || cols > MAX_COLS) {
        printf("Invalid dimensions. Rows and columns must be positive and within limits (max %d x %d).\n", MAX_ROWS, MAX_COLS);
        return 0;
    }

    // Consume newline character left by scanf
    while (getchar() != '\n');

    printf("Enter %d integers for the matrix, row by row:\n", rows * cols);
    // Read matrix elements
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("Enter element matrix[%d][%d]: ", i, j);
            if (scanf("%d", &matrix[i][j]) != 1) {
                printf("Invalid input for element matrix[%d][%d]. Please enter an integer.\n", i, j);
                return 0;
            }
            // Consume newline character left by scanf
            while (getchar() != '\n');
        }
    }

    // Calculate column averages
    for (j = 0; j < cols; j++) { // Iterate through columns
        column_sum = 0.0; // Reset sum for each column
        for (i = 0; i < rows; i++) { // Iterate through rows for current column
            column_sum += matrix[i][j]; // Add element to column sum
        }
        // Calculate average with floating-point division
        column_averages[j] = column_sum / (double)rows;
    }

    printf("\nColumn averages:\n");
    // Print column averages
    for (j = 0; j < cols; j++) {
        printf("%.2lf ", column_averages[j]);
    }
    printf("\n"); // New line for clean output

    return 0;
}
