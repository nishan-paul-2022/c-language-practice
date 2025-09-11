#include <stdio.h>

int main(void) {
    int num_test_cases;
    long int n; // Number of terms to consider in the progression (actually n-1 terms are summed)
    long int current_sum; // Stores the sum of the progression
    long int current_term; // Stores the current term in the progression

    // Read the total number of test cases
    scanf("%d", &num_test_cases);

    // Process each test case
    while (num_test_cases > 0) {
        // Read the value of n for the current test case
        scanf("%ld", &n);

        // Initialize variables for the arithmetic progression
        current_sum = 0; // The sum starts at 0
        // The first term of the progression is 2.
        // The loop calculates the sum of the first n-1 terms.
        // The terms are 2, 6, 10, 14, ... (an arithmetic progression with first term 2 and common difference 4)
        current_term = 2; 

        // Calculate the sum of the first n-1 terms of the progression
        // The loop runs from i=1 up to n-1, effectively summing n-1 terms.
        for (long int i = 1; i < n; i++) {
            current_sum += current_term; // Add the current term to the sum
            current_term += 4;           // Calculate the next term by adding the common difference (4)
        }

        // Print the calculated sum for the current test case
        printf("%ld\n", current_sum);
        
        // Decrement the test case counter
        num_test_cases--;
    }

    return 0;
}
