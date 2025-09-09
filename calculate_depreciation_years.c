#include <stdio.h>
#include <math.h> // Required for log() function

int main() {
    double initial_cost;        // The initial cost or value of the item.
    double depreciation_rate;   // The annual depreciation rate (e.g., 0.11 for 11%).
    double target_value;        // The target value to reach after depreciation.
    double years_to_depreciate; // The calculated number of years.

    // Read the initial cost, depreciation rate, and target value from input.
    // The format expects values separated by ", ".
    // Example input: 10000.0, 0.10, 5000.0
    if (scanf("%lf, %lf, %lf", &initial_cost, &depreciation_rate, &target_value) != 3) {
        fprintf(stderr, "Invalid input format. Please enter values as 'initial_cost, depreciation_rate, target_value'.\n");
        return 1; // Indicate an error
    }

    // Ensure valid inputs for the calculation:
    // - Initial cost must be positive.
    // - Depreciation rate must be between 0 and 1 (exclusive of 1, as 100% depreciation is problematic).
    // - Target value must be positive and less than or equal to initial cost.
    if (initial_cost <= 0 || depreciation_rate <= 0 || depreciation_rate >= 1 || target_value <= 0 || target_value > initial_cost) {
        fprintf(stderr, "Invalid input values for depreciation calculation.\n");
        // Handle cases where target_value == initial_cost (0 years) or other edge cases if needed.
        // For simplicity, we'll exit if inputs are invalid for the formula.
        return 1; // Indicate an error
    }

    // Calculate the number of years using the formula derived from:
    // target_value = initial_cost * (1 - depreciation_rate)^years
    // (1 - depreciation_rate)^years = target_value / initial_cost
    // years * log(1 - depreciation_rate) = log(target_value / initial_cost)
    // years = log(target_value / initial_cost) / log(1 - depreciation_rate)
    years_to_depreciate = log(target_value / initial_cost) / log(1.0 - depreciation_rate);

    // Print the calculated number of years.
    // %lf is used for printing double values.
    printf("%lf\n", years_to_depreciate);

    return 0;
}
