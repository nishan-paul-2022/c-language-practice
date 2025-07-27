// Purpose: Demonstrates returning a pointer to the larger of two integer values.
// Topic: Pointers, Functions, Return Values, Comparison

#include <stdio.h>
#include <stdlib.h> // For exit()

// Function to find the pointer to the larger of two integer values.
// Takes two integer pointers as input.
// Returns a pointer to the integer with the larger value.
// If values are equal, it returns the pointer to the first argument.
int* find_larger_pointer(int *ptr_val1, int *ptr_val2) {
    // Check for NULL pointers to ensure safety
    if (ptr_val1 == NULL || ptr_val2 == NULL) {
        fprintf(stderr, "Error: NULL pointer passed to find_larger_pointer.\n");
        return NULL; // Return NULL to indicate an error
    }

    // Compare the values pointed to by the pointers
    if (*ptr_val1 >= *ptr_val2) { // If value1 is greater than or equal to value2
        return ptr_val1; // Return pointer to value1
    } else { // If value2 is greater than value1
        return ptr_val2; // Return pointer to value2
    }
}

int main() {
    int value1 = 10;
    int value2 = 20;
    int *larger_value_ptr = NULL; // Pointer to store the result

    // Print initial values
    printf("Initial value1: %d\n", value1);
    printf("Initial value2: %d\n", value2);

    // Call the function to get the pointer to the larger value
    larger_value_ptr = find_larger_pointer(&value1, &value2);

    // Check if the function returned a valid pointer
    if (larger_value_ptr != NULL) {
        // Print the value pointed to by the returned pointer
        printf("The larger value is: %d\n", *larger_value_ptr);
    } else {
        printf("Could not determine the larger value due to an error.\n");
    }

    return 0; // Indicate successful execution
}
