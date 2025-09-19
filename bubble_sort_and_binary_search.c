/*
 * Purpose: Demonstrates bubble sort to sort an array and then binary search to find an element in the sorted array.
 * Topic: Sorting Algorithms (Bubble Sort), Searching Algorithms (Binary Search), Arrays, Functions, Input/Output
 */

#include <stdio.h>
#include <stdlib.h>

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

int binary_search(int arr[], int size, int target) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            return mid + 1;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    return -1;
}

int get_array_size() {
    int size;

    printf("Enter the size of the array: ");

    if (scanf("%d", &size) != 1 || size <= 0) {
        printf("Invalid array size. Please enter a positive integer.\n");
        return -1;
    }

    return size;
}

int* allocate_array(int size) {
    int *array = (int *)malloc(size * sizeof(int));

    if (array == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
    }

    return array;
}

int read_array_elements(int arr[], int size) {
    printf("Enter %d integer elements for the array:\n", size);

    for (int i = 0; i < size; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input. Exiting.\n");
            return -1;
        }
    }

    return 0;
}

void display_array(const char *label, int arr[], int size) {
    printf("%s", label);

    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

int get_search_target() {
    int target;

    printf("Enter the number to search for: ");

    if (scanf("%d", &target) != 1) {
        printf("Invalid input for search target. Exiting.\n");
        return -1;
    }

    return target;
}

void display_search_result(int target, int found_index) {
    if (found_index == -1) {
        printf("Element %d doesn't exist in the array.\n", target);
    } else {
        printf("Element %d found at 1-based index: %d\n", target, found_index);
    }
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

    if (read_array_elements(numbers, array_size) == -1) {
        free(numbers);
        return 0;
    }

    display_array("\nOriginal array elements: ", numbers, array_size);

    bubble_sort(numbers, array_size);
    display_array("Array after Bubble Sort: ", numbers, array_size);

    int target_number = get_search_target();
    if (target_number == -1) {
        free(numbers);
        return 0;
    }

    int found_index = binary_search(numbers, array_size, target_number);
    display_search_result(target_number, found_index);

    free(numbers);

    return 0;
}
