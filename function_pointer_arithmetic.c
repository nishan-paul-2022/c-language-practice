/*
 * Purpose: Demonstrates the use of function pointers to perform arithmetic operations.
 * Topic: Function Pointers, Arithmetic Operations
 */

#include <stdio.h>
#include <stdlib.h>

int sum(int a, int b) {
    return a + b;
}

int subtract_abs(int a, int b) {
    return abs(a - b);
}

int get_input(int *num1, int *num2) {
    printf("Enter two integers: ");
    if (scanf("%d %d", num1, num2) != 2) {
        printf("Invalid input. Please enter two integers.\n");
        return -1;
    }
    return 0;
}

void perform_operations(int num1, int num2) {
    int (*func_ptr_add)(int, int) = sum;
    int (*func_ptr_sub)(int, int) = subtract_abs;

    printf("Sum: %d\n", func_ptr_add(num1, num2));
    printf("Absolute difference: %d\n", func_ptr_sub(num1, num2));
}

int main(void) {
    int num1, num2;
    
    if (get_input(&num1, &num2) == 0) {
        perform_operations(num1, num2);
    }
    
    return 0;
}
