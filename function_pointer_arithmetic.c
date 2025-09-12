/*
 * Purpose: Demonstrates the use of function pointers to perform arithmetic operations.
 * Topic: Function Pointers, Arithmetic Operations
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int sum(int a, int b) {
    return a + b;
}

int subtract_abs(int a, int b) {
    return abs(a - b);
}

int perform_arithmetic_operations() {
    int num1, num2, result;

    printf("Enter two integers (separated by a space): ");
    if (scanf("%d %d", &num1, &num2) != 2) {
        printf("Invalid input. Please enter two integers.\n");
        return 0;
    }

    int (*func_ptr_add)(int, int);
    int (*func_ptr_sub)(int, int);

    func_ptr_add = sum;
    func_ptr_sub = subtract_abs;

    result = func_ptr_add(num1, num2);
    printf("Sum: %d\n", result);

    result = func_ptr_sub(num1, num2);
    printf("Absolute difference: %d\n", result);

    return 0;
}

int main(void) {
    return perform_arithmetic_operations();
}
