/*
 * Purpose: Calculates a final amount based on an initial account type and an input value, applying different base amounts and a percentage increase, then applies discounts based on the final amount.
 * Topic: Conditional Statements (switch, if-else if), Input/Output, Floating-Point Arithmetic
 */

#include <stdio.h>

int main()
{
    int accountType;
    double inputValue;
    double calculatedAmount; // z in original

    printf("Enter account type (1-4) and an input value (e.g., 1, 100.50): ");
    if (scanf("%d, %lf", &accountType, &inputValue) != 2)
    {
        printf("Invalid input format. Please enter an integer and a double separated by a comma.\n");
        return 1;
    }

    switch (accountType)
    {
        case 1:
            calculatedAmount = 1500.0 + inputValue * 1.25;
            break;
        case 2:
            calculatedAmount = 950.0 + inputValue * 1.25;
            break;
        case 3:
            calculatedAmount = 600.0 + inputValue * 1.25;
            break;
        case 4:
            calculatedAmount = 250.0 + inputValue * 1.25;
            break;
        default:
            printf("Error: Invalid account type. Please enter a number between 1 and 4.\n");
            return 1; // Indicate an error
    }

    // Apply discounts based on the calculated amount
    if (calculatedAmount <= 2000.0)
    {
        printf("Final amount: %.2lf\n", calculatedAmount);
    }
    else if (calculatedAmount > 2000.0 && calculatedAmount <= 4000.0)
    {
        printf("Final amount (3%% discount): %.2lf\n", calculatedAmount * 0.97);
    }
    else if (calculatedAmount > 4000.0 && calculatedAmount <= 5000.0)
    {
        // Original code had z*95, which seems like a typo and should be z*0.95 for 5% discount.
        printf("Final amount (5%% discount): %.2lf\n", calculatedAmount * 0.95);
    }
    else if (calculatedAmount > 5000.0)
    {
        printf("Final amount (8%% discount): %.2lf\n", calculatedAmount * 0.92);
    }

    return 0;
}
