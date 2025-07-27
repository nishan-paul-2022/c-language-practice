/*
 * Purpose: Demonstrates the relationship between arrays and pointers by reading and printing array elements using pointer arithmetic.
 * Topic: Arrays, Pointers, Input/Output
 */

#include <stdio.h>
#include <stdlib.h> // For malloc and free

int main()
{
    int size; // n in original
    int *arrayPtr; // p in original, pointer to the array

    printf("Enter the size of the array: ");
    if (scanf("%d", &size) != 1 || size <= 0)
    {
        printf("Invalid array size. Please enter a positive integer.\n");
        return 1;
    }

    // Dynamically allocate memory for the array
    // Using VLA (Variable Length Array) `int a[n]` is a C99 feature,
    // but dynamic allocation with malloc is more flexible and standard across C versions.
    arrayPtr = (int *)malloc(size * sizeof(int));
    if (arrayPtr == NULL)
    {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }

    printf("Enter %d integer elements:\n", size);
    for (int i = 0; i < size; i++)
    {
        // Read elements using pointer arithmetic
        if (scanf("%d", (arrayPtr + i)) != 1)
        {
            printf("Invalid input. Exiting.\n");
            free(arrayPtr);
            return 1;
        }
    }

    printf("Array elements entered:\n");
    for (int i = 0; i < size; i++)
    {
        // Print elements using pointer dereferencing
        printf("%d ", *(arrayPtr + i));
    }
    printf("\n");

    free(arrayPtr); // Free the dynamically allocated memory

    return 0;
}
