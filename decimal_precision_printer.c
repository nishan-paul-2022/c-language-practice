/*
 * Purpose: Reads a double-precision floating-point number and prints it with a precision
 *          equal to the number of decimal places in the input.
 * Topic: Input/Output, Floating-Point Numbers, Loops, Precision Formatting
 */

#include <stdio.h>
#include <math.h>

int count_decimal_places(double number) {
    int decimal_places = 0;
    double temp_number = number;

    if (temp_number != (long long)temp_number) {
        while (fmod(temp_number, 1.0) != 0.0 && decimal_places < 15) {
            temp_number *= 10.0;
            decimal_places++;
        }
    }

    return decimal_places;
}

void display_number_with_precision(double number, int precision) {
    printf("The number with its original precision: %.*lf\n\n", precision, number);
}

void process_floating_point_numbers() {
    double input_number;
    int decimal_places;

    printf("Enter a floating-point number (e.g., 123.456) (or Ctrl+D to exit): ");
    
    while (scanf("%lf", &input_number) == 1) {
        decimal_places = count_decimal_places(input_number);
        display_number_with_precision(input_number, decimal_places);
        printf("Enter another floating-point number (or Ctrl+D to exit): ");
    }

    printf("\nExiting program.\n");
}

int main(void) {
    process_floating_point_numbers();
    return 0;
}
