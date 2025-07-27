// Purpose: Demonstrates the use of function pointers to perform arithmetic operations.
// Topic: Function Pointers, Arithmetic Operations

#include <stdio.h>
#include <stdlib.h> // For abs() function
#include <math.h>   // Included for completeness, though abs() is preferred for integers

// Function to calculate the sum of two integers
int sum(int a, int b) {
    return a + b;
}

// Function to calculate the absolute difference of two integers
int subtract_abs(int a, int b) {
    // Using abs() for integer absolute difference, as fabs() is for floating-point numbers.
    return abs(a - b);
}

int main() {
    int num1, num2, result; // Variables to hold input numbers and the result

    // Prompt the user to enter two integers
    printf("Enter two integers (separated by a space): ");

    // Read two integers from the user and store them in num1 and num2.
    // Added input validation for scanf.
    if (scanf("%d %d", &num1, &num2) != 2) {
        printf("Invalid input. Please enter two integers.\n");
        return 1; // Indicate an error
    }

    // Declare function pointers.
    // 'func_ptr_add' can point to any function that takes two ints and returns an int.
    // 'func_ptr_sub' can point to any function that takes two ints and returns an int.
    int (*func_ptr_add)(int, int);
    int (*func_ptr_sub)(int, int);

    // Assign the addresses of the sum and subtract_abs functions to the pointers.
    func_ptr_add = sum;
    func_ptr_sub = subtract_abs;

    // Call the sum function using the function pointer 'func_ptr_add'
    result = func_ptr_add(num1, num2);
    printf("Sum: %d\n", result);

    // Call the subtract_abs function using the function pointer 'func_ptr_sub'
    result = func_ptr_sub(num1, num2);
    printf("Absolute difference: %d\n", result);

    return 0; // Indicate successful execution
}
