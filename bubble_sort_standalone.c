/*
 * Purpose: Implements the bubble sort algorithm to sort an array of integers.
 * Topic: Sorting Algorithms (Bubble Sort), Arrays, Functions, Input/Output
 */

#include <stdio.h>
#include <stdlib.h>

int get_array_size() {
    int array_size;

    printf("Enter the size of the array: ");

    if (scanf("%d", &array_size) != 1 || array_size <= 0) {
        printf("Invalid array size. Please enter a positive integer.\n");
        return -1;
    }

    return array_size;
}

int* allocate_array(int size) {
    int *numbers = (int *)malloc(size * sizeof(int));

    if (numbers == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return NULL;
    }

    return numbers;
}

void bubble_sort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

int input_array(int arr[], int size) {
    printf("Enter %d integer elements:\n", size);

    for (int i = 0; i < size; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            fprintf(stderr, "Invalid input. Please enter integers only.\n");
            return -1;
        }
    }
    
    return 0;
}

int main(void) {
    int array_size = get_array_size();
    if (array_size == -1) {
        return 0;
    }

    int *numbers = allocate_array(array_size);
    if (numbers == NULL) {
        return 0;
    }

    int result = input_array(numbers, array_size);
    if (result == 0) {
        printf("Array: ");
        print_array(numbers, array_size);
        
        bubble_sort(numbers, array_size);
        
        printf("Sorted Array: ");
        print_array(numbers, array_size);
    }

    free(numbers);
    return 0;
}
