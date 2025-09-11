/*
 * Purpose: Reads a specified number of integers into an array and prints them in groups of three.
 * Topic: Arrays, Loops, Input/Output, Grouping Elements
 */

#include <stdio.h>

int main(void) {
    int num_elements;
    int element_index;
    int num_groups;

    printf("Enter the number of elements: ");
    // Read the number of elements and validate input
    if (scanf("%d", &num_elements) != 1) {
        printf("Error: Invalid input. Please enter an integer for the number of elements.\n");
        return 0;
    }

    // Ensure there are enough elements to form at least one group of three
    if (num_elements < 3) {
        printf("Please enter at least 3 elements to form groups of three.\n");
        // Optionally, read and discard remaining input if any
        return 0; // Exit gracefully if not enough elements
    }

    // Declare array using Variable Length Array (VLA) feature
    int elements[num_elements];

    printf("Enter %d integers:\n", num_elements);
    // Read the array elements
    for (element_index = 0; element_index < num_elements; element_index++) {
        printf("Enter element %d: ", element_index + 1);
        // Read integer and consume the character after it (e.g., newline)
        if (scanf("%d%*c", &elements[element_index]) != 1) {
            printf("\nError: Invalid input for element %d. Please enter an integer.\n", element_index + 1);
            return 0;
        }
    }

    // Calculate the number of full groups of three
    num_groups = num_elements / 3;
    element_index = 0; // Reset index for printing groups

    printf("\nElements printed in groups of three:\n");
    // Print elements in groups of three
    for (int group_count = 0; group_count < num_groups; group_count++) {
        printf("%d %d %d\n", elements[element_index], elements[element_index + 1], elements[element_index + 2]);
        element_index += 3; // Move to the start of the next group
    }

    // Note: If num_elements is not a multiple of 3, the remaining elements are not printed.
    // This behavior matches the original code's logic.

    return 0;
}
