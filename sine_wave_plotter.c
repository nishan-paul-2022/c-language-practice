#define _USE_MATH_DEFINES
#include <stdio.h>

// Define M_PI if it's not already defined by math.h with _USE_MATH_DEFINES
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
#include <math.h> // For sin() and M_PI, round()

// Purpose: Visualizes a sine wave by printing asterisks at scaled positions.
// Topic: Trigonometry, Loops, Math Functions, Output Formatting
int main(void) {
    double angle_degrees; // Angle in degrees
    double angle_radians; // Angle in radians
    double sine_value;    // The sine of the angle
    int scaled_position;  // Scaled position for printing spaces
    int i;
    double m;

    // Define the amplitude and the scaling factor for the plot
    const double AMPLITUDE = 50.0; 
    const int DEGREE_STEP = 15;

    printf("Sine Wave Plot:\n");
    printf("----------------\n");

    // Loop through angles from 0 to 180 degrees, in steps of DEGREE_STEP
    for (i = 0; i <= 180; i = i + DEGREE_STEP) {
        // Convert degrees to radians for the sin() function
        angle_radians = (3.14159265358979323846 / 180.0) * i;
        
        // Calculate the sine of the angle
        sine_value = sin(angle_radians);
        
        // Scale the sine value and round it to get the position for the asterisk
        // The original code used (int) which truncates. Rounding provides a better visual.
        scaled_position = (int)round(AMPLITUDE * sine_value);

        // Print leading spaces to position the asterisk
        // Ensure scaled_position is not negative, though for 0-180 degrees, sin is non-negative.
        // If it were negative, we'd need to handle it (e.g., print spaces based on absolute value or adjust logic).
        for (m = 0; m < scaled_position; m++) {
            printf(" ");
        }
        
        // Print the asterisk at the calculated position
        printf("*");
        
        // Move to the next line for the next angle
        printf("\n");
    }
    printf("----------------\n");

    return 0;
}
