/*
 * Purpose: Calculates sum and average of given numbers.
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
    double average = sum / count;
    return average;
}

int main(void) {
    int test_cases;
    printf("Enter the number of test cases: ");
    scanf("%d", &test_cases);

    for (int i = 1; i <= test_cases; i++) {
        printf("\nTest Case %d:\n", i);

        int count;
        printf("Enter the number of inputs: ");
        scanf("%d", &count);

        printf("Enter %d numbers: ", count);
        double sum = calculate_sum(count);
        double average = calculate_average(sum, count);

        printf("Number of inputs: %d\n", count);
        printf("Sum of inputs: %.2lf\n", sum);
        printf("Average of inputs: %.2lf\n", average);
    }


    return 0;
}
