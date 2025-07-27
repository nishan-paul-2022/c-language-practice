/*
 * Purpose: Converts a decimal integer to its binary representation.
 * Topic: Loops, Arithmetic Operations, Number Systems, Arrays
 */

#include <stdio.h>
#include <stdlib.h> // For EXIT_SUCCESS, EXIT_FAILURE

int main()
{
    int decimalNumber;
    int binaryDigits[32]; // An array to store binary digits (sufficient for 32-bit int)
    int i;

    printf("Enter a non-negative decimal integer (or Ctrl+D to exit): ");
    while (scanf("%d", &decimalNumber) == 1)
    {
        if (decimalNumber < 0)
        {
            printf("Please enter a non-negative integer.\n");
            printf("Enter a non-negative decimal integer (or Ctrl+D to exit): ");
            continue;
        }

        if (decimalNumber == 0)
        {
            printf("Binary: 0\n");
            printf("Enter a non-negative decimal integer (or Ctrl+D to exit): ");
            continue;
        }

        i = 0;
        while (decimalNumber > 0)
        {
            binaryDigits[i] = decimalNumber % 2;
            decimalNumber = decimalNumber / 2;
            i++;
        }

        printf("Binary: ");
        // Print binary digits in reverse order
        for (int j = i - 1; j >= 0; j--)
        {
            printf("%d", binaryDigits[j]);
        }
        printf("\n\n");

        printf("Enter a non-negative decimal integer (or Ctrl+D to exit): ");
    }

    printf("\nExiting program.\n");
    return EXIT_SUCCESS;
}
