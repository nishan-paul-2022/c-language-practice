/*
 * Purpose: Calculates the Greatest Common Divisor (GCD) and Least Common Multiple (LCM) of two numbers using an alternative approach for GCD.
 * Topic: Number Theory, GCD, LCM, Input Handling
 */

#include <stdio.h>

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
    long int lcm = (abs_a / gcd) * abs_b;
    return lcm;
}

void display_results(long int num1, long int num2, long int gcd_result, long int lcm_result) {
    printf("For %ld and %ld:\n", num1, num2);
    if (gcd_result == 0) {
        printf(" GCD: Undefined (both numbers are 0)\n");
        printf(" LCM: Undefined (both numbers are 0)\n");
    } else {
        printf("  GCD: %ld\n", gcd_result);
        printf("  LCM: %ld\n", lcm_result);
    }
    printf("\n");
}

void process_number_pairs() {
    long int num1, num2;

    printf("Enter pairs of numbers (e.g., '12 18') or press Ctrl+D to exit:\n\n");

    while (scanf("%ld %ld", &num1, &num2) == 2) {
        long int gcd_result = calculate_gcd(num1, num2);
        long int lcm_result = calculate_lcm(num1, num2, gcd_result);
        display_results(num1, num2, gcd_result, lcm_result);
    }
}

int main(void) {
    process_number_pairs();
    return 0;
}
