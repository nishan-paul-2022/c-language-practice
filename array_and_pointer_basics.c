/*
 * Purpose: Demonstrates the relationship between arrays and pointers by reading and printing array elements using pointer arithmetic.
 * Topic: Arrays, Pointers, Input/Output
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
    int size;
    int *array_pointer;

    printf("Enter the size of the array: ");
    if (scanf("%d", &size) != 1 || size <= 0) {
        printf("Invalid array size. Please enter a positive integer.\n");
        return 0;
    }

    // Dynamically allocate memory for the array
    // Using malloc for dynamic allocation (more flexible than VLA)
    array_pointer = (int *)malloc(size * sizeof(int));
    if (array_pointer == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 0;
    }

    printf("Enter %d integer elements:\n", size);
    for (int i = 0; i < size; i++) {
        // Read elements using pointer arithmetic
        if (scanf("%d", (array_pointer + i)) != 1) {
            printf("Invalid input. Exiting.\n");
            free(array_pointer);
            return 0;
        }
    }

    printf("Array elements entered: ");
    for (int i = 0; i < size; i++) {
        // Print elements using pointer dereferencing
        printf("%d ", *(array_pointer + i));
    }

    free(array_pointer); // Free the dynamically allocated memory

    printf("\n");

    return 0;
}
