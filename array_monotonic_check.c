/*
 * Purpose: Counts elements in an array that are strictly increasing or strictly decreasing relative to all preceding elements.
 * Topic: Arrays, Loops, Conditional Logic
 */

#include <stdio.h>

int main() {
    int num_test_cases;
    int i, j;
    int count_monotonic_elements = 0;

    // Read the number of test cases (array size)
    scanf("%d", &num_test_cases);

    // Declare a Variable Length Array (VLA) - C99 feature
    int numbers[num_test_cases];

    // Read the array elements
    for (i = 0; i < num_test_cases; i++) {
        scanf("%d", &numbers[i]);
    }

    // Iterate through the array starting from the second element
    for (i = 1; i < num_test_cases; i++) {
        int smaller_count = 0; // Count of preceding elements smaller than current
        int larger_count = 0;  // Count of preceding elements larger than current

        // Compare current element with all preceding elements
        for (j = i - 1; j >= 0; j--) {
            if (numbers[i] > numbers[j]) {
                smaller_count++;
            } else if (numbers[i] < numbers[j]) {
                larger_count++;
            }
        }

        // If all preceding elements are either strictly smaller or strictly larger,
        // then the current element maintains a monotonic relationship with all previous ones.
        if (smaller_count == i || larger_count == i) {
            count_monotonic_elements++;
        }
    }

    // Print the total count of such elements
    printf("%d\n", count_monotonic_elements);

    return 0;
}
