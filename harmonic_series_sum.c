/*
 * Purpose: Calculates the sum of the harmonic series (1 + 1/2 + 1/3 + ... + 1/n).
 * Topic: Loops, Floating-point Arithmetic, Type Casting
 */

#include <stdio.h>

int main(void) {
    int n_terms; // Number of terms for the harmonic series
    float sum_harmonic_series = 0.0; // Variable to store the sum of the series
    int i;

    // Prompt user to enter the number of terms
    printf("Enter the number of terms (n) for the harmonic series: ");
    // Read the number of terms from user input
    scanf("%d", &n_terms);

    // Calculate the sum of the harmonic series
    for (i = 1; i <= n_terms; i++) {
        // Perform floating-point division by casting 'i' to float
        sum_harmonic_series = sum_harmonic_series + (1.0 / i);
    }

    // Display the calculated sum
    printf("The summation of the harmonic series up to %d terms is: %f\n", n_terms, sum_harmonic_series);

    return 0;
}
