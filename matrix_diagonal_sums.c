/*
 * Purpose: Calculates the sum of the main and anti-diagonals of a square matrix.
 * Topic: 2D Arrays, Matrix Operations, Loops
 */

#include <stdio.h>

#define MAX_SIZE 100

int read_matrix_size(void) {
    int size;
    printf("Enter the size of the square matrix (1-%d): ", MAX_SIZE);
    if (scanf("%d", &size) != 1 || size <= 0 || size > MAX_SIZE) {
        printf("Invalid size. Please enter a positive integer between 1 and %d.\n", MAX_SIZE);
        return 0;
    }
    return size;
}

int read_matrix_elements(int matrix[MAX_SIZE][MAX_SIZE], int size) {
    int i, j;
    printf("Enter the elements of the %dx%d matrix:\n", size, size);
    for (i = 0; i < size; i++) {
        printf("Row %d: ", i + 1);
        for (j = 0; j < size; j++) {
            if (scanf("%d", &matrix[i][j]) != 1) {
                printf("Invalid input. Please enter integers only.\n");
                return -1;
            }
        }
    }
    return 0;
}

void calculate_diagonal_sums(int matrix[MAX_SIZE][MAX_SIZE], int size, int *main_sum, int *anti_sum) {
    int i;
    *main_sum = 0;
    *anti_sum = 0;

    for (i = 0; i < size; i++) {
        *main_sum += matrix[i][i];
        *anti_sum += matrix[i][size - 1 - i];
    }

    if (size % 2) {
        int center = size / 2;
        *anti_sum -= matrix[center][center];
    }
}

void print_results(int main_sum, int anti_sum) {
    printf("\nSum of the main diagonal: %d\n", main_sum);
    printf("Sum of the anti-diagonal: %d\n", anti_sum);
}

int main(void) {
    int matrix[MAX_SIZE][MAX_SIZE];
    int size;
    int main_diagonal_sum, anti_diagonal_sum;

    size = read_matrix_size();
    if (size == 0) {
        return 0;
    }

    if (read_matrix_elements(matrix, size) == -1) {
        return 0;
    }

    calculate_diagonal_sums(matrix, size, &main_diagonal_sum, &anti_diagonal_sum);
    print_results(main_diagonal_sum, anti_diagonal_sum);

    return 0;
}
