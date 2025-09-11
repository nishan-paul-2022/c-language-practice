/*
 * Purpose: Reads a matrix, identifies prime numbers within it, and calculates their sum.
 * Topic: Arrays, 2D Arrays, Primality Test, Dynamic Memory Allocation
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to check if a number is prime
// Returns 1 if prime, 0 otherwise.
int is_prime(int num) {
    if (num <= 1) {
        return 0; // Numbers less than or equal to 1 are not prime
    }
    // Check for divisibility from 2 up to the square root of the number
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0; // If divisible by any number in this range, it's not prime
        }
    }
    return 1; // If no divisors found, it's prime
}

int main(void) {
    int rows, cols;
    int **matrix; // Pointer to pointer for dynamic 2D array
    int *prime_numbers = NULL; // Pointer to store prime numbers found
    int prime_count = 0;
    int prime_sum = 0;
    int i, j;

    // Prompt user for matrix dimensions
    printf("Enter the number of rows and columns for the matrix: ");
    if (scanf("%d %d", &rows, &cols) != 2 || rows <= 0 || cols <= 0) {
        printf("Invalid input. Please enter positive integers for rows and columns.\n");
        return 0;
    }

    // Dynamically allocate memory for the matrix
    matrix = (int **)malloc(rows * sizeof(int *));
    if (matrix == NULL) {
        printf("Memory allocation failed for rows.\n");
        return 1;
    }
    for (i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
        if (matrix[i] == NULL) {
            printf("Memory allocation failed for columns.\n");
            // Free previously allocated memory before exiting
            for (int k = 0; k < i; k++) {
                free(matrix[k]);
            }
            free(matrix);
            return 1;
        }
    }

    // Read matrix elements and identify prime numbers
    printf("Enter the elements of the %dx%d matrix:\n", rows, cols);
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("Enter element matrix[%d][%d]: ", i, j);
            // Using scanf with a space before %d to consume any leftover whitespace,
            // including newlines from previous inputs.
            if (scanf(" %d", &matrix[i][j]) != 1) {
                printf("Invalid input for matrix element. Please enter an integer.\n");
                // Free allocated memory before exiting
                for (int k = 0; k < rows; k++) {
                    free(matrix[k]);
                }
                free(matrix);
                return 0;
            }

            // Check if the number is prime
            if (is_prime(matrix[i][j])) {
                // If it's prime, add it to our list of primes
                prime_count++;
                // Reallocate memory for prime_numbers array to accommodate the new prime
                int *temp = (int *)realloc(prime_numbers, prime_count * sizeof(int));
                if (temp == NULL) {
                    printf("Memory reallocation failed for prime numbers.\n");
                    // Free all allocated memory before exiting
                    for (int k = 0; k < rows; k++) {
                        free(matrix[k]);
                    }
                    free(matrix);
                    free(prime_numbers);
                    return 1;
                }
                prime_numbers = temp;
                prime_numbers[prime_count - 1] = matrix[i][j];
                prime_sum += matrix[i][j];
            }
        }
    }

    // Print the prime numbers found
    printf("\nPrime numbers found in the matrix: ");
    if (prime_count == 0) {
        printf("None");
    } else {
        for (i = 0; i < prime_count; i++) {
            printf("%d ", prime_numbers[i]);
        }
    }
    printf("\n");

    // Print the sum of prime numbers
    printf("Sum of prime numbers: %d\n", prime_sum);

    // Free dynamically allocated memory
    for (i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
    free(prime_numbers);

    return 0;
}
