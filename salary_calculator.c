#include <stdio.h>

// Purpose: Calculates salary based on hours worked, with overtime pay.
// Topic: Conditional Logic, Input/Output, Basic Arithmetic

int main(void) {
    double hours_worked;
    double salary;

    // Prompt user for input
    printf("Enter the number of hours worked: ");
    
    // Read input and check for valid entry
    if (scanf("%lf", &hours_worked) != 1) {
        printf("Invalid input. Please enter a numeric value for hours worked.\n");
        return 0;
    }

    // Calculate salary based on hours worked
    if (hours_worked < 0) {
        printf("Hours worked cannot be negative.\n");
        return 0;
    } else if (hours_worked == 40) {
        // Standard pay for exactly 40 hours
        salary = 300.0;
    } else if (hours_worked < 40) {
        // Regular pay for less than 40 hours (assuming a base rate calculation, though the original implies a fixed amount)
        // The original code implies a fixed salary of 4*x + 100 for x < 40.
        // Let's stick to the original logic for now, but make it clearer.
        salary = 4.0 * hours_worked + 100.0;
    } else { // hours_worked > 40
        // Overtime pay for more than 40 hours
        salary = 4.5 * hours_worked + 150.0;
    }

    // Print the calculated salary
    printf("Your calculated salary is: %.2f\n", salary); // Using %.2f for currency

    return 0;
}
