/*
 * Purpose: Reads 'n' integers into an array and finds the maximum element among them.
 *          It uses a sorting-like approach (similar to bubble sort's pass for finding max).
 * Topic: Arrays, Loops, Conditional Statements, Finding Maximum
 */

#include <stdio.h>

void read_array_elements(int arr[], int size) {
    printf("Enter %d integer elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
}

int find_maximum(const int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main(void) {
    int num_elements;

    printf("Enter the number of elements: ");
    scanf("%d", &num_elements);

    if (num_elements <= 0) {
        printf("Number of elements must be positive.\n");
        return 0;
    }

    int arr[num_elements];

    read_array_elements(arr, num_elements);

    int max_element = find_maximum(arr, num_elements);

    printf("The maximum element in the array is: %d\n", max_element);

    return 0;
}
