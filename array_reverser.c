/*
 * Purpose: Reads an array of integers, reverses it in-place, and allows accessing an element by index.
 * Topic: Arrays, Reversal Algorithm, Pointers, Loops, Input/Output
 */

#include <stdio.h>
#define ARRAY_SIZE 10

void reverse_array(int arr[], int size) {
    int start_index = 0;
    int end_index = size - 1;

    
    while (start_index < end_index) {
        int temp = arr[start_index];
        arr[start_index] = arr[end_index];
        arr[end_index] = temp;
        start_index++;
        end_index--;
    }
}

int main(void) {
    int numbers[ARRAY_SIZE];

    printf("Enter %d integers:\n", ARRAY_SIZE);

    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("Enter element %d: ", i + 1);
        if (scanf("%d", &numbers[i]) != 1) {
            printf("\nInvalid input. Please enter an integer.\n");
            return 0;
        }
    }

    reverse_array(numbers, ARRAY_SIZE);

    printf("\nArray reversed.\n");

    
    printf("Enter an index (1 to %d) to display an element from the reversed array: ", ARRAY_SIZE);
    int index_to_access;
    if (scanf("%d", &index_to_access) != 1) {
        printf("\nInvalid input. Please enter an integer for the index.\n");
        return 0;
    }

    
    if (index_to_access >= 1 && index_to_access <= ARRAY_SIZE) {
        printf("Element at index %d (1-based) is: %d\n", index_to_access, numbers[index_to_access - 1]);
    } else {
        printf("Index out of bounds. Please enter an index between 1 and %d.\n", ARRAY_SIZE);
    }

    return 0;
}
