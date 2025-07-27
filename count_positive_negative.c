#include <stdio.h>

int main() {
    int num_test_cases;
    int positive_count = 0;
    int negative_count = 0;

    // Read the total number of test cases
    scanf("%d", &num_test_cases);

    // Process each test case
    while (num_test_cases--) {
        long long int number;
        // Read the number for the current test case
        scanf("%lld", &number);

        // Check if the number is positive or negative and update counts
        if (number > 0) {
            positive_count++;
        } else if (number < 0) {
            negative_count++;
        }
        // Note: Zero is neither positive nor negative, so it's not counted.
    }

    // Print the final counts of positive and negative numbers
    printf("%d %d\n", positive_count, negative_count);

    return 0;
}
