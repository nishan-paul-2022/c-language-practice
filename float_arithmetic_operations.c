/*
 * Purpose: Performs basic arithmetic operations (addition, subtraction, multiplication, division) on two floating-point numbers.
 * Topic: Input/Output, Floating-Point Numbers, Basic Arithmetic
 */

#include <stdio.h>

int main()
{
    float num1, num2;

    printf("Enter two floating-point numbers separated by a comma (e.g., 10.5,20.3): ");
    // Using a space in scanf format string to consume any whitespace including newline after first number
    if (scanf("%f, %f", &num1, &num2) != 2)
    {
        printf("Invalid input. Please enter two numbers.\n");
        return 0;
    }

    // Loop to repeatedly print results if both numbers are positive
    // The original code's loop condition (x>0 && y>0) and goto made it an infinite loop
    // if both numbers were positive. This version prints once.
    printf("Results:\n");
    printf("Sum: %.2f\n", num1 + num2);
    printf("Difference: %.2f\n", num1 - num2);
    printf("Product: %.2f\n", num1 * num2);

    if (num2 != 0)
    {
        printf("Quotient: %.2f\n", num1 / num2);
    }
    else
    {
        printf("Quotient: Division by zero is not allowed.\n");
    }

    // The original code had an "ERROR" print statement that was unreachable due to the goto.
    // This version handles invalid input at the beginning.

    return 0;
}
