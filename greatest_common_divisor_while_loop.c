/*
 * Purpose: Calculates the Greatest Common Divisor (GCD) of two integers using a while loop.
 * Topic: Loops, Conditional Operator (Ternary), Arithmetic Operators (Modulo)
 */

#include <stdio.h>

int find_gcd(int num1, int num2) {
    int current_divisor = (num1 < num2) ? num1 : num2;

    while (current_divisor >= 1) {
        if (num1 % current_divisor == 0 && num2 % current_divisor == 0) {
            break;
        }
        current_divisor--;
    }
    return current_divisor;
}

int main(void) {
    int num1, num2;
    int gcd_result;

    printf("Enter two integers (format: 48 18): ");
    scanf("%d %d", &num1, &num2);

    gcd_result = find_gcd(num1, num2);

    printf("The Greatest Common Divisor (GCD) of %d and %d is: %d\n", num1, num2, gcd_result);

    return 0;
}
