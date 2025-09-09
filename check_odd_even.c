/*
 * Purpose: Reads a series of numbers and determines if each number is odd or even.
 * Topic: Input/Output, Loops, Conditional Statements, Modulo Operator
 */

#include <stdio.h>

int main() {
    int num_test_cases; // Variable to store the total number of test cases.
    int test_case_index;
    int number_to_check; // Variable to store the number read for each test case.

    // Prompt the user to enter the number of test cases.
    printf("Enter the number of test cases: ");
    // Read the number of test cases.
    if (scanf("%d", &num_test_cases) != 1) {
        printf("Error reading number of test cases.\n");
        return 0;
    }

    // Loop through each test case.
    for (test_case_index = 0; test_case_index < num_test_cases; test_case_index++) {
        // Prompt the user to enter a number for the current test case.
        printf("Enter number for test case %d: ", test_case_index + 1);
        // Read the number for the current test case.
        if (scanf("%d", &number_to_check) != 1) {
            printf("Error reading number for test case %d.\n", test_case_index + 1);
            // Optionally, you could break or continue here. For simplicity, we'll continue.
            continue;
        }

        // Check if the number is odd or even using the modulo operator.
        // A number is odd if the remainder when divided by 2 is 1 (or -1 for negative numbers).
        // A number is even if the remainder when divided by 2 is 0.
        if (number_to_check % 2 != 0) {
            printf("Result for test case %d: Odd\n", test_case_index + 1);
        } else {
            printf("Result for test case %d: Even\n", test_case_index + 1);
        }
    }

    return 0;
}
