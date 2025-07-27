// Purpose: Calculates a tiered cost based on the number of units consumed.
// Topic: Conditional Logic, Floating-Point Arithmetic

#include <stdio.h>

int main() {
    double units_consumed; // Variable to store the input units
    double total_cost;     // Variable to store the calculated total cost

    // Prompt the user to enter the number of units consumed
    printf("Enter the number of units consumed: ");

    // Read the number of units from the user.
    // Using %lf for double input. Added input validation.
    if (scanf("%lf", &units_consumed) != 1) {
        printf("Invalid input. Please enter a valid number for units.\n");
        return 1; // Indicate an error
    }

    // Calculate the total cost based on tiered rates.
    if (units_consumed <= 200) {
        // Tier 1: For the first 200 units, rate is 0.50 per unit.
        total_cost = units_consumed * 0.50;
    } else if (units_consumed <= 400) {
        // Tier 2: For units between 201 and 400.
        // Cost for the first 200 units is 200 * 0.50 = 100.
        // Rate for units above 200 is 0.65 per unit.
        total_cost = 100.0 + (units_consumed - 200.0) * 0.65;
    } else if (units_consumed <= 600) {
        // Tier 3: For units between 401 and 600.
        // Cost for the first 400 units is 100 (tier 1) + (400-200)*0.65 = 100 + 130 = 230.
        // Rate for units above 400 is 0.80 per unit.
        total_cost = 230.0 + (units_consumed - 400.0) * 0.80;
    } else { // units_consumed > 600
        // Tier 4: For units above 600.
        // Cost for the first 600 units is 230 (tier 2) + (600-400)*0.80 = 230 + 160 = 390.
        // Rate for units above 600 is assumed to be 1.00 per unit (based on the original code's calculation).
        total_cost = 390.0 + (units_consumed - 600.0) * 1.00;
    }

    // Print the calculated total cost.
    // Using %.2lf to display the cost with two decimal places for currency.
    printf("Total cost: %.2lf\n", total_cost);

    return 0; // Indicate successful execution
}
