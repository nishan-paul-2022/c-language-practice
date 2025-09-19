/*
 * Purpose: Calculates the Greatest Common Divisor (GCD) of two integers using a recursive function.
 * Topic: Recursion, Arithmetic Operators (Modulo)
 */

#include <stdio.h>

int find_gcd_recursive(int num1, int num2) {
    if (num2 == 0) {
        return num1;
    }
    return find_gcd_recursive(num2, num1 % num2);
}

int main(void) {
    int number1, number2;
    int gcd_result;

    printf("Enter two integers (format: 48 18): ");
    scanf("%d %d", &number1, &number2);

    if (number1 < 0) {
        number1 = -number1;
    }
    if (number2 < 0) {
        number2 = -number2;
    }

    if (number1 == 0 && number2 == 0) {
        printf("GCD of 0 and 0 is undefined (or 0 by some definitions).\n");
        return 0;
    }

    gcd_result = find_gcd_recursive(number1, number2);

    printf("The Greatest Common Divisor (GCD) of %d and %d is: %d\n", number1, number2, gcd_result);

    return 0;
}
