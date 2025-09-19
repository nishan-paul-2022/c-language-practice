/*
 * Purpose: Demonstrates functions using a global variable, performing calculations, and includes error handling for division by zero.
 * Topic: Global Variables, Functions, Arithmetic Operations, Error Handling
 */

#include <stdio.h>

int global_multiplier_divisor;

int calculate_product_with_global(int num1, int num2) {
    int sum = num1 + num2;
    return sum * global_multiplier_divisor;
}

int calculate_division_with_global(int num1, int num2) {
    if (global_multiplier_divisor == 0) {
        fprintf(stderr, "Division by zero is not allowed.\n");
        return -1;
    }
    int sum = num1 + num2;
    return sum / global_multiplier_divisor;
}

int get_user_input(int *num1, int *num2) {
    printf("Enter global multiplier/divisor: ");
    if (scanf("%d", &global_multiplier_divisor) != 1) {
        fprintf(stderr, "Invalid input for the global multiplier/divisor.\n");
        return -1;
    }
    while (getchar() != '\n');

    printf("Enter two integers (e.g., 5, 12): ");
    if (scanf("%d, %d", num1, num2) != 2) {
        fprintf(stderr, "Invalid input format. Please enter two integers separated by a comma.\n");
        return -1;
    }
    while (getchar() != '\n');
    
    return 0;
}

void perform_and_print_calculations(int number1, int number2) {
    int product_result = calculate_product_with_global(number1, number2);
    printf("Product result: %d\n", product_result);

    int division_result = calculate_division_with_global(number1, number2);
    if (division_result == -1) {
        printf("Division result: Error occurred (division by zero).\n");
    } else {
        printf("Division result: %d\n", division_result);
    }
}

int main(void) {
    int number1, number2;

    if (get_user_input(&number1, &number2) == 0) {
        perform_and_print_calculations(number1, number2);
    }

    return 0;
}
