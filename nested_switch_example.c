/*
 * Purpose: Demonstrates the use of nested switch statements to handle different input ranges and values.
 * Topic: Switch Statements, Nested Control Flow, Type Casting (double to int)
 */

#include <stdio.h>
#include <stdlib.h>

double get_employee_hours() {
    double hours;
    printf("Enter hours worked this week: ");
    if (scanf("%lf", &hours) != 1 || hours < 0 || hours > 168) {
        printf("Invalid input. Hours must be between 0-168.\n");
        return -1;
    }
    return hours;
}

double get_hourly_rate() {
    double rate;
    printf("Enter hourly rate ($): ");
    if (scanf("%lf", &rate) != 1 || rate < 0) {
        printf("Invalid hourly rate.\n");
        return -1;
    }
    return rate;
}

int get_employee_level() {
    int level;
    printf("Enter employee level (1=Junior, 2=Senior, 3=Manager): ");
    if (scanf("%d", &level) != 1) {
        printf("Invalid employee level.\n");
        return -1;
    }
    return level;
}

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

double calculate_overtime_rate(int employee_level) {
    switch (employee_level) {
        case 1: {
            printf("Junior employee: Standard overtime rate (1.5x)\n");
            return 1.5;
        }
        case 2: {
            printf("Senior employee: Enhanced overtime rate (1.75x)\n");
            return 1.75;
        }
        case 3: {
            printf("Manager: Premium overtime rate (2.0x)\n");
            return 2.0;
        }
        default: {
            printf("Unknown level: Using standard overtime rate (1.5x)\n");
            return 1.5;
        }
    }
}

int calculate_payroll(int hours_category) {
    switch (hours_category) {
        case 1:
        case 2:
        case 3:
        case 4: {
            printf("Regular hours (under 40) - No overtime needed.\n");
            return 0;
        }
        case 5:
        case 6: {
            printf("Overtime hours detected (40+ hours).\n");
            int employee_level = get_employee_level();
            if (employee_level == -1) {
                return -1;
            }
            clear_input_buffer();
            
            double overtime_multiplier = calculate_overtime_rate(employee_level);
            printf("Overtime will be calculated at %.1fx rate.\n", overtime_multiplier);
            return 0;
        }
        default: {
            printf("Excessive hours (60+) - Please review with HR.\n");
            return 0;
        }
    }
}

int main(void) {
    printf("=== Payroll Processing System ===\n");
    
    double hours_worked = get_employee_hours();
    if (hours_worked == -1) {
        return 1;
    }
    
    clear_input_buffer();
    
    int hours_category = (int)(hours_worked / 10.0) + 1;
    
    printf("\nProcessing payroll for %.1f hours worked...\n", hours_worked);
    
    if (calculate_payroll(hours_category) == -1) {
        printf("Payroll processing failed.\n");
        return 1;
    }
    
    printf("Payroll processing completed.\n\n");
    return 0;
}
