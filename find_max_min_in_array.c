#include <stdio.h>

int main() {
    int num_test_cases;
    int numbers[5]; // Array to store 5 integers
    int max_val, min_val; // Variables to store the maximum and minimum values

    // Read the total number of test cases
    scanf("%d", &num_test_cases);

    // Process each test case
    while (num_test_cases--) {
        // Read 5 integers into the array
        for (int i = 0; i < 5; i++) {
            // Read an integer and consume the character immediately following it
            // This helps in handling input where numbers might be separated by spaces or newlines
            scanf("%d%*c", &numbers[i]);
        }

        // Initialize max_val and min_val with the first element of the array
        max_val = numbers[0];
        min_val = numbers[0];

        // Iterate through the array to find the maximum and minimum values
        for (int i = 1; i < 5; i++) {
            // Update max_val if the current element is greater
            if (numbers[i] > max_val) {
                max_val = numbers[i];
            }
            // Update min_val if the current element is smaller
            if (numbers[i] < min_val) {
                min_val = numbers[i];
            }
        }

        // Print the maximum and minimum values for the current test case
        printf("%d %d\n", max_val, min_val);
    }

    return 0;
}
