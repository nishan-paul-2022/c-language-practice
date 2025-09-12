/*
 * Purpose: Demonstrates functions using a global variable, performing calculations, and includes error handling for division by zero.
 * Topic: Global Variables, Functions, Arithmetic Operations, Error Handling
 */

#include <stdio.h>

// Using global variables is generally discouraged.
int global_multiplier_divisor;

// Calculates product using a global multiplier.
int calculate_product_with_global(int num1, int num2) {
    int sum = num1 + num2;
    int product = sum * global_multiplier_divisor;
    return product;
}

// Calculates division using a global divisor.
int calculate_division_with_global(int num1, int num2) {
    if (global_multiplier_divisor == 0) {
        fprintf(stderr, "Error: Division by zero is not allowed.\n");
        return -1; // Error
    }
    int sum = num1 + num2;
    return sum / global_multiplier_divisor;
}

void get_user_input(int *num1, int *num2) {
    printf("Enter global multiplier/divisor: ");
    if (scanf("%d", &global_multiplier_divisor) != 1) {
        fprintf(stderr, "Error: Invalid input for the global multiplier/divisor.\n");
        global_multiplier_divisor = 1; // Default to safe value
    }
    while (getchar() != '\n'); // Clear buffer

    printf("Enter two integers (e.g., 5, 12): ");
    if (scanf("%d, %d", num1, num2) != 2) {
        fprintf(stderr, "Error: Invalid input format. Please enter two integers separated by a comma.\n");
        *num1 = 0; // Default
        *num2 = 0;
    }
    while (getchar() != '\n'); // Clear buffer
}

void perform_and_print_calculations(int number1, int number2) {
    int product_result = calculate_product_with_global(number1, number2);
    printf("Product result: %d\n", product_result);

    int division_result = calculate_division_with_global(number1, number2);
    if (division_result != -1) {
        printf("Division result: %d\n", division_result);
    } else {
        printf("Division result: Error occurred (division by zero).\n");
    }
}

int main(void) {
    int number1, number2;

    get_user_input(&number1, &number2);
    perform_and_print_calculations(number1, number2);

    return 0;
}
