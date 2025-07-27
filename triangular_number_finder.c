// Purpose: Finds the smallest integer 'k' such that the sum of integers from 1 to 'k' (the k-th triangular number) is greater than or equal to a given target sum 'n'.
// Topic: Number Theory, Summation, Loops, Integer Arithmetic

#include <stdio.h>

int main() {
    int num_test_cases; // Number of test cases
    int case_num;       // Current test case number

    // Read the number of test cases
    scanf("%d", &num_test_cases);

    // Process each test case
    for (case_num = 1; case_num <= num_test_cases; case_num++) {
        long long int target_sum;       // The target sum to reach or exceed
        long long int current_number = 1; // The number being added in the current iteration (starts from 1)
        long long int cumulative_sum = 0; // The running sum of numbers

        // Read the target sum
        scanf("%lld", &target_sum);

        // Find the smallest 'k' (represented by current_number) such that the sum 1+2+...+k >= target_sum
        while (cumulative_sum < target_sum) {
            cumulative_sum += current_number;
            // If the cumulative sum has now met or exceeded the target, we stop.
            // The 'current_number' at this point is the 'k' we are looking for.
            if (cumulative_sum >= target_sum) {
                break;
            }
            current_number++;
        }

        // Print the result for the current test case
        printf("%lld\n", current_number);
    }

    return 0; // Indicate successful execution
}
