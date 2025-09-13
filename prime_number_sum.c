/*
 * Purpose: Reads a matrix, identifies prime numbers within it, and calculates their sum.
 * Topic: Arrays, 2D Arrays, Primality Test, Dynamic Memory Allocation
 */

#include <stdio.h>
#include <stdlib.h>

int is_prime(int num) {
    if (num <= 1) return 0;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

int main(void) {
    int rows, cols;
    int **matrix;
    int *primes = NULL;
    int prime_count = 0, prime_sum = 0;

    printf("Enter the number of rows and columns for the matrix: ");
    if (scanf("%d %d", &rows, &cols) != 2 || rows <= 0 || cols <= 0) {
        printf("Invalid input. Please enter positive integers for rows and columns.\n");
        return 0;
    }

    matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }

    printf("Enter the elements of the %dx%d matrix:\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (scanf(" %d", &matrix[i][j]) != 1) {
                printf("Invalid input for matrix element.\n");
                for (int k = 0; k < rows; k++) free(matrix[k]);
                free(matrix);
                free(primes);
                return 0;
            }
            if (is_prime(matrix[i][j])) {
                int *temp = (int *)realloc(primes, (prime_count + 1) * sizeof(int));
                if (!temp) {
                    printf("Memory allocation failed.\n");
                    for (int k = 0; k < rows; k++) free(matrix[k]);
                    free(matrix);
                    free(primes);
                    return 0;
                }
                primes = temp;
                primes[prime_count++] = matrix[i][j];
                prime_sum += matrix[i][j];
            }
        }
    }

    printf("\nPrime numbers found in the matrix: ");
    if (prime_count == 0) printf("None");
    else for (int i = 0; i < prime_count; i++) printf("%d ", primes[i]);
    printf("\nSum of prime numbers: %d\n", prime_sum);

    for (int i = 0; i < rows; i++) free(matrix[i]);
    free(matrix);
    free(primes);

    return 0;
}
