/*
 * Purpose: Calculates a final amount based on account type and input value, applying base amounts and discounts.
 * Topic: Conditional statements, input/output, floating-point arithmetic
 */

#include <stdio.h>

int main(void) {
    int account_type;
    double cash;
    
    printf("Enter account type (1-4) and an input value (e.g., 1, 100.50): ");

    if (scanf("%d, %lf", &account_type, &cash) != 2) {
        printf("Invalid input format. Please enter an integer and a double separated by a comma.\n");
        return 0;
    }

    double amount;
    switch (account_type) {
        case 1: {
            amount = 1500.0 + cash * 1.25;
            break;
        }
        case 2: {
            amount = 950.0 + cash * 1.25;
            break;
        }
        case 3: {
            amount = 600.0 + cash * 1.25;
            break;
        }
        case 4: {
            amount = 250.0 + cash * 1.25;
            break;
        }
        default: {
            printf("Invalid account type. Please enter a number between 1 and 4.\n");
            return 0;
        }
    }

    if (amount <= 2000.0) {
        printf("Final amount: %.2lf\n", amount);
    } else if (amount > 2000.0 && amount <= 4000.0) {
        printf("Final amount (3%% discount): %.2lf\n", amount * 0.97);
    } else if (amount > 4000.0 && amount <= 5000.0 ) {
        printf("Final amount (5%% discount): %.2lf\n", amount * 0.95);
    } else if (amount > 5000.0) {
        printf("Final amount (8%% discount): %.2lf\n", amount * 0.92);
    }

    return 0;
}
