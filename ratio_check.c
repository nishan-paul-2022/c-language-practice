/*
 * Purpose: Calculates a specific ratio from two input values and checks if it matches a target integer value.
 * Topic: Floating-point Arithmetic, Type Casting, Conditional Logic, Math Functions
 */

#include <stdio.h>
#include <math.h>

int main(void) {
    printf("Enter the number of test cases: ");
    int num_test_cases;
    scanf("%d", &num_test_cases);

    for (int i = 0; i < num_test_cases; i++) {
        printf("Enter values for r and s (separated by space): ");
        double r, s;
        scanf("%lf %lf", &r, &s);
        if (r == 0.0) {
            printf("Division by zero.\n");
            continue;
        }

        int ratio = (int)round(s * 100.0 / r);
        if (ratio == 141) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }

    return 0;
}
