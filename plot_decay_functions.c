#include <stdio.h>
#include <math.h> // Required for exp() function

int main() {
    double x_value;         // The independent variable for the functions (x-axis).
    double y1_value_double; // The calculated value of the first function (exponential decay).
    double y2_value_double; // The calculated value of the second function (Gaussian-like).
    int y1_scaled;          // Scaled and truncated value of y1 for plotting.
    int y2_scaled;          // Scaled and truncated value of y2 for plotting.
    int i;
    const double decay_constant_exp = 0.4; // Decay constant for the exponential function.
    const double decay_constant_gauss = 0.4; // Constant related to the width of the Gaussian-like function.

    // Loop through x values from 0 to 5, with a step of 0.25.
    // This simulates plotting points along the x-axis.
    for (x_value = 0.0; x_value <= 5.0; x_value += 0.25) {
        
        // Calculate the value for the first function: y1 = 50 * exp(-a * x)
        // The result is cast to int, effectively truncating the decimal part.
        y1_value_double = 50.0 * exp(-decay_constant_exp * x_value);
        y1_scaled = (int)y1_value_double;

        // Print leading spaces for the first function's plot point.
        // The number of spaces is determined by the scaled y1 value.
        for (i = 0; i < y1_scaled; i++) {
            printf(" ");
        }
        // Print '1' to represent the plot point for the first function.
        printf("1\n");

        // Calculate the value for the second function: y2 = 50 * exp(-0.4 * x^2 / 2)
        // This is a Gaussian-like function. The result is cast to int.
        y2_value_double = 50.0 * exp(-decay_constant_gauss * x_value * x_value / 2.0);
        y2_scaled = (int)y2_value_double;

        // Print leading spaces for the second function's plot point.
        // The number of spaces is determined by the scaled y2 value.
        for (i = 0; i < y2_scaled; i++) {
            printf(" ");
        }
        // Print '2' to represent the plot point for the second function.
        printf("2\n");
    }

    return 0;
}
