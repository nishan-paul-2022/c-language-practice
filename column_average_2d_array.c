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
    int matrix[MAX_ROWS][MAX_COLS];
    int i, j;
    double column_sum;
    double column_averages[MAX_COLS]; // Store average for each column

    printf("=== Matrix Column Averages Calculator ===\n");
    printf("Enter the number of rows and columns (e.g., '3 4'): ");
    
    if (scanf("%d %d", &rows, &cols) != 2) {
        printf("Invalid input for dimensions. Please enter two integers.\n");
        return 0;
    }

    if (rows <= 0 || rows > MAX_ROWS || cols <= 0 || cols > MAX_COLS) {
        printf("Dimensions must be positive and within limits (max %d x %d).\n", MAX_ROWS, MAX_COLS);
        return 0;
    }

    while (getchar() != '\n'); // Clear input buffer

    printf("\nEnter %d integers for the matrix, row by row:\n", rows * cols);
    
    // Read matrix elements
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("Enter element at row %d, column %d: ", i + 1, j + 1);
            if (scanf("%d", &matrix[i][j]) != 1) {
                printf("Invalid input at position [%d][%d]. Please enter an integer.\n", i, j);
                return 0;
            }
            while (getchar() != '\n'); // Clear input buffer
        }
    }

    // Calculate average for each column
    for (j = 0; j < cols; j++) {
        column_sum = 0.0;
        for (i = 0; i < rows; i++) {
            column_sum += matrix[i][j];
        }
        column_averages[j] = column_sum / rows;
    }

    printf("\nColumn Averages:\n");
    for (j = 0; j < cols; j++) {
        printf("Column %d: %.2lf\n", j + 1, column_averages[j]);
    }

    return 0;
}
