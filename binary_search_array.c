/*
 * Purpose: Implements binary search to find a target element in a sorted array and prints its 1-based index.
 * Topic: Arrays, Searching Algorithms, Binary Search, Loops, Input/Output
 */

#include <stdio.h>
#include <stdlib.h> // For malloc and free

int main()
{
    int arraySize; // m in original
    int *array;    // a in original
    int target;    // n in original

    printf("Enter the size of the sorted array: ");
    if (scanf("%d", &arraySize) != 1 || arraySize <= 0)
    {
        printf("Invalid array size. Please enter a positive integer.\n");
        return 1;
    }

    array = (int *)malloc(arraySize * sizeof(int));
    if (array == NULL)
    {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }

    printf("Enter %d sorted integers for the array:\n", arraySize);
    for (int i = 0; i < arraySize; i++)
    {
        if (scanf("%d", &array[i]) != 1)
        {
            printf("Invalid input. Exiting.\n");
            free(array);
            return 1;
        }
    }

    // Clear the input buffer after reading array elements, especially if there's a newline left
    while (getchar() != '\n' && !feof(stdin) && !ferror(stdin));

    while (1) // Loop to allow multiple searches
    {
        printf("Enter the number to search for (or Ctrl+D to exit): ");
        if (scanf("%d", &target) != 1)
        {
            printf("\nExiting search program.\n");
            break; // Exit loop if scanf fails (e.g., EOF)
        }

        int start = 0;
        int end = arraySize - 1;
        int mid;
        int foundIndex = -1; // To store the 1-based index if found

        while (start <= end)
        {
            mid = start + (end - start) / 2; // Safer way to calculate mid to prevent overflow

            if (array[mid] == target)
            {
                foundIndex = mid + 1; // Found, store 1-based index
                break;
            }
            else if (array[mid] < target)
            {
                start = mid + 1;
            }
            else // array[mid] > target
            {
                end = mid - 1;
            }
        }

        if (foundIndex != -1)
        {
            printf("Element %d found at 1-based index: %d\n", target, foundIndex);
        }
        else
        {
            printf("Element %d DOES NOT EXIST in the array.\n", target);
        }
        printf("\n");
    }

    free(array); // Free dynamically allocated memory
    return 0;
}
