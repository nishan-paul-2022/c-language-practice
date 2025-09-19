/*
 * Purpose: Simulates compound interest growth over 10 years with an 11% annual interest rate.
 * Topic: Financial Simulation, Compound Interest, Loops, Formatting
 */

#include <stdio.h>

int main(void) {
    float principal_amount = 5000.0f;
    int year = 0;
    float annual_interest_rate = 0.11f; 
    
    printf("=== Compound Interest Calculator ===\n");
    printf("Initial Principal: $%.2f\n", principal_amount);
    printf("Annual Interest Rate: %.2f%%\n", annual_interest_rate * 100);
    printf("\nYear\tBalance\n");
    printf("----\t-------\n");
    
    while (year <= 10) {
        printf("%d\t$%7.2f\n", year, principal_amount);
        principal_amount += principal_amount * annual_interest_rate;
        year++;
    }
    
    return 0;
}
