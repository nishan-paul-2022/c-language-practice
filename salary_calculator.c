/*
 * Purpose: Calculates salary based on hours worked, with overtime pay.
 * Topic: Conditional Logic, Input/Output, Basic Arithmetic
 */

#include <stdio.h>

double calculate_salary(double hours_worked) {
    if (hours_worked < 0) {
        printf("Hours worked cannot be negative.\n");
        return 0;
    } else if (hours_worked == 40) {
        return 300.0;
    } else if (hours_worked < 40) {
        return 4.0 * hours_worked + 100.0;
    } else {
        return 4.5 * hours_worked + 150.0;
    }
}

int main(void) {
    double hours_worked;
    double salary;

    printf("Enter the number of hours worked: ");
    if (scanf("%lf", &hours_worked) != 1) {
        printf("Invalid input. Please enter a numeric value for hours worked.\n");
        return 0;
    }

    salary = calculate_salary(hours_worked);
    if (hours_worked >= 0) {
        printf("Your calculated salary is: %.2f\n", salary);
    }

    return 0;
}
