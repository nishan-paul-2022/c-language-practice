/*
 * Purpose: Calculates the Least Common Multiple (LCM) of two integers.
 * Topic: Loops, Conditional Statements, Arithmetic Operators (Modulo), GCD, LCM
 */

#include <stdio.h>

int calculate_gcd(int num1, int num2) {
    int smaller_num = (num1 < num2) ? num1 : num2;
    int gcd_val;

    for (gcd_val = smaller_num; gcd_val >= 1; gcd_val--) {
        if (num1 % gcd_val == 0 && num2 % gcd_val == 0) {
            break;
        }
    }

    return gcd_val;
}

int calculate_lcm(int num1, int num2) {
    if (num1 == 0 || num2 == 0) {
        return 0;
    }

    int gcd_val = calculate_gcd(num1, num2);
    int lcm_val = (num1 * num2) / gcd_val;
    return lcm_val;
}

void get_numbers_and_calculate_lcm() {
    int num1, num2;
    printf("Enter two integers (e.g., 12 18): ");
    scanf("%d %d", &num1, &num2);

    if (num1 == 0 || num2 == 0) {
        printf("LCM of 0 with any number is 0.\n");
        return;
    }

    int lcm_result = calculate_lcm(num1, num2);
    printf("LCM of %d and %d is %d\n", num1, num2, lcm_result);
}

int main(void) {
    get_numbers_and_calculate_lcm();

    return 0;
}
