/*
 * Purpose: Demonstrates sorting an array of integers using the Bubble Sort algorithm.
 * Topic: Arrays, sorting algorithms, loops, input/output.
 */

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 256 // Define a reasonable buffer size for input

int main(void) {
    int array_size;
    int numbers[BUFFER_SIZE]; // Use a fixed buffer size for simplicity, or dynamically allocate if needed.
    int outer_index, inner_index, temp;

    printf("Enter the number of integers to sort (max %d): ", BUFFER_SIZE);
    // Read the size of the array and validate input
    if (scanf("%d", &array_size) != 1 || array_size <= 0 || array_size > BUFFER_SIZE) {
        printf("Invalid input. Please enter a positive integer up to %d.\\n", BUFFER_SIZE);
        return 0;
    }

    // Consume the newline character left by scanf
    while (getchar() != '\\n');

    printf("Enter %d integers, separated by spaces or newlines:\\n", array_size);
    // Read the integers into the array and validate input for each element
    for (outer_index = 0; outer_index < array_size; outer_index++) {
        if (scanf("%d", &numbers[outer_index]) != 1) {
            printf("Invalid input for integer at position %d. Please enter integers only.\\n", outer_index + 1);
            return 0;
        }
        // Consume the newline character left by scanf after each number
        while (getchar() != '\\n');
    }

    // Bubble Sort algorithm to sort the array in ascending order
    // The outer loop controls the number of passes.
    for (outer_index = 0; outer_index < array_size - 1; outer_index++) {
        // The inner loop performs comparisons and swaps.
        // In each pass, the largest unsorted element "bubbles up" to its correct position.
        for (inner_index = 0; inner_index < array_size - 1 - outer_index; inner_index++) {
            // If the current element is greater than the next element, swap them
            if (numbers[inner_index] > numbers[inner_index + 1]) {
                temp = numbers[inner_index];
                numbers[inner_index] = numbers[inner_index + 1];
                numbers[inner_index + 1] = temp;
            }
        }
    }

    printf("Sorted array (ascending order):\\n");
    // Print the sorted array
    for (outer_index = 0; outer_index < array_size; outer_index++) {
        printf("%d ", numbers[outer_index]);
    }
    printf("\\n"); // Print a newline at the end

    return 0;
}
