#include <stdio.h>
#include <math.h> // Required for sqrt() and potentially other math functions

int main() {
    int i;                  // Loop counter
    double y_value;         // The value of the quadratic function for a given i
    double min_y = 40.0;    // Initialize minimum y to a large value (or a value from the range)
    double max_y = 40.0;    // Initialize maximum y to a small value (or a value from the range)
    double D1, D2;          // Variables for the final calculations

    // The quadratic function is y = (i*i - 80*i + 4000) / 100
    // This can be rewritten as y = 0.01*i^2 - 0.8*i + 40
    // The vertex (minimum) of a parabola ax^2 + bx + c is at x = -b / (2a).
    // For this function, the vertex is at i = -(-0.8) / (2 * 0.01) = 0.8 / 0.02 = 40.
    // The minimum value occurs at i=40.

    // Iterate through the range of i from 0 to 100
    for (i = 0; i <= 100; i++) {
        // Calculate the value of the quadratic function for the current i
        y_value = ((double)i * i - 80.0 * i + 4000.0) / 100.0;

        // Update the minimum y value found so far
        if (y_value < min_y) {
            min_y = y_value;
        }
        // Update the maximum y value found so far
        if (y_value > max_y) {
            max_y = y_value;
        }
    }

    // Calculate D1 using the minimum y value (z in original code)
    // The formula is D1 = sqrt(6400 - 4 * (4000 - min_y * 100))
    // Note: The term inside sqrt must be non-negative for sqrt to be defined in real numbers.
    D1 = sqrt(6400.0 - 4.0 * (4000.0 - min_y * 100.0));

    // Calculate D2 using the maximum y value (Z in original code)
    // The formula is D2 = sqrt(6400 - 4 * (4000 - max_y * 100))
    D2 = sqrt(6400.0 - 4.0 * (4000.0 - max_y * 100.0));

    // Print the minimum and maximum y values found.
    // %3.2lf formats the double to have a minimum width of 3 and 2 decimal places.
    printf("%3.2lf, %3.2lf\n", min_y, max_y);

    // Print the results of the final calculations.
    // %3.0lf formats the double to have a minimum width of 3 and 0 decimal places (rounded).
    printf("%3.0lf, %3.0lf\n", 4.0 + 0.05 * D1, 4.0 + 0.05 * D2);

    return 0; // Indicate successful execution
}
