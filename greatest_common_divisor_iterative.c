/*
 * Purpose: Calculates the Greatest Common Divisor (GCD) of two integers using an iterative approach.
 * Topic: Loops, Conditional Statements, Arithmetic Operators (Modulo)
 */

#include <stdio.h>

int find_gcd(int num1, int num2) {
    int larger_num = (num1 > num2) ? num1 : num2;
    int smaller_num = (num1 < num2) ? num1 : num2;

    for (int gcd_result = smaller_num; gcd_result >= 1; gcd_result--) {
        if (num1 % gcd_result == 0 && num2 % gcd_result == 0) {
            return gcd_result;
        }
    }
    
    return 1;
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
