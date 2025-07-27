// Purpose: Reads integers into an array until a sentinel value (1) is entered,
//          then reverses the array and prints its elements.
// Topic: Arrays, Sentinel Value, Reversal Algorithm, Loops, Input/Output

#include <stdio.h>

#define MAX_ARRAY_SIZE 100 // Define a maximum size for the array

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
    int numbers[MAX_ARRAY_SIZE];
    int count = 0; // To keep track of the number of elements entered
    int input_value;

    printf("Enter integers. Enter '1' to stop:\n");

    // Read integers until the sentinel value (1) is entered or max size is reached
    while (count < MAX_ARRAY_SIZE) {
        printf("Enter element %d: ", count + 1);
        if (scanf("%d", &input_value) != 1) {
            printf("\nError: Invalid input. Please enter an integer.\n");
            return 1; // Indicate an error
        }

        // Check for the sentinel value
        if (input_value == 1) {
            break; // Stop reading if sentinel is entered
        }

        numbers[count] = input_value; // Store the valid input
        count++;                      // Increment the count of elements
    }

    // If no elements were entered (only sentinel was entered or max size reached without sentinel)
    if (count == 0) {
        printf("\nNo elements entered (other than the sentinel).\n");
        return 0;
    }

    // Reverse the array containing the entered elements
    reverse_array(numbers, count);

    printf("\nArray after reversal:\n");
    // Print the reversed array elements
    for (int k = 0; k < count; k++) {
        printf("%d ", numbers[k]);
    }
    printf("\n"); // Print a newline at the end

    return 0; // Indicate successful execution
}
