/*
 * Purpose: Reads integers into an array until a non-integer input is entered,
 *          then reverses the array and prints its elements.
 * Topic: Arrays, Input Termination, Reversal Algorithm, Loops, Input/Output
 */

#include <stdio.h>

#define MAX_ARRAY_SIZE 100 // Define a maximum size for the array

// Function to reverse an array in-place
void reverse_array(int arr[], int size) {
    int temp;
    int start_index = 0;
    int end_index = size - 1;

    // Swap elements from the beginning and end, moving towards the center
    while (start_index < end_index) {
        temp = arr[start_index];
        arr[start_index] = arr[end_index];
        arr[end_index] = temp;

        // Move indices towards the center
        start_index++;
        end_index--;
    }
}

int main() {
    int numbers[MAX_ARRAY_SIZE];
    int count = 0; // To keep track of the number of elements entered
    int input_value;

    printf("Enter integers. Enter any non-integer to stop:\n");

    // Read integers until a non-integer is entered or max size is reached
    while (count < MAX_ARRAY_SIZE) {
        printf("Enter element %d: ", count + 1);
        if (scanf("%d", &input_value) != 1) {
            break; // Stop reading if non-integer is entered
        }

        numbers[count] = input_value;
        count++;
    }

    // If no elements were entered
    if (count == 0) {
        printf("\nNo elements entered.\n");
        return 0;
    }

    // Reverse the array containing the entered elements
    reverse_array(numbers, count);

    printf("\nArray after reversal:\n");
    for (int k = 0; k < count; k++) {
        printf("%d ", numbers[k]);
    }
    printf("\n");

    return 0;
}
