/*
 * Purpose: Divides two integers and prints the result, including basic error handling for division by zero.
 * Topic: Functions, Basic I/O
 */

#include <stdio.h>

int divide_numbers(int a, int b) {
    if (b != 0) {
        return a / b;
    } else {
        printf("Division by zero.\n");
        return 0;
    }
}

void get_input_and_divide() {
    int x, y, result;

    printf("Enter dividend: ");
    scanf("%d", &x);

    printf("Enter divisor: ");
    scanf("%d", &y);

    result = divide_numbers(x, y);

    if (y != 0) {
        printf("Result: %d\n", result);
    }
}

int main(void) {
    get_input_and_divide();
    return 0;
}
