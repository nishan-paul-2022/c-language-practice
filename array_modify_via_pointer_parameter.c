/*
 * Purpose: Demonstrates passing an array to a function and modifying its elements, using array size as a parameter, and avoiding global variables.
 * Topic: Arrays, Functions, Pointers, Variable Modification, Dynamic Memory Allocation
 */

#include <stdio.h>
#include <stdlib.h> // For exit(), malloc(), free()

// Function to modify the last element of an integer array by multiplying it by 10.
// Takes the array and its size as parameters.
// Modifies the array element directly via the array parameter (which decays to a pointer).
void multiply_last_element_by_ten(int data_array[], int array_size) {
    // Check for invalid inputs: NULL array or non-positive size
    if (data_array == NULL || array_size <= 0) {
        fprintf(stderr, "Error: Invalid array or size passed to multiply_last_element_by_ten.\n");
        return; // Exit if inputs are invalid
    }

    // Modify the last element of the array
    data_array[array_size - 1] *= 10;
}

int main() {
    int array_size;
    int *data_array = NULL; // Pointer to dynamically allocated array
    int i;

    // Get the size of the array from the user
    printf("Enter the number of elements for the array: ");
    if (scanf("%d", &array_size) != 1) {
        fprintf(stderr, "Error: Invalid input for array size.\n");
        return 1; // Indicate an error
    }
    // Consume any remaining characters on the line after the integer, including the newline
    while (getchar() != '\n');

    // Validate the array size
    if (array_size <= 0) {
        fprintf(stderr, "Error: Array size must be positive.\n");
        return 1;
    }

    // Dynamically allocate memory for the array
    // This avoids relying on VLAs and is more portable.
    data_array = (int *)malloc(array_size * sizeof(int));
    if (data_array == NULL) {
        fprintf(stderr, "Error: Memory allocation failed.\n");
        return 1;
    }

    // Read elements into the array
    printf("Enter %d integers for the array:\n", array_size);
    for (i = 0; i < array_size; ++i) {
        printf("  Element %d: ", i);
        if (scanf("%d", &data_array[i]) != 1) {
            fprintf(stderr, "Error: Invalid input for array element %d.\n", i);
            free(data_array); // Free allocated memory before exiting
            return 1;
        }
        // Consume any remaining characters on the line after the integer
        while (getchar() != '\n');
    }

    // Print the initial value of the last element
    printf("Initial value of the last element (index %d): %d\n", array_size - 1, data_array[array_size - 1]);

    // Call the function to modify the last element of the array
    multiply_last_element_by_ten(data_array, array_size);

    // Print the value of the last element after the function call
    printf("Value of the last element (index %d) after function call: %d\n", array_size - 1, data_array[array_size - 1]);

    // Free the dynamically allocated memory
    free(data_array);

    return 0; // Indicate successful execution
}
