/*
 * Purpose: Calculates and prints the GCD and LCM of two integers iteratively.
 * Topic: Arithmetic Operations, Iteration, GCD, LCM
 */

#include <stdio.h>
#include <stdlib.h>

long long calculate_gcd(long long num1, long long num2) {
    if (num1 < 0) num1 = -num1;
    if (num2 < 0) num2 = -num2;

    if (num1 == 0 && num2 == 0) return 0;
    if (num1 == 0) return num2;
    if (num2 == 0) return num1;

    long long temp;
    while (num2) {
        temp = num2;
        num2 = num1 % num2;
        num1 = temp;
    }
    return num1;
}

long long calculate_lcm(long long num1, long long num2, long long gcd_val) {
    if (num1 == 0 || num2 == 0) {
        return 0;
    }
    if (gcd_val == 0) return 0;

    unsigned long long product = (unsigned long long)num1 * num2;
    return (long long)(product / gcd_val);
}

int main(void) {
    long long number1, number2;
    long long gcd_result, lcm_result;

    while (1) {
        printf("\nEnter two integers (format: 12, 18) or type '0, 0' to exit: ");

        if (scanf("%lld, %lld", &number1, &number2) != 2) {
            fprintf(stderr, "Invalid input format. Please enter two integers separated by a comma.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        if (number1 == 0 && number2 == 0) {
            printf("Exiting program.\n");
            break;
        }

        gcd_result = calculate_gcd(number1, number2);
        lcm_result = calculate_lcm(number1, number2, gcd_result);

        printf("GCD: %lld, LCM: %lld\n", gcd_result, lcm_result);
    }

    return 0;
}
