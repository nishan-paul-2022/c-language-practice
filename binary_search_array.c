/*
 * Purpose: Implements binary search to find a target element in a sorted array and prints its 1-based index.
 * Topic: Arrays, Searching Algorithms, Binary Search, Loops, Input/Output
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int array_size;
    printf("Enter the size of the sorted array: ");
    if (scanf("%d", &array_size) != 1 || array_size <= 0) {
        printf("Invalid array size. Please enter a positive integer.\n");
        return 0;
    }

    int *array = (int *)malloc(array_size * sizeof(int));
    if (array == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 0;
    }

    printf("Enter %d sorted integers for the array:\n", array_size);
    for (int i = 0; i < array_size; i++) {
        if (scanf("%d", &array[i]) != 1) {
            printf("Invalid input. Exiting.\n");
            free(array);
            return 0;
        }
    }

    while (getchar() != '\n' && !feof(stdin) && !ferror(stdin)); // Clear input buffer

    while (1) {
        int target;
        printf("Enter the number to search for (or Ctrl+D to exit): ");
        if (scanf("%d", &target) != 1) {
            printf("\nExiting search program.\n");
            break;
        }

        int start = 0;
        int end = array_size - 1;
        int found_index = -1; // To store the 1-based index if found
        while (start <= end) {
            int mid = start + (end - start) / 2; // Prevents overflow

            if (array[mid] == target) {
                found_index = mid + 1; // Store 1-based index
                break;
            } else if (array[mid] < target) {
                start = mid + 1;
            } else { // array[mid] > target
                end = mid - 1;
            }
        }

        if (found_index != -1) {
            printf("Element %d found at 1-based index: %d\n", target, found_index);
        } else {
            printf("Element %d doesn't exist in the array.\n", target);
        }
        
        printf("\n");
    }

    free(array);

    return 0;
}
