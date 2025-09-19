/*
 * Purpose: Reads a dynamic array of integers from user input and prints its elements.
 * Topic: Arrays, Input/Output, Dynamic Sizing (via user input)
 */

#include <stdio.h>

int get_array_size() {
    int n;
    printf("Enter the number of elements for the array: ");
    
    if (scanf("%d", &n) != 1) {
        printf("Invalid input for array size. Please enter an integer.\n");
        return -1;
    }
    return n;
}

int read_integer_array(int arr[], int size) {
    printf("Enter %d integers (separated by spaces or newlines):\n", size);
    
    for (int i = 0; i < size; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input at element %d. Please enter integers only.\n", i);
            return -1;
        }
    }

    return 0;
}

void print_array(int arr[], int size) {
    printf("The elements of the array are: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(void) {
    int n = get_array_size();
    
    if (n <= 0) {
        return 0;
    }
    
    int arr[n];
    
    if (read_integer_array(arr, n) == -1) {
        return 0;
    }
    
    print_array(arr, n);
    
    return 0;
}
