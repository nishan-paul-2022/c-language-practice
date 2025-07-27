/*
 * Purpose: Reads a floating-point number, extracts its integer part, and then finds the last digit of that integer part.
 * Topic: Basic I/O, Type Casting, Arithmetic Operators (Modulo)
 */

#include <stdio.h> // Required for printf and scanf

int main() {
    float input_float; // Floating-point number input by the user
    int integer_part;  // Integer part of the input float
    int last_digit;    // Last digit of the integer part

    // Prompt user for input
    printf("Enter a floating-point value (e.g., 123.45): ");
    scanf("%f", &input_float);

    // Convert the floating-point number to an integer.
    // This truncates the decimal part.
    integer_part = (int)input_float;

    // Calculate the last digit of the integer part using the modulo operator.
    // The modulo operator (%) gives the remainder of a division.
    last_digit = integer_part % 10;

    // Print the extracted last digit
    printf("The last digit of the integer part is: %d\n", last_digit);

    return 0; // Indicate successful execution
}
