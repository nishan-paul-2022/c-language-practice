/*
 * Purpose: Reads two floating-point numbers, finds the larger one, and prints its value
 *          along with the size (in bytes) of a float variable.
 * Topic: Basic I/O, Conditional Operator (Ternary), sizeof Operator, Data Types
 */

#include <stdio.h> // Required for printf and scanf

int main() {
    float number1; // First floating-point number
    float number2; // Second floating-point number
    float larger_number; // Variable to store the larger of the two numbers
    int size_of_float_var; // Variable to store the size of a float (using int for sizeof result)

    // Prompt user for input
    printf("Enter two floating-point values (e.g., 10.5 20.3): ");
    scanf("%f %f", &number1, &number2);

    // Use the ternary operator to find the larger number
    larger_number = (number1 > number2) ? number1 : number2;

    // Get the size of a float variable using sizeof operator
    size_of_float_var = sizeof(larger_number); // Or sizeof(float)

    // Print the larger number
    printf("The larger number is: %.2f\n\n", larger_number);

    // Print the size of the float variable
    printf("The size of the float variable 'larger_number' is: %d bytes\n", size_of_float_var);

    return 0;
}
