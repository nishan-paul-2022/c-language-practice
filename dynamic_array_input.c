/*
* Purpose: Reads a dynamic array of integers from user input and prints its elements.
 * Topic: Arrays, Input/Output, Dynamic Sizing (via user input)
 */

#include <stdio.h>

// Function to read an array of integers from user input
// Takes a pointer to the array and its size as arguments
void read_integer_array(int arr[], int size) {
    int i;
    printf("Enter %d integers (separated by spaces or newlines):\n", size);
    for (i = 0; i < size; i++) {
        // Read each integer. The %*c consumes any trailing whitespace (like newline)
        // after reading the integer, which helps with subsequent inputs
        if (scanf("%d%*c", &arr[i]) != 1) {
            printf("Invalid input at element %d. Please enter integers only.\n", i);
            // In a real-world scenario, you might want more robust error handling here
            // For this example, we'll proceed, but the array might be partially filled
            // To be safer, we could exit or re-prompt
            return; // Exit the function on invalid input
        }
    }
}

int main() {
    int n; // Variable to store the size of the array
    int i;

    // Prompt the user to enter the number of elements for the array
    printf("Enter the number of elements for the array: ");

    // Read the size of the array from the user
    if (scanf("%d", &n) != 1) {
        printf("Invalid input for array size. Please enter an integer.\n");
        return 0;
    }

    // Declare an array of size 'n'. This is a Variable Length Array (VLA)
    // supported in C99 and later standards
    int arr[n];

    // Call the function to read the array elements
    read_integer_array(arr, n);

    // Print the elements of the array
    printf("The elements of the array are: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n"); // Print a newline at the end

    return 0;
}
