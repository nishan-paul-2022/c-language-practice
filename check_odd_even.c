/*
 * Purpose: Reads a series of numbers and determines if each number is odd or even.
 * Topic: Input/Output, Loops, Conditional Statements, Modulo Operator
 */

#include <stdio.h>

int main(void) {
    int num_test_cases; // Number of test cases
    int test_case_index;
    int number_to_check; // Number to check for odd/even

    // Get number of test cases
    printf("Enter the number of test cases: ");
    if (scanf("%d", &num_test_cases) != 1) {
        printf("Error reading number of test cases.\n");
        return 0;
    }

    // Process each test case
    for (test_case_index = 0; test_case_index < num_test_cases; test_case_index++) {
        // Get number for current test case
        printf("Enter number for test case %d: ", test_case_index + 1);
        if (scanf("%d", &number_to_check) != 1) {
            printf("Error reading number for test case %d.\n", test_case_index + 1);
            continue;
        }

        // Check if number is odd or even using modulo operator
        // Number is odd if remainder when divided by 2 is non-zero
        // Number is even if remainder when divided by 2 is zero
        if (number_to_check % 2 != 0) {
            printf("Result for test case %d: Odd\n", test_case_index + 1);
        } else {
            printf("Result for test case %d: Even\n", test_case_index + 1);
        }
    }

    return 0;
}
