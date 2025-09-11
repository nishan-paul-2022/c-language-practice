/*
 * Purpose: Implements the bubble sort algorithm to sort an array of integers.
 * Topic: Sorting Algorithms (Bubble Sort), Arrays, Functions, Input/Output
 */

#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int arr[], int size) {
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

void input_array(int arr[], int size) {
    printf("Enter %d integer elements:\n", size);
    for (int i = 0; i < size; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            fprintf(stderr, "Invalid input. Please enter integers only.\n");
            exit(EXIT_FAILURE); // Exit if input is invalid
        }
    }
}

void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(void) {
    int array_size;

    printf("Enter the size of the array: ");
    if (scanf("%d", &array_size) != 1 || array_size <= 0) {
        printf("Invalid array size. Please enter a positive integer.\n");
        return 0;
    }

    int *numbers = (int *)malloc(array_size * sizeof(int)); // Dynamically allocate memory for the array
    if (numbers == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 0;
    }

    input_array(numbers, array_size);

    print_array(numbers, array_size);

    bubble_sort(numbers, array_size);

    print_array(numbers, array_size);

    free(numbers); // Free dynamically allocated memory

    return 0;
}
