/*
 * Purpose: Demonstrates initializing a 2D array and setting specific elements to 1.
 * Topic: 2D arrays, loops, input/output, initialization.
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_DIMENSION 100

int get_dimension(void) {
    int dimension;
    printf("Enter the dimension of the square matrix (max %d): ", MAX_DIMENSION);
    if (scanf("%d", &dimension) != 1 || dimension <= 0 || dimension > MAX_DIMENSION) {
        printf("Invalid input. Please enter a positive integer for dimension up to %d.\n", MAX_DIMENSION);
        return -1;
    }
    while (getchar() != '\n');
    return dimension;
}

int get_num_elements() {
    int num_elements;
    printf("Enter the number of elements to set to 1: ");
    if (scanf("%d", &num_elements) != 1 || num_elements < 0) {
        printf("Invalid input. Please enter a non-negative integer for the number of elements.\n");
        return -1;
    }
    while (getchar() != '\n');
    return num_elements;
}

void initialize_matrix(int matrix[MAX_DIMENSION][MAX_DIMENSION], int dimension) {
    for (int row = 0; row < dimension; row++) {
        for (int col = 0; col < dimension; col++) {
            matrix[row][col] = 0;
        }
    }
}

void set_matrix_elements(int matrix[MAX_DIMENSION][MAX_DIMENSION], int dimension, int num_elements) {
    printf("Enter %d pairs of row and column indices (format: row col):\n", num_elements);
    
    for (int i = 0; i < num_elements; i++) {
        int row, col;
        printf("Enter pair %d: ", i + 1);
        
        if (scanf("%d %d", &row, &col) != 2) {
            printf("Invalid input for pair %d. Please enter two integers separated by a space.\n", i + 1);
            return;
        }
        while (getchar() != '\n');

        if (row >= 0 && row < dimension && col >= 0 && col < dimension) {
            matrix[row][col] = 1;
        } else {
            printf("Indices (%d, %d) are out of bounds for a %d x %d matrix. Skipping.\n", 
                   row, col, dimension, dimension);
        }
    }
}

void print_matrix(int matrix[MAX_DIMENSION][MAX_DIMENSION], int dimension) {
    printf("\nMatrix after setting elements to 1:\n");
    for (int row = 0; row < dimension; row++) {
        for (int col = 0; col < dimension; col++) {
            printf("%d ", matrix[row][col]);
        }
        printf("\n");
    }
}

int main(void) {
    int matrix[MAX_DIMENSION][MAX_DIMENSION];
    
    int dimension = get_dimension();
    if (dimension == -1) return 0;

    int num_elements = get_num_elements();
    if (num_elements == -1) return 0;

    initialize_matrix(matrix, dimension);
    set_matrix_elements(matrix, dimension, num_elements);
    print_matrix(matrix, dimension);

    return 0;
}
