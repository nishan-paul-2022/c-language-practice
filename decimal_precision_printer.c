/*
 * Purpose: Reads a double-precision floating-point number and prints it with a precision
 *          equal to the number of decimal places in the input.
 * Topic: Input/Output, Floating-Point Numbers, Loops, Precision Formatting
 */

#include <stdio.h>
#include <math.h>

int main()
{
    double inputNumber;
    double tempNumber;
    int decimalPlaces;

    printf("Enter a floating-point number (e.g., 123.456) (or Ctrl+D to exit): ");
    while (scanf("%lf", &inputNumber) == 1)
    {
        decimalPlaces = 0;
        tempNumber = inputNumber;

        // Check if the number has a fractional part
        if (tempNumber != (long long)tempNumber)
        {
            // Multiply by 10 until the fractional part is zero
            // This counts the number of decimal places
            while (fmod(tempNumber, 1.0) != 0.0 && decimalPlaces < 15) // Limit to avoid infinite loop with floating point inaccuracies
            {
                tempNumber *= 10.0;
                decimalPlaces++;
            }
        }

        // Print the original number with the determined precision
        printf("The number with its original precision: %.*lf\n\n", decimalPlaces, inputNumber);
        printf("Enter another floating-point number (or Ctrl+D to exit): ");
    }

    printf("\nExiting program.\n");
    return 0;
}
