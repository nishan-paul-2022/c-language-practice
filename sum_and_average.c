/*
 * Purpose: Calculate the sum and average of 10 numbers.
 * Topic: Loops, Basic I/O, Functions
 */

#include <stdio.h>

double calculate_sum(int count) {
    double input, sum = 0.0;
    for (int i = 0; i < count; i++) {
        scanf("%lf", &input);
        sum += input;
    }
    return sum;
}

double calculate_average(double sum, int count) {
    return sum / count;
}

int main(void) {
    printf("Enter the number of test cases: ");
    int test_cases;
    scanf("%d", &test_cases);

    for (int i = 1; i <= test_cases; i++) {
        printf("\n\nTest Case %d:\n", i);

        printf("Enter the number of inputs: ");
        int count;
        scanf("%d", &count);
        printf("Enter %d numbers:\n", count);

        double sum = calculate_sum(count);
        double average = calculate_average(sum, count);

        printf("Number of inputs: %d\n", count);
        printf("Summation of inputs: %.2lf\n", sum);
        printf("Average of inputs: %.2lf\n", average);
    }


    return 0;
}
