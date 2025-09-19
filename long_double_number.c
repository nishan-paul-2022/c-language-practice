/*
 * Purpose: Demonstrates reading and printing long double-precision floating-point number.
 * Topic: Input/Output, Data Types (long double)
 */

#include <stdio.h>

long double read_long_double() {
    long double value;

    printf("Enter a long double precision floating point number: ");
    
    if (scanf("%Lf", &value) != 1) {
        printf("Invalid input. Please enter a valid number.\n");
        return 0.0L;
    }
    
    return value;
}

void display_long_double(long double value) {
    printf("Entered number is %Lf\n", value);
}

int main(void) {
    long double value;

    value = read_long_double();

    if (value != 0.0L) {
        display_long_double(value);
    }

    return 0;
}
