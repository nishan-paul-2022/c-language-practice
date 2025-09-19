/*
 * Purpose: Demonstrates the relationship between arrays and pointers by reading and printing array elements using pointer arithmetic.
 * Topic: Arrays, Pointers, Input/Output
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int size;
    printf("Enter the size of the array: ");
    if (scanf("%d", &size) != 1 || size <= 0) {
        printf("Invalid array size. Please enter a positive integer.\n");
        return 0;
    }

    
    int *array_pointer = (int *)malloc(size * sizeof(int));
    if (array_pointer == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 0;
    }

    printf("Enter %d integer elements:\n", size);
    for (int i = 0; i < size; i++) {
        
        if (scanf("%d", (array_pointer + i)) != 1) {
            printf("Invalid input. Exiting.\n");
            free(array_pointer);
            return 0;
        }
    }

    printf("Array elements entered: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", *(array_pointer + i)); 
    }

    free(array_pointer);

    printf("\n");

    return 0;
}
