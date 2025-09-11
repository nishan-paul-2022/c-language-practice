/*
 * Purpose: Demonstrates bubble sort to sort an array and then binary search to find an element in the sorted array.
 * Topic: Sorting Algorithms (Bubble Sort), Searching Algorithms (Binary Search), Arrays, Functions, Input/Output
 */

#include <stdio.h>
#include <stdlib.h>

// Sorts an integer array using bubble sort algorithm
void bubble_sort(int arr[], int size) {
    int i, j, temp;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - 1 - i; j++) { // Optimized inner loop
            if (arr[j] > arr[j + 1]) {
                // Swap elements
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Searches for target in a sorted integer array using binary search
// Returns 1-based index if found, -1 otherwise
int binary_search(int arr[], int size, int target) {
    int low = 0;
    int high = size - 1;
    int mid;

    while (low <= high) {
        mid = low + (high - low) / 2; // Safer way to calculate mid

        if (arr[mid] == target) {
            return mid + 1; // Element found, return 1-based index
        }
        else if (arr[mid] < target) {
            low = mid + 1;
        }
        else // arr[mid] > target
            high = mid - 1;
    }
    
    return -1; // Element not found
}

int main(void) {
    int array_size;
    int *numbers;
    int target_number;

    printf("Enter the size of the array: ");
    if (scanf("%d", &array_size) != 1 || array_size <= 0) {
        printf("Invalid array size. Please enter a positive integer.\n");
        return 0;
    }

    // Dynamically allocate memory for the array
    numbers = (int *)malloc(array_size * sizeof(int));
    if (numbers == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 0;
    }

    printf("Enter %d integer elements for the array:\n", array_size);
    for (int i = 0; i < array_size; i++) {
        if (scanf("%d", &numbers[i]) != 1) {
            printf("Invalid input. Exiting.\n");
            free(numbers);
            return 0;
        }
    }

    printf("\nOriginal array elements: ");
    for (int i = 0; i < array_size; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    bubble_sort(numbers, array_size);
    printf("Array after Bubble Sort: ");
    for (int i = 0; i < array_size; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    printf("Enter the number to search for: ");
    if (scanf("%d", &target_number) != 1) {
        printf("Invalid input for search target. Exiting.\n");
        free(numbers);
        return 0;
    }

    int found_index = binary_search(numbers, array_size, target_number);

    if (found_index != -1) {
        printf("Element %d found at 1-based index: %d\n", target_number, found_index);
    }
    else {
        printf("Element %d DOES NOT EXIST in the array.\n", target_number);
    }

    free(numbers); // Free dynamically allocated memory

    return 0;
}
