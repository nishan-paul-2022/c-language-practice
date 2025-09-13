/*
 * Purpose: Calculates the sum of the harmonic series (1 + 1/2 + 1/3 + ... + 1/n).
 * Topic: Loops, Floating-point Arithmetic, Type Casting
 */

#include <stdio.h>

float calculate_harmonic_sum(int n_terms) {
    float sum_harmonic_series = 0.0;

    for (int i = 1; i <= n_terms; i++) {
        sum_harmonic_series += (1.0 / i);
    }

    return sum_harmonic_series;
}

int main(void) {
    int n_terms;
    float result;

    printf("Enter the number of terms (n) for the harmonic series: ");
    scanf("%d", &n_terms);

    result = calculate_harmonic_sum(n_terms);

    printf("The summation of the harmonic series up to %d terms is: %f\n", n_terms, result);

    return 0;
}
