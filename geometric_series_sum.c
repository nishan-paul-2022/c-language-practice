/*
 * Purpose: Calculates the sum of a geometric series (x^0 + x^1 + ... + x^n).
 * Topic: Series Summation, Loops, Math Functions, Input/Output
 */

#include <stdio.h>
#include <math.h>

double calculate_series_sum(double base_x, int exponent_n) {
    double sum_of_powers = 0.0;
    double current_term;

    for (int i = 0; i <= exponent_n; i++) {
        current_term = pow(base_x, i);

        if (fabs(current_term) < 0.0001 && i > 0) {
            printf("Term %d (%.5lf) is very small, stopping summation early.\n", i, current_term);
            break;
        }
        
        sum_of_powers += current_term;
    }

    return sum_of_powers;
}

int get_user_input(double *base_x, int *exponent_n) {
    printf("Enter the base (x) and the maximum exponent (n) (format: 2.5, 5): ");
    
    int input_status = scanf("%lf, %d", base_x, exponent_n);

    if (input_status != 2) {
        printf("Invalid input format. Please enter values like '2.5, 5'.\n");
        while (getchar() != '\n');
        return -1;
    }

    if (*exponent_n < 0) {
        printf("Exponent n cannot be negative.\n");
        return -1;
    }

    return 0;
}

int ask_continue() {
    char another_calculation;
    printf("Type 'y' to perform another calculation? (y/n): ");
    scanf(" %c", &another_calculation);
    return (another_calculation == 'y' || another_calculation == 'Y');
}

int main(void) {
    double base_x;
    int exponent_n;
    double sum_result;

    while (1) {
        if (get_user_input(&base_x, &exponent_n) == -1) {
            continue;
        }

        sum_result = calculate_series_sum(base_x, exponent_n);

        printf("The sum of the series up to x^%d is: %.5lf\n", exponent_n, sum_result);
        
        if (ask_continue() == 0) {
            break;
        }
        printf("\n");
    }

    return 0;
}
