/*
 * Purpose: Finds the largest among three double-precision floating-point numbers.
 * Topic: Input Processing, Conditional Statements, Finding Maximum Value
 */

#include <stdio.h>

// Finds the largest of three double-precision numbers.
double find_largest(double a, double b, double c) {
    double largest = a;
    if (b > largest) {
        largest = b;
    }
    if (c > largest) {
        largest = c;
    }
    return largest;
}

int main(void) {
    double num1, num2, num3;

    printf("Enter three numbers: ");

    // Read three numbers from standard input.
    if (scanf("%lf, %lf, %lf", &num1, &num2, &num3) == 3) {
        double largest = find_largest(num1, num2, num3);
        printf("The largest number is: %.2lf\n", largest);
    } else {
        // Handle incorrect input format.
        fprintf(stderr, "Error: Invalid input format. Please enter three numbers separated by commas.\n");
        // Clear the input buffer.
        while (getchar() != '\n');
    }

    return 0;
}
