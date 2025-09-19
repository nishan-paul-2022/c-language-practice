/*
 * Purpose: Reads two floating-point numbers, finds the larger one, and prints its value
 *          along with the size (in bytes) of a float variable.
 * Topic: Basic I/O, Conditional Operator (Ternary), sizeof Operator, Data Types
 */

#include <stdio.h>

float find_larger(float num1, float num2) {
    return (num1 > num2) ? num1 : num2;
}

int get_float_size() {
    return sizeof(float);
}

void get_numbers(float *num1, float *num2) {
    printf("Enter two floating-point values: ");
    scanf("%f %f", num1, num2);
}

int main(void) {
    float number1, number2;

    get_numbers(&number1, &number2);

    float larger_number = find_larger(number1, number2);
    int size_of_float = get_float_size();

    printf("The larger number is: %.2f\n", larger_number);
    printf("The size of a float is: %d bytes\n", size_of_float);

    return 0;
}
