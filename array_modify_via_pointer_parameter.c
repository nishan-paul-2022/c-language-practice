/*
 * Purpose: Demonstrates passing an array to a function and modifying its elements, using array size as a parameter, and avoiding global variables.
 * Topic: Arrays, Functions, Pointers, Variable Modification, Dynamic Memory Allocation
 */

#include <stdio.h>
#include <stdlib.h>

void multiply_last_element_by_ten(int data_array[], int array_size) {
    // Validate inputs
    if (data_array == NULL || array_size <= 0) {
        fprintf(stderr, "Error: Invalid array or size passed to multiply_last_element_by_ten.\n");
        return;
    }

    data_array[array_size - 1] *= 10;
}

int main(void) {
    int array_size;
    int *data_array = NULL;
    int i;

    printf("Enter the number of elements for the array: ");
    if (scanf("%d", &array_size) != 1) {
        fprintf(stderr, "Error: Invalid input for array size.\n");
        return 0;
    }
    // Clear input buffer
    while (getchar() != '\n');

    if (array_size <= 0) {
        fprintf(stderr, "Error: Array size must be positive.\n");
        return 0;
    }

    // Allocate memory for array
    data_array = (int *)malloc(array_size * sizeof(int));
    if (data_array == NULL) {
        fprintf(stderr, "Error: Memory allocation failed.\n");
        return 0;
    }

    // Read elements into the array
    printf("Enter %d integers for the array:\n", array_size);
    for (i = 0; i < array_size; ++i) {
        printf("Element %d: ", i);
        if (scanf("%d", &data_array[i]) != 1) {
            fprintf(stderr, "Error: Invalid input for array element %d.\n", i);
            free(data_array); // Free allocated memory before exiting
            return 0;
        }
        // Clear input buffer
        while (getchar() != '\n');
    }

    printf("Initial value of the last element (index %d): %d\n", array_size - 1, data_array[array_size - 1]);

    multiply_last_element_by_ten(data_array, array_size);

    printf("Value of the last element (index %d) after function call: %d\n", array_size - 1, data_array[array_size - 1]);

    free(data_array);

    return 0;
}
