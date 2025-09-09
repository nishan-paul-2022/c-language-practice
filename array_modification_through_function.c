/*
 * Purpose: Demonstrates how a function can modify array elements passed to it.
 * Topic: Arrays, Functions, Pass-by-Reference (for arrays), Pointers
 */

#include <stdio.h>
#include <stdlib.h> // For exit()

// Function to modify the first element of an integer array.
// It takes an integer array and its size as input.
// It modifies the first element to a specific value and returns that value.
// Note: Arrays are passed by reference in C, so modifications inside the function
// affect the original array passed from the caller.
int modify_first_element(int data_array[], int array_size) {
    // Check if the array is valid and has at least one element
    if (data_array == NULL || array_size <= 0) {
        fprintf(stderr, "Error: Invalid array or size passed to modify_first_element.\n");
        return -1; // Indicate an error, or a specific error value
    }

    // Modify the first element of the array
    data_array[0] = 100;

    // Return the modified value (optional, as the array is modified directly)
    return data_array[0];
}

int main() {
    int data_array[3] = {1, 2, 3}; // Initialize an array
    int function_return_value;

    // Print the initial value of the first element
    printf("Initial value of data_array[0]: %d\n", data_array[0]);

    // Call the function to modify the array.
    // The function will change data_array[0] to 100.
    function_return_value = modify_first_element(data_array, 3);

    // Check if the function call resulted in an error
    if (function_return_value == -1) {
        fprintf(stderr, "Function call failed.\n");
        return 1; // Indicate an error
    }

    // Print the value of the first element after the function call.
    // It should now be 100 because the array was modified in place.
    printf("Value of data_array[0] after function call: %d\n", data_array[0]);

    // Optionally, print the value returned by the function
    printf("Value returned by modify_first_element(): %d\n", function_return_value);

    return 0; // Indicate successful execution
}
