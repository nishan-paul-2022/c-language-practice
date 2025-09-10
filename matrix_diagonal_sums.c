/*
 * Purpose: Calculates the sum of the main and anti-diagonals of a square matrix.
 * Topic: 2D Arrays, Matrix Operations, Loops
 */

#include <stdio.h>

#define MAX_SIZE 100 // Maximum matrix size

int main() {
    int matrix[MAX_SIZE][MAX_SIZE];
    int size, i, j;
    int main_diagonal_sum = 0;
    int anti_diagonal_sum = 0;

    // Prompt for the matrix size and validate it
    printf("Enter the size of the square matrix (1-%d): ", MAX_SIZE);
    if (scanf("%d", &size) != 1 || size <= 0 || size > MAX_SIZE) {
        printf("Invalid size. Please enter a positive integer between 1 and %d.\n", MAX_SIZE);
        return 1; // Indicate error
    }

    // Read matrix elements from user input
    printf("Enter the elements of the %dx%d matrix:\n", size, size);
    for (i = 0; i < size; i++) {
        printf("Row %d: ", i + 1);
        for (j = 0; j < size; j++) {
            if (scanf("%d", &matrix[i][j]) != 1) {
                printf("Invalid input. Please enter integers only.\n");
                return 1; // Indicate error
            }
        }
    }

    // Calculate the sum of both diagonals in a single loop
    for (i = 0; i < size; i++) {
        main_diagonal_sum += matrix[i][i];
        anti_diagonal_sum += matrix[i][size - 1 - i];
    }

    // If the matrix has an odd size, the center element is counted twice, so subtract it once.
    if (size % 2 != 0) {
        int center = size / 2;
        anti_diagonal_sum -= matrix[center][center];
    }

    // Print the final sums
    printf("\nSum of the main diagonal: %d\n", main_diagonal_sum);
    printf("Sum of the anti-diagonal: %d\n", anti_diagonal_sum);

    return 0;
}