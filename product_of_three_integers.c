#include <stdio.h>

int main(void) {
    int num_test_cases;
    int num1, num2, num3;
    long long int product; // Use long long to prevent potential overflow

    // Read the total number of test cases
    scanf("%d", &num_test_cases);

    // Process each test case
    while (num_test_cases--) {
        // Read the three integers for the current test case
        scanf("%d %d %d", &num1, &num2, &num3);

        // Calculate the product
        // Cast to long long before multiplication to avoid intermediate overflow
        product = (long long int)num1 * num2 * num3;

        // Print the result for the current test case
        printf("%lld\n", product);
    }

    return 0;
}
