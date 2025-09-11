/*
 * Purpose: Counts elements in an array that are strictly increasing or strictly decreasing relative to all preceding elements.
 * Topic: Arrays, Loops, Conditional Logic
 */

#include <stdio.h>

int main(void) {
    int num_test_cases;
    int i, j;
    int count_monotonic_elements = 0;

    printf("Enter array size: ");
    scanf("%d", &num_test_cases);

    int numbers[num_test_cases];

    for (i = 0; i < num_test_cases; i++) {
        printf("Element %d: ", i);
        scanf("%d", &numbers[i]);
    }

    // Check elements starting from second position
    for (i = 1; i < num_test_cases; i++) {
        int smaller_count = 0; // Count of elements smaller than current
        int larger_count = 0;  // Count of elements larger than current

        // Compare with all preceding elements
        for (j = i - 1; j >= 0; j--) {
            if (numbers[i] > numbers[j]) {
                smaller_count++;
            } else if (numbers[i] < numbers[j]) {
                larger_count++;
            }
        }

        // Check if element maintains monotonic relationship with all previous elements
        if (smaller_count == i || larger_count == i) {
            count_monotonic_elements++;
        }
    }

    printf("%d\n", count_monotonic_elements);

    return 0;
}
