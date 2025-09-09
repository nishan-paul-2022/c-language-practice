/*
 * Purpose: Finds pairs of numbers in an array that sum up to a target value,
 *          where the target value is the sum of the maximum and minimum elements in the array.
 * Topic: Arrays, Finding Pairs, Max/Min Elements, Nested Loops, Target Sum
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    int num_elements;           // Number of elements in the input array.
    int index;                  // General loop index.
    int outer_idx, inner_idx;   // Indices for nested loops.
    int numbers[100];           // Array to store input numbers (assuming max 100 elements).
    int max_val, min_val;       // To store the maximum and minimum values in the array.
    int target_sum;             // The target sum (max_val + min_val).
    int found_pair_idx;         // Index of the found pair element.
    int processed_flags[100] = {0}; // To mark elements that have already been part of a pair.

    printf("Enter the number of elements (max 100): ");
    // Read the number of elements.
    if (scanf("%d", &num_elements) != 1 || num_elements <= 0 || num_elements > 100) {
        printf("Invalid input. Please enter a positive integer up to 100.\n");
        return EXIT_FAILURE;
    }

    // Consume the newline character left by scanf.
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    // Read the array elements.
    printf("Enter %d integers (separated by spaces):\n", num_elements);
    for (index = 0; index < num_elements; index++) {
        if (scanf("%d", &numbers[index]) != 1) {
            printf("Invalid input for element at index %d.\n", index);
            return EXIT_FAILURE;
        }
        // Consume the newline character after each integer input.
        while ((c = getchar()) != '\n' && c != EOF);
    }

    // Find the maximum and minimum values in the array.
    if (num_elements > 0) {
        max_val = numbers[0];
        min_val = numbers[0];
        for (index = 1; index < num_elements; index++) {
            if (numbers[index] > max_val) {
                max_val = numbers[index];
            }
            if (numbers[index] < min_val) {
                min_val = numbers[index];
            }
        }
    } else {
        // Handle case of empty array, though num_elements > 0 is checked above.
        printf("No elements to process.\n");
        return 0;
    }

    // Calculate the target sum.
    target_sum = max_val + min_val;
    printf("\nTarget sum (max + min) is: %d\n", target_sum);

    // Find pairs that sum up to the target sum.
    printf("Pairs that sum to %d:\n", target_sum);
    for (outer_idx = 0; outer_idx < num_elements; outer_idx++) {
        // Skip if this element has already been used in a pair.
        if (processed_flags[outer_idx] == 1) {
            continue;
        }

        // Search for a complement element.
        for (inner_idx = outer_idx + 1; inner_idx < num_elements; inner_idx++) {
            // Skip if the inner element has already been used.
            if (processed_flags[inner_idx] == 1) {
                continue;
            }

            // Check if the current pair sums to the target.
            if (numbers[outer_idx] + numbers[inner_idx] == target_sum) {
                printf("%d %d\n", numbers[outer_idx], numbers[inner_idx]);
                // Mark both elements as processed.
                processed_flags[outer_idx] = 1;
                processed_flags[inner_idx] = 1;
                // Break the inner loop since we found a pair for numbers[outer_idx].
                break;
            }
        }
    }

    return 0;
}
