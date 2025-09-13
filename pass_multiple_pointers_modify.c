/*
 * Purpose: Demonstrates passing multiple pointers to a function to modify multiple variables in the caller's scope, with corrected signature and type issues.
 * Topic: Pointers, Functions, Pass-by-Reference, Multiple Variable Modification, Error Handling
 */

#include <stdio.h>
#include <stdlib.h>

void perform_arithmetic_operations(double num1, double num2,
                                   double *sum_ptr,
                                   double *diff_ptr,
                                   double *prod_ptr,
                                   double *div_ptr) {
    if (sum_ptr == NULL || diff_ptr == NULL || prod_ptr == NULL || div_ptr == NULL) {
        fprintf(stderr, "Error: NULL pointer passed to function.\n");
        return;
    }

    *sum_ptr = num1 + num2;
    *diff_ptr = num1 - num2;
    *prod_ptr = num1 * num2;

    if (num2 == 0.0) {
        fprintf(stderr, "Error: Division by zero attempted.\n");
        *div_ptr = 0.0;
    } else {
        *div_ptr = num1 / num2;
    }
}

int get_two_doubles(double *value1, double *value2) {
    printf("Enter two double values (e.g., 10.5 5.2): ");
    return scanf("%lf %lf", value1, value2);
}

void clear_input_buffer(void) {
    while (getchar() != '\n');
}

void display_results(double sum, double diff, double prod, double div, double divisor) {
    printf("Sum: %.2lf\n", sum);
    printf("Difference: %.2lf\n", diff);
    printf("Product: %.2lf\n", prod);
    
    if (divisor != 0.0) {
        printf("Division: %.2lf\n", div);
    } else {
        printf("Division: Error (division by zero).\n")
        ;
    }
}

int main(void) {
    double value1, value2;
    double result_sum, result_diff, result_prod, result_div;

    if (get_two_doubles(&value1, &value2) != 2) {
        fprintf(stderr, "Error: Invalid input format.\n");
        return 0;
    }
    clear_input_buffer();

    perform_arithmetic_operations(value1, value2,
                                  &result_sum,
                                  &result_diff,
                                  &result_prod,
                                  &result_div);

    display_results(result_sum, result_diff, result_prod, result_div, value2);

    return 0;
}