/*
 * Purpose: Counts positive and negative numbers from a series of test cases.
 * Topic: Loops, Conditional Statements, Basic I/O
 */

#include <stdio.h>

void count_positive_negative() {
    int num_test_cases;
    int positive_count = 0;
    int negative_count = 0;

    printf("Enter number of test cases: ");
    scanf("%d", &num_test_cases);

    while (num_test_cases--) {
        long long int number;
        printf("Enter number: ");
        scanf("%lld", &number);

        if (number > 0) {
            positive_count++;
        } else if (number < 0) {
            negative_count++;
        }
        // Zero is neither positive nor negative
    }

    printf("Positive count: %d, Negative count: %d\n", positive_count, negative_count);
}

int main(void) {
    count_positive_negative();
    return 0;
}
