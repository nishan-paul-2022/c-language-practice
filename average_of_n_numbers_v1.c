/*
 * Purpose: Calculates the average of a specified number of double-precision floating-point numbers.
 * Topic: Input/Output, Loops, Basic Statistics
 */

#include <stdio.h>

int main() {
    int count;
    double sum = 0.0;

    printf("Enter the number of values you want to average: ");
    if (scanf("%d", &count) != 1 || count <= 0) {
        printf("Invalid input. Please enter a positive integer for the count.\n");
        return 0;
    }

    printf("Enter %d numbers:\n", count);
    for (int i = 0; i < count; i++) {
        double number;
        if (scanf("%lf", &number) != 1) {
            printf("Invalid input. Please enter a numeric value.\n");
            return 1;
        }
        sum += number;
    }

    printf("The average of the %d numbers is: %.3lf\n", count, sum / count);

    return 0;
}
