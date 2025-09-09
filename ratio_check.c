// Purpose: Calculates a specific ratio from two input values and checks if it matches a target integer value.
// Topic: Floating-point Arithmetic, Type Casting, Conditional Logic, Math Functions (round)

#include <stdio.h>
#include <math.h> // For round() function

int main() {
    int num_test_cases; // Number of test cases
    int i;              // Loop counter

    // Read the number of test cases
    scanf("%d", &num_test_cases);

    // Process each test case
    for (i = 0; i < num_test_cases; i++) {
        double value_r, value_s; // Input floating-point values
        double calculated_ratio; // Result of s * 100 / r
        int integer_ratio;       // Rounded integer value of the ratio

        // Read the two floating-point values
        scanf("%lf %lf", &value_r, &value_s);

        // Check for division by zero
        if (value_r == 0.0) {
            printf("Error: Division by zero (value_r is 0).\n");
            continue; // Skip to the next test case
        }

        // Calculate the ratio
        calculated_ratio = value_s * 100.0 / value_r;

        // Round the floating-point result to the nearest integer before casting
        // This is more robust than simple truncation (int)
        integer_ratio = (int)round(calculated_ratio);

        // Check if the rounded integer ratio matches the target value
        if (integer_ratio == 141) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }

    return 0;
}
