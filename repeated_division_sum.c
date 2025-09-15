/*
 * Purpose: Calculates a sum by repeatedly adding a value and then dividing it by a divisor until it becomes zero.
 * Topic: Loops, Integer Division, Accumulation, Input Validation
 */

#include <stdio.h>

int read_input(int *value, int *divisor) {
    printf("Enter two integers (value divisor): ");
    if (scanf("%d %d", value, divisor) != 2) {
        fprintf(stderr, "Error: Invalid input.\n");
        while (getchar() != '\n'); // Clear buffer
        return -1;
    }
    if (*divisor == 0) {
        fprintf(stderr, "Error: Division by zero.\n");
        return -1;
    }
    return 0;
}

int calculate_sum(int value, int divisor) {
    int sum = 0;
    while (value) {
        sum += value;
        value /= divisor;
    }
    return sum;
}

int main(void) {
    int current_value, divisor;
    if (read_input(&current_value, &divisor) == -1) {
        return 0;
    }
    int sum = calculate_sum(current_value, divisor);
    printf("The calculated sum is: %d\n", sum);
    return 0;
}
