/*
 * Purpose: Calculates and displays powers of 2 and their reciprocals for a given number of iterations using the pow() function.
 * Topic: Loops, Math Functions, Powers
 */

#include <stdio.h>
#include <math.h>

void print_powers(int iterations) {
    printf("\n--- Power Calculations ---\n");
    printf("Power of 2 | Iteration | Reciprocal Power of 2\n");
    printf("----------------------------------------------\n");

    for (int i = 1; i <= iterations; i++) {
        int power_of_two = (int)pow(2, i);
        double reciprocal_power_of_two = pow(2, -i);
        printf("%-10d | %-9d | %10.5lf\n", power_of_two, i, reciprocal_power_of_two);
    }
    printf("\n");
}

int main(void) {
    int num_iterations;

    printf("Enter the number of iterations: ");
    if (scanf("%d", &num_iterations) != 1 || num_iterations <= 0) {
        fprintf(stderr, "Invalid input. Please enter a positive integer for the number of iterations.\n");
        return 0;
    }

    print_powers(num_iterations);

    return 0;
}
