/*
 * Purpose: Reads integers into an array until a non-integer input is entered,
 *          then reverses the array and prints its elements.
 * Topic: Arrays, Input Termination, Reversal Algorithm, Loops, Input/Output
 */

#include <stdio.h>

#define MAX_ARRAY_SIZE 100

// Function to reverse an array in-place
void reverse_array(int arr[], int size) {
    int start_index = 0;
    int end_index = size - 1;

    // Swap elements from the beginning and end, moving towards the center
    while (start_index < end_index) {
        int temp = arr[start_index];
        arr[start_index] = arr[end_index];
        arr[end_index] = temp;

        // Move indices towards the center
        start_index++;
        end_index--;
    }
}

int main(void) {
    int numbers[MAX_ARRAY_SIZE];

    printf("Enter integers (or any non-integer to stop and process):\n");

    // Read integers until a non-integer is entered or max size is reached
    int count = 0;
    while (count < MAX_ARRAY_SIZE) {
        printf("Enter element %d: ", count + 1);
        int input_value;
        if (scanf("%d", &input_value) != 1) {
            break; // Stop reading if non-integer is entered
        }

        numbers[count] = input_value;
        count++;
    }

    // If no elements were entered
    if (count == 0) {
        printf("\nNo elements were entered.\n");
        return 0;
    }

    // Reverse the array containing the entered elements
    reverse_array(numbers, count);

    printf("\nArray after reversal:\n");
    for (int i = 0; i < count; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    return 0;
}
