/*
 * Purpose: Reads two floating-point numbers, finds the larger one, and prints its value
 *          along with the size (in bytes) of a float variable.
 * Topic: Basic I/O, Conditional Operator (Ternary), sizeof Operator, Data Types
 */

#include <stdio.h>

// Finds the larger of two floating-point numbers.
float findLarger(float num1, float num2) {
    return (num1 > num2) ? num1 : num2;
}

// Gets the size of a float variable.
int getFloatSize() {
    return sizeof(float);
}

// Prompts the user to enter two numbers and reads them.
void getNumbers(float *num1, float *num2) {
    printf("Enter two floating-point values (e.g., 10.5 20.3): ");
    scanf("%f %f", num1, num2);
}

int main(void) {
    float number1, number2;

    getNumbers(&number1, &number2);

    float larger_number = findLarger(number1, number2);
    int size_of_float = getFloatSize();

    printf("The larger number is: %.2f\n", larger_number);
    printf("The size of a float is: %d bytes\n", size_of_float);

    return 0;
}