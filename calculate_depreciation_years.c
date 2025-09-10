#include <stdio.h>
#include <math.h>

int main() {
    double initial_cost;        // Initial cost of the item
    double depreciation_rate;   // Annual depreciation rate (e.g., 0.11 for 11%)
    double target_value;        // Target value after depreciation
    double years_to_depreciate; // Calculated number of years

    // Read input values in format: initial_cost, depreciation_rate, target_value
    // Example: 10000.0, 0.10, 5000.0
    if (scanf("%lf, %lf, %lf", &initial_cost, &depreciation_rate, &target_value) != 3) {
        fprintf(stderr, "Invalid input format. Please enter values as 'initial_cost, depreciation_rate, target_value'.\n");
        return 0;
    }

    // Validate inputs:
    // - Initial cost must be positive
    // - Depreciation rate must be between 0 and 1
    // - Target value must be positive and less than or equal to initial cost
    if (initial_cost <= 0 || depreciation_rate <= 0 || depreciation_rate >= 1 || target_value <= 0 || target_value > initial_cost) {
        fprintf(stderr, "Invalid input values for depreciation calculation.\n");
        return 0;
    }

    // Calculate years using logarithmic depreciation formula
    years_to_depreciate = log(target_value / initial_cost) / log(1.0 - depreciation_rate);

    // Print the result
    printf("%lf\n", years_to_depreciate);

    return 0;
}
