/*
 * Purpose: To calculate the sum of a number and its successive integer divisions.
 * Topic: Loops, Basic I/O
 */

#include <stdio.h>

int main() {
    int num, divisor, sum = 0;

    printf("Enter a number and a divisor: ");
    scanf("%d %d", &num, &divisor);

    if (divisor == 0) {
        printf("Error: Division by zero is not allowed.\n");
        return 0;
    }

    while (num > 0) {
        sum += num;
        num /= divisor;
    }

    printf("The sum is: %d\n", sum);

    return 0;
}
