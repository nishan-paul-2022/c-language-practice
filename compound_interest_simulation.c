#include <stdio.h>

int main() {
    float principal_amount = 5000.0f; // Initial principal amount
    int year = 0;                     // Current year counter
    float annual_interest_rate = 0.11f; // Annual interest rate (11%)

    // Simulate compound interest for 10 years (from year 0 to year 10)
    while (year <= 10) {
        // Print the current year and the amount with formatting
        // %d for integer year, %6.2f for float amount (6 total width, 2 decimal places)
        printf("%d %6.2f\n", year, principal_amount);

        // Calculate the amount for the next year: principal + interest
        // interest = principal * rate
        // new_principal = principal + interest = principal + principal * rate = principal * (1 + rate)
        principal_amount = principal_amount + principal_amount * annual_interest_rate;
        
        // Increment the year counter
        year = year + 1;
    }

    return 0; // Indicate successful execution
}
