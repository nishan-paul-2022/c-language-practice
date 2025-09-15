/*
 * Purpose: Calculates a tiered cost based on the number of units consumed.
 * Topic: Conditional Logic, Floating-Point Arithmetic
 */

#include <stdio.h>

double read_units(const char *prompt) {
    double units;
    printf("%s", prompt);
    if (scanf("%lf", &units) != 1 || units < 0) {
        printf("Invalid input. Please enter a non-negative number for units.\n");
        return -1;
    }
    return units;
}

double calculate_tiered_cost(double units) {
    double cost = 0.0;
    if (units <= 200) {
        cost = units * 0.50;
    } else if (units <= 400) {
        cost = 100.0 + (units - 200.0) * 0.65;
    } else if (units <= 600) {
        cost = 230.0 + (units - 400.0) * 0.80;
    } else {
        cost = 390.0 + (units - 600.0) * 1.00;
    }
    return cost;
}

void print_cost(double cost) {
    printf("Total cost: %.2lf\n", cost);
}

int main(void) {
    double units = read_units("Enter the number of units consumed: ");
    if (units < 0) {
        return 0;
    }

    double total_cost = calculate_tiered_cost(units);

    print_cost(total_cost);

    return 0;
}
