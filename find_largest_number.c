/*
 * Purpose: Finds the largest among three double-precision floating-point numbers.
 * Topic: Input Processing, Conditional Statements, Finding Maximum Value
 */

#include <stdio.h>

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

    printf("Enter three numbers (comma-separated): ");

    if (scanf("%lf, %lf, %lf", &num1, &num2, &num3) == 3) {
        double largest = find_largest(num1, num2, num3);
        printf("The largest number is: %.2lf\n", largest);
    } else {
        fprintf(stderr, "Error: Invalid input format. Please enter three numbers separated by commas.\n");
        while (getchar() != '\n');
    }

    return 0;
}
