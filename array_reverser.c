/*
 * Purpose: Reads an array of integers, reverses it in-place, and allows accessing an element by index.
 * Topic: Arrays, Reversal Algorithm, Pointers, Loops, Input/Output
 */

#include <stdio.h>
#define ARRAY_SIZE 10

// Function to reverse an array in-place
void reverse_array(int arr[], int size) {
    int temp;
    int start_index = 0;
    int end_index = size - 1;

    // Swap elements from the beginning and end, moving towards the center
    while (start_index < end_index) {
        // Swap arr[start_index] and arr[end_index]
        temp = arr[start_index];
        arr[start_index] = arr[end_index];
        arr[end_index] = temp;

        // Move indices towards the center
        start_index++;
        end_index--;
    }
}

int main() {
    int numbers[ARRAY_SIZE];
    int index_to_access;

    printf("Enter %d integers:\n", ARRAY_SIZE);
    // Read the array elements and validate input
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("Enter element %d: ", i + 1);
        if (scanf("%d", &numbers[i]) != 1) {
            printf("\nError: Invalid input. Please enter an integer.\n");
            return 1; // Indicate an error
        }
    }

    // Reverse the array
    reverse_array(numbers, ARRAY_SIZE);

    printf("\nArray reversed.\n");

    // Prompt user for an index to access an element from the reversed array
    printf("Enter an index (1 to %d) to display an element from the reversed array: ", ARRAY_SIZE);
    if (scanf("%d", &index_to_access) != 1) {
        printf("\nError: Invalid input. Please enter an integer for the index.\n");
        return 1; // Indicate an error
    }

    // Validate the entered index
    if (index_to_access >= 1 && index_to_access <= ARRAY_SIZE) {
        // Display the element at the specified index (adjusting for 0-based indexing)
        printf("Element at index %d (1-based) is: %d\n", index_to_access, numbers[index_to_access - 1]);
    } else {
        printf("Error: Index out of bounds. Please enter an index between 1 and %d.\n", ARRAY_SIZE);
        return 1; // Indicate an error
    }

    return 0;
}
