/*
 * Purpose: Counts the number of digits in a given non-negative integer.
 * Topic: Integer Arithmetic, Loops, Basic Math
 */

#include <stdio.h>

int main(void) {
    int num_test_cases; // Number of test cases
    int case_num;       // Current test case number

    // Read the number of test cases
    scanf("%d", &num_test_cases);

    // Process each test case
    for (case_num = 1; case_num <= num_test_cases; case_num++) {
        long long int number_to_process; // The number whose digits are to be counted
        int digit_count = 0;             // Counter for the number of digits
        long long int temp_number;       // Temporary variable to avoid modifying the original number

        // Read the number
        scanf("%lld", &number_to_process);

        // Handle the special case of 0
        if (number_to_process == 0) {
            digit_count = 1;
        } else {
            temp_number = number_to_process;
            // Count digits by repeatedly dividing by 10
            while (temp_number > 0) {
                temp_number /= 10;
                digit_count++;
            }
        }

        // Print the result for the current test case
        printf("%d\n", digit_count);
    }

    return 0;
}
