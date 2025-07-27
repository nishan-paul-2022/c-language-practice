#include <stdio.h>

// Purpose: Calculates the sum of the main diagonal and anti-diagonal of a square matrix.
// Topic: Arrays, 2D Arrays, Matrix Operations

int main() {
    int matrix_size;
    int matrix[100][100]; // Assuming a maximum size of 100x100 for simplicity.
                          // For dynamic sizing, malloc would be needed.
    int main_diagonal_sum = 0;
    int anti_diagonal_sum = 0;
    int i, j;

    // Prompt user for the size of the square matrix
    printf("Enter the size of the square matrix: ");
    if (scanf("%d", &matrix_size) != 1 || matrix_size <= 0 || matrix_size > 100) {
        printf("Invalid input. Please enter a positive integer for the matrix size (up to 100).\n");
        return 1; // Indicate an error
    }

    // Prompt user to enter the matrix elements
    printf("Enter the elements of the %dx%d matrix:\n", matrix_size, matrix_size);
    for (i = 0; i < matrix_size; i++) {
        for (j = 0; j < matrix_size; j++) {
            printf("Enter element m[%d][%d]: ", i, j);
            if (scanf("%d", &matrix[i][j]) != 1) {
                printf("Invalid input for matrix element. Please enter an integer.\n");
                return 1; // Indicate an error
            }
            // Calculate sum of main diagonal elements
            if (i == j) {
                main_diagonal_sum += matrix[i][j];
            }
            // Calculate sum of anti-diagonal elements
            if (i + j == matrix_size - 1) {
                anti_diagonal_sum += matrix[i][j];
            }
        }
    }

    // Print the sums of the diagonals
    printf("\nSum of the main diagonal: %d\n", main_diagonal_sum);
    printf("Sum of the anti-diagonal: %d\n", anti_diagonal_sum);

    return 0; // Indicate successful execution
}
