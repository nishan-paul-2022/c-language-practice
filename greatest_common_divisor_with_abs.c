/*
 * Purpose: Calculates the Greatest Common Divisor (GCD) of two integers, handling negative inputs
 *          by taking their absolute values. Uses an iterative approach.
 * Topic: Loops, Conditional Statements, Arithmetic Operators (Modulo), Absolute Value
 */

#include <stdio.h>
#include <stdlib.h>

int handle_zero_cases(int num1, int num2, int abs_num1, int abs_num2) {
    if (abs_num1 == 0 && abs_num2 == 0) {
        printf("GCD of 0 and 0 is undefined (or 0 by some definitions).\n");
        return 0;
    } else if (abs_num1 == 0) {
        printf("The Greatest Common Divisor (GCD) of %d and %d is: %d\n", num1, num2, abs_num2);
        return 0;
    } else if (abs_num2 == 0) {
        printf("The Greatest Common Divisor (GCD) of %d and %d is: %d\n", num1, num2, abs_num1);
        return 0;
    }
    return -1;
}

int find_gcd(int abs_num1, int abs_num2) {
    int smaller_abs_num = (abs_num1 < abs_num2) ? abs_num1 : abs_num2;

    for (int gcd_result = smaller_abs_num; gcd_result >= 1; gcd_result--) {
        if (abs_num1 % gcd_result == 0 && abs_num2 % gcd_result == 0) {
            return gcd_result;
        }
    }
    
    return 1;
}

int main(void) {
    printf("Enter two integers (format: -48 18): ");
    int num1, num2;
    scanf("%d %d", &num1, &num2);

    int abs_num1 = abs(num1);
    int abs_num2 = abs(num2);

    if (handle_zero_cases(num1, num2, abs_num1, abs_num2) == 0) {
        return 0;
    }

    int gcd_result = find_gcd(abs_num1, abs_num2);

    printf("The Greatest Common Divisor (GCD) of %d and %d is: %d\n", num1, num2, gcd_result);

    return 0;
}
