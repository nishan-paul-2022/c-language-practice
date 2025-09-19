/*
 * Purpose: Demonstrates passing an array to a function and modifying its elements, using array size as a parameter, and avoiding global variables.
 * Topic: Arrays, Functions, Pointers, Variable Modification, Dynamic Memory Allocation
 */

#include <stdio.h>
#include <stdlib.h>

void multiply_last_element_by_ten(int data[], int size) {
    if (data == NULL || size <= 0) {
        fprintf(stderr, "Invalid array or size.\n");
        return;
    }

    data[size - 1] *= 10;
}

int main(void) {
    int size;
    
    printf("Enter the number of elements for the array: ");

    if (scanf("%d", &size) != 1) {
        fprintf(stderr, "Invalid input for array size.\n");
        return 0;
    }
    
    while (getchar() != '\n'); 

    if (size <= 0) {
        fprintf(stderr, "Array size must be positive.\n");
        return 0;
    }

    
    int *data = (int *)malloc(size * sizeof(int));
    if (data == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 0;
    }

    
    printf("Enter %d integers for the array:\n", size);
    for (int i = 0; i < size; ++i) {
        printf("Element %d: ", i);
        if (scanf("%d", &data[i]) != 1) {
            fprintf(stderr, "Invalid input for array element %d.\n", i);
            free(data); 
            return 0;
        }

        while (getchar() != '\n'); 
    }

    printf("Initial value of the last element (index %d): %d\n", size - 1, data[size - 1]);

    multiply_last_element_by_ten(data, size);

    printf("Value of the last element (index %d) after function call: %d\n", size - 1, data[size - 1]);

    free(data);

    return 0;
}
