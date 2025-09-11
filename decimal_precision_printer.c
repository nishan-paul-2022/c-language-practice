/*
 * Purpose: Reads a double-precision floating-point number and prints it with a precision
 *          equal to the number of decimal places in the input.
 * Topic: Input/Output, Floating-Point Numbers, Loops, Precision Formatting
 */

#include <stdio.h>
#include <math.h>

int main(void) {
    double input_number;
    double temp_number;
    int decimal_places;

    printf("Enter a floating-point number (e.g., 123.456) (or Ctrl+D to exit): ");
    while (scanf("%lf", &input_number) == 1) {
        decimal_places = 0;
        temp_number = input_number;

        // Check if the number has a fractional part
        if (temp_number != (long long)temp_number) {
            // Multiply by 10 until the fractional part is zero
            // This counts the number of decimal places
            // Limit to 15 to avoid infinite loop with floating point inaccuracies
            while (fmod(temp_number, 1.0) != 0.0 && decimal_places < 15) {
                temp_number *= 10.0;
                decimal_places++;
            }
        }

        // Print the original number with the determined precision
        printf("The number with its original precision: %.*lf\n\n", decimal_places, input_number);
        printf("Enter another floating-point number (or Ctrl+D to exit): ");
    }

    printf("\nExiting program.\n");
    return 0;
}
