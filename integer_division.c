/*
 * Purpose: Divides two integers and prints the result, including basic error handling for division by zero.
 * Topic: Functions, Basic I/O
 */

#include <stdio.h>

int divide(int a, int b) {
    if (b != 0) {
        return a / b;
    } else {
        printf("Error: Division by zero.\n");
        return 0;
    }
}

int main() {
    int x, y, result;

    printf("Enter the dividend: ");
    scanf("%d", &x);

    printf("Enter the divisor: ");
    scanf("%d", &y);

    result = divide(x, y);

    if (y != 0) {
        printf("The result is: %d\n", result);
    }

    return 0;
}
