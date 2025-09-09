// Purpose: Calculates the Euclidean magnitude (length) of a 3D vector.
// Topic: Floating-point Arithmetic, Math Functions (sqrt), Input/Output Formatting

#include <stdio.h>
#include <math.h> // For sqrt function

int main() {
    int num_test_cases; // Number of test cases
    int i;              // Loop counter

    // Read the number of test cases
    scanf("%d", &num_test_cases);

    // Process each test case
    for (i = 0; i < num_test_cases; i++) {
        double component_x, component_y, component_z; // Components of the 3D vector
        double sum_of_squares;                        // x*x + y*y + z*z
        double magnitude;                             // sqrt(sum_of_squares)

        // Read the three components of the vector
        scanf("%lf %lf %lf", &component_x, &component_y, &component_z);

        // Calculate the sum of squares
        sum_of_squares = component_x * component_x + component_y * component_y + component_z * component_z;

        // Calculate the magnitude (Euclidean norm)
        magnitude = sqrt(sum_of_squares);

        // Print the magnitude formatted to two decimal places
        printf("%.2lf\n", magnitude);
    }

    return 0;
}
