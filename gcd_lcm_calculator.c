/*
 * Purpose: Calculates the Greatest Common Divisor (GCD) and Least Common Multiple (LCM) of two numbers.
 * Topic: Number Theory, Euclidean Algorithm, Input Handling
 */

#include <stdio.h>
#include <stdlib.h>

long int calculate_gcd(long int a, long int b) {
    if (a < 0) {
        a = -a;
    }
    if (b < 0) {
        b = -b;
    }

    if (a == 0 && b == 0) {
        return 0;
    }
    if (a == 0) {
        return b;
    }
    if (b == 0) {
        return a;
    }

    while (b) {
        long int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

long int calculate_lcm(long int a, long int b, long int gcd) {
    if (gcd == 0) {
        return 0;
    }
    long int abs_a = (a < 0) ? -a : a;
    long int abs_b = (b < 0) ? -b : b;
    return (abs_a / gcd) * abs_b; // Divide first to prevent overflow
}

int main(void) {
    long int num1, num2;
    long int gcd_result, lcm_result;

    printf("Enter pairs of numbers (format: 12, 18) or press Ctrl+D/Ctrl+Z to exit:\n");

    while (scanf("%ld, %ld", &num1, &num2) == 2) {
        gcd_result = calculate_gcd(num1, num2);
        lcm_result = calculate_lcm(num1, num2, gcd_result);

        printf("For %ld and %ld:\n", num1, num2);
        if (gcd_result == 0) {
            printf("  GCD: Undefined (both numbers are 0)\n");
            printf("  LCM: Undefined (both numbers are 0)\n");
        } else {
            printf("  GCD: %ld\n", gcd_result);
            printf("  LCM: %ld\n", lcm_result);
        }
    }

    if (ferror(stdin)) {
        perror("Error reading input");
        return 0;
    }

    printf("Exiting program.\n");
    return 0;
}
