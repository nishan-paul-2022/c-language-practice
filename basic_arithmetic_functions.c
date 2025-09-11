/*
 * Purpose: Demonstrates basic arithmetic operations (addition and subtraction) using functions.
 * Topic: Functions, Basic Arithmetic
 */

#include <stdio.h>

// Function prototypes
int add(int num1, int num2);
int subtract(int num1, int num2);

int main(void) {
    int x = 10;
    int y = 20;
    int sum_result;
    int subtract_result;

    sum_result = add(x, y);
    subtract_result = subtract(y, x);

    printf("%d + %d = %d\n", x, y, sum_result);
    printf("%d - %d = %d\n", y, x, subtract_result);

    return 0;
}

// Function to add two integers
int add(int num1, int num2) {
    return num1 + num2;
}

// Function to subtract two integers
int subtract(int num1, int num2) {
    return num1 - num2;
}
