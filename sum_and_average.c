/*
 * Purpose: To calculate the sum and average of 10 numbers.
 * Topic: Loops, Basic I/O
 */

#include <stdio.h>

int main() {
    double input, sum = 0.0, average;
    int i, count = 10;

    printf("Enter %d numbers:\n", count);

    for (i = 0; i < count; i++) {
        scanf("%lf", &input);
        sum += input;
    }

    average = sum / count;

    printf("Number of inputs: %d\n", count);
    printf("Summation of inputs: %lf\n", sum);
    printf("Average of inputs: %lf\n", average);

    return 0;
}
