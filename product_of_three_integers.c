/*
 * Purpose: Compute the product of three integers across multiple test cases.
 * Topic: Integer Arithmetic, Test Case Processing, Basic Input/Output
 */

#include <stdio.h>

int main(void) { 
    int num_test_cases;
    int num1, num2, num3;
    long long product;

    printf("Enter the number of test cases: ");
    scanf("%d", &num_test_cases);

    while (num_test_cases--) {
        printf("Enter three integers: ");
        scanf("%d %d %d", &num1, &num2, &num3);
        product = (long long)num1 * num2 * num3;
        printf("%lld\n", product);
    }

    return 0;
}
