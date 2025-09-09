/*
 * Purpose: Demonstrates how a function can modify array elements passed to it.
 * Topic: Arrays, Functions, Pass-by-Reference (for arrays), Pointers
 */

#include <stdio.h>
#include <stdlib.h>

// Modifies the first element of an integer array to 100
int modify_first_element(int data_array[], int array_size) {
    // Check if the array is valid and has at least one element
    if (data_array == NULL || array_size <= 0) {
        fprintf(stderr, "Error: Invalid array or size passed to modify_first_element.\n");
        return -1; // Error value
    }

    // Set first element to 100
    data_array[0] = 100;

    // Return the new value of first element
    return data_array[0];
}

int main() {
    int data_array[3] = {1, 2, 3};
    int function_return_value;

    printf("Initial value of data_array[0]: %d\n", data_array[0]);

    // Modify first element to 100
    function_return_value = modify_first_element(data_array, 3);

    if (function_return_value == -1) {
        fprintf(stderr, "Function call failed.\n");
        return 0;
    }

    printf("Value of data_array[0] after function call: %d\n", data_array[0]);
    printf("Value returned by modify_first_element(): %d\n", function_return_value);

    return 0;
}