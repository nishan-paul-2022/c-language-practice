/*
 * Purpose: Demonstrates functions performing arithmetic operations using parameters and returning results, avoiding global variables.
 * Topic: Functions, Parameters, Return Values, Arithmetic Operations, Global Variables (avoidance), Structs
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double sum;
    double difference;
    double product;
    double division;
} calculation_results;

calculation_results perform_arithmetic_operations(double num1, double num2) {
    calculation_results results;

    results.sum = num1 + num2;
    results.difference = num1 - num2;
    results.product = num1 * num2;

    if (num2 == 0.0) {
        fprintf(stderr, "Error: Division by zero attempted.\n");
        results.division = 0.0;
    } else {
        results.division = num1 / num2;
    }

    return results;
}

int get_user_input(double *value1, double *value2) {
    printf("Enter two double values separated by a comma (e.g., 10.5, 5.2): ");
    if (scanf("%lf, %lf", value1, value2) != 2) {
        fprintf(stderr, "Error: Invalid input format. Please enter two double values separated by a comma.\n");
        return -1;
    }
    while (getchar() != '\n');
    return 0;
}

void print_results(calculation_results results, double divisor) {
    printf("Sum: %.2lf\n", results.sum);
    printf("Difference: %.2lf\n", results.difference);
    printf("Product: %.2lf\n", results.product);
    if (divisor != 0.0) {
        printf("Division: %.2lf\n", results.division);
    } else {
        printf("Division: Error (division by zero).\n");
    }
}

int main(void) {
    double value1, value2;
    
    if (get_user_input(&value1, &value2) == 0) {
        calculation_results calculation_results = perform_arithmetic_operations(value1, value2);
        print_results(calculation_results, value2);
    }

    return 0;
}
