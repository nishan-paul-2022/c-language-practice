/*
 * Purpose: Calculates the sum of the harmonic series (1 + 1/2 + 1/3 + ... + 1/n).
 * Topic: Loops, Floating-point Arithmetic, Type Casting
 */

#include <stdio.h> // Required for printf and scanf

int main() {
    int n_terms; // Number of terms for the harmonic series
    float sum_harmonic_series = 0.0; // Variable to store the sum of the series
    int i; // Loop counter

    // Prompt user for input
    printf("Enter the number of terms (n) for the harmonic series: ");
    scanf("%d", &n_terms);

    // Calculate the sum of the harmonic series
    for (i = 1; i <= n_terms; i++) {
        // Perform floating-point division by casting 'i' to float
        sum_harmonic_series = sum_harmonic_series + (1.0 / i);
    }

    // Print the calculated sum
    printf("The summation of the harmonic series up to %d terms is: %f\n", n_terms, sum_harmonic_series);

    return 0; // Indicate successful execution
}
