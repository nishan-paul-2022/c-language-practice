/*
 * Purpose: Calculates 'base' raised to the power of 'exponent' (base^exponent) using a loop.
 *          Handles positive, zero, and negative integer exponents.
 * Topic: Exponentiation, Loops, Floating-Point Arithmetic
 */

#include <stdio.h>
#include <math.h> // Required for fabs() if handling negative exponents with division.

// Declare main as int main() for standard C compliance.
int main()
{
    double base;         // The base number.
    int exponent;        // The exponent.
    double result = 1.0; // Initialize result to 1.0 for exponentiation.
    int counter;

    // --- Input ---
    printf("Enter the base (a double) and the exponent (an integer), separated by a comma (e.g., 2.5, 3): ");

    // Read the base and exponent.
    // Using scanf for mixed input. Note: This can be fragile.
    if (scanf("%lf", &base) != 1)
    {
        printf("Invalid input for base. Please enter a valid double.\n");
        return 0;
    }

    // Consume the comma and any whitespace after the base.
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
        if (c == ',')
        { // Found the comma separator
            // Consume any whitespace after the comma
            while ((c = getchar()) != '\n' && c != EOF && (c == ' ' || c == '\t'))
            {
            }
            // If we consumed a newline immediately after comma, it's an error.
            if (c == '\n' || c == EOF)
            {
                printf("Invalid input format. Missing exponent after comma.\n");
                return 0;
            }
    
            break; // Exit the character consumption loop if we found the comma.
        }
    }
    // If the loop finished without finding a comma, it's an error.
    if (c != ',' && c != '\n' && c != EOF)
    {
    }

}