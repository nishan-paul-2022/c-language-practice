/*
 * Purpose: Implements the bubble sort algorithm to sort an array of integers.
 * Topic: Sorting Algorithms (Bubble Sort), Arrays, Functions, Input/Output
 */

#include <stdio.h>
#include <stdlib.h>

// Function to perform bubble sort on an integer array
void bubbleSort(int arr[], int size) {
    int i, j, temp;
    for (i = 0; i < size - 1; i++) {
        // Last i elements are already in place, so no need to check them
        for (j = 0; j < size - 1 - i; j++) {
            // Swap if the element found is greater than the next element
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to read integer elements into an array
void inputArray(int arr[], int size) {
    printf("Enter %d integer elements:\n", size);
    for (int i = 0; i < size; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            fprintf(stderr, "Invalid input. Please enter integers only.\n");
            exit(EXIT_FAILURE); // Exit if input is invalid
        }
    }
}

// Function to print integer elements of an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arraySize;

    printf("Enter the size of the array: ");
    if (scanf("%d", &arraySize) != 1 || arraySize <= 0) {
        printf("Invalid array size. Please enter a positive integer.\n");
        return 0;
    }

    // Dynamically allocate memory for the array
    int *numbers = (int *)malloc(arraySize * sizeof(int));
    if (numbers == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 0;
    }

    inputArray(numbers, arraySize);

    printf("Original array: ");
    printArray(numbers, arraySize);

    bubbleSort(numbers, arraySize);

    printf("Sorted array (Bubble Sort): ");
    printArray(numbers, arraySize);

    free(numbers); // Free dynamically allocated memory

    return 0;
}
