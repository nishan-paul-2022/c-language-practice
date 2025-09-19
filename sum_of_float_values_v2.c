/*
 * Purpose: Reads two floating-point numbers, calculates their sum, and prints the sum as an integer.
 *          This demonstrates implicit type conversion (truncation) from float to int.
 * Topic: Basic I/O, Data Types, Type Conversion
 */

#include <stdio.h>

void read_two_floats(float *a, float *b) {
    printf("Enter two floating-point values (e.g., 10.5 2.3): ");
    scanf("%f %f", a, b);
}

int sum_as_int(float a, float b) {
    int result = a + b;
    return result;
}

int main(void) {
    float num1, num2;
    read_two_floats(&num1, &num2);

    int result = sum_as_int(num1, num2);

    printf("The sum of the two numbers (truncated to integer) is: %d\n", result);

    return 0;
}
