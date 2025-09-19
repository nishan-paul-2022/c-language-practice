/*
 * Purpose: To calculate the sum of a number and its successive integer divisions.
 * Topic: Loops, Basic I/O
 */

#include <stdio.h>

int read_two_ints(const char *prompt, int *a, int *b) {
    printf("%s", prompt);
    
    if (scanf("%d %d", a, b) != 2) {
        printf("Invalid input. Please enter two integers.\n");
        return -1;
    }

    if (*b == 0) {
        printf("Division by zero is not allowed.\n");
        return -1;
    }

    return 0;
}

int sum_successive_divisions(int num, int divisor) {
    int sum = 0;

    while (num > 0) {
        sum += num;
        num /= divisor;
    }

    return sum;
}

int main(void) {
    int num, divisor;
    if (read_two_ints("Enter a number and a divisor: ", &num, &divisor) == -1) {
        return 0;
    }

    int sum = sum_successive_divisions(num, divisor);
    printf("For number %d and divisor %d, the sum of successive integer divisions is: %d\n", num, divisor, sum);

    return 0;
}
