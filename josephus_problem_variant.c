/*
 * Purpose: Solves a variant of the Josephus problem using modular arithmetic.
 * Topic: Loops, Modular Arithmetic, Problem Solving
 */

#include <stdio.h>

int main() {
    int number_of_test_cases;
    int current_test_case = 0;
    
    // Read number of test cases
    printf("Enter the number of test cases: ");
    if (scanf("%d", &number_of_test_cases) != 1 || number_of_test_cases < 0) {
        printf("Invalid input for number of test cases.\n");
        return 0;
    }

    while (current_test_case < number_of_test_cases) {
        int n;
        int result_position = 0;

        printf("Enter the value of n for test case %d: ", current_test_case + 1);
        if (scanf("%d", &n) != 1 || n < 1) {
            printf("Invalid input for n. Skipping this test case.\n");
            // Clear input buffer in case of invalid input
            while (getchar() != '\n' && !feof(stdin) && !ferror(stdin));
            current_test_case++;
            continue;
        }

        // Loop calculates position based on given formula
        // This pattern is typical for Josephus-like problems where items are removed
        // and position of last remaining item is sought
        for (int x = 2; x <= n; x++) {
            result_position = (result_position + n + 1 - x) % x;
        }

        // Problem's output is 1-indexed, so add 1 to 0-indexed result
        printf("Result for n = %d: %d\n", n, result_position + 1);
        current_test_case++;
    }

    return 0;
}
