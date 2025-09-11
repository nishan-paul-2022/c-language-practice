/*
 * Purpose: Simulates compound interest growth over 10 years with an 11% annual interest rate.
 * Topic: Financial Simulation, Compound Interest, Loops, Formatting
 */

#include <stdio.h>

int main(void) {
    float principal_amount = 5000.0f; // Initial principal amount ($5000)
    int year = 0;                     // Year counter (0-10)
    float annual_interest_rate = 0.11f; // Annual interest rate (11%)
    
    printf("Compound Interest Simulation\n");
    printf("Initial Principal: $%.2f\n", principal_amount);
    printf("Annual Interest Rate: %.2f%%\n", annual_interest_rate * 100);
    printf("\nYear\tBalance\n");
    
    // Simulate compound interest growth for 11 years (year 0 through year 10)
    while (year <= 10) {
        // Print current year and account balance with formatting
        // %d for integer year, %6.2f for float amount (6 total width, 2 decimal places)
        printf("%d\t$%6.2f\n", year, principal_amount);
        
        // Calculate next year's balance: principal + (principal * interest rate)
        // Formula: new_balance = principal * (1 + interest_rate)
        principal_amount = principal_amount + principal_amount * annual_interest_rate;
        
        // Increment year counter
        year = year + 1;
    }
    
    return 0;
}
