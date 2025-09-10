/*
 * Purpose: Demonstrates reading and printing a long double-precision floating-point number.
 * Topic: Input/Output, Data Types (long double)
 */

#include <stdio.h>

int main() {
    long double value;

    printf("Enter a long double-precision floating-point number: ");
    // Use %Lf for long double with scanf and printf
    if (scanf("%Lf", &value) != 1) {
        printf("Invalid input. Please enter a valid number.\n");
        return 0;
    }

    printf("You entered: %Lf\n", value);

    return 0;
}
