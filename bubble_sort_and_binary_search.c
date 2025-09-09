/*
 * Purpose: Demonstrates bubble sort to sort an array and then binary search to find an element in the sorted array.
 * Topic: Sorting Algorithms (Bubble Sort), Searching Algorithms (Binary Search), Arrays, Functions, Input/Output
 */

#include <stdio.h>
#include <stdlib.h>

// Function to perform bubble sort on an integer array
void bubbleSort(int arr[], int size) {
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

// Function to perform binary search on a sorted integer array
// Returns 1-based index if found, -1 otherwise
int binarySearch(int arr[], int size, int target) {
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

int main() {
    int arraySize;
    int *numbers; 
    int targetNumber;

    printf("Enter the size of the array: ");
    if (scanf("%d", &arraySize) != 1 || arraySize <= 0) {
        printf("Invalid array size. Please enter a positive integer.\n");
        return 0;
    }

    // Dynamically allocate memory for the array
    numbers = (int *)malloc(arraySize * sizeof(int));
    if (numbers == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 0;
    }

    printf("Enter %d integer elements for the array:\n", arraySize);
    for (int i = 0; i < arraySize; i++) {
        if (scanf("%d", &numbers[i]) != 1) {
            printf("Invalid input. Exiting.\n");
            free(numbers);
            return 0;
        }
    }

    printf("\nOriginal array elements: ");
    for (int i = 0; i < arraySize; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    // Sort the array using bubble sort
    bubbleSort(numbers, arraySize);
    printf("Array after Bubble Sort: ");
    for (int i = 0; i < arraySize; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    printf("Enter the number to search for: ");
    if (scanf("%d", &targetNumber) != 1) {
        printf("Invalid input for search target. Exiting.\n");
        free(numbers);
        return 0;
    }

    // Perform binary search on the sorted array
    int foundIndex = binarySearch(numbers, arraySize, targetNumber);

    if (foundIndex != -1) {
        printf("Element %d found at 1-based index: %d\n", targetNumber, foundIndex);
    }
    else {
        printf("Element %d DOES NOT EXIST in the array.\n", targetNumber);
    }

    free(numbers); // Free dynamically allocated memory

    return 0;
}
