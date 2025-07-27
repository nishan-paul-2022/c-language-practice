/*
 * Purpose: Reads 'n' integers into an array and finds the maximum element among them.
 *          It uses a sorting-like approach (similar to bubble sort's pass for finding max).
 * Topic: Arrays, Loops, Conditional Statements, Finding Maximum
 */

#include <stdio.h> // Required for printf and scanf
#include <stdlib.h> // Required for malloc and free (for dynamic array if VLA is not desired)

int main() {
    int num_elements; // Number of elements in the array
    int i, j;         // Loop counters
    int temp_val;     // Temporary variable for swapping

    // Prompt user for the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &num_elements);

    // Check for valid number of elements
    if (num_elements <= 0) {
        printf("Number of elements must be positive.\n");
        return 1; // Indicate an error
    }

    // Declare a Variable Length Array (VLA) - C99 feature
    // For strict C89/C90, dynamic memory allocation with malloc would be used.
    int arr[num_elements];

    // Read elements into the array
    printf("Enter %d integer elements:\n", num_elements);
    for (i = 0; i < num_elements; i++) {
        scanf("%d", &arr[i]);
    }

    // Find the maximum element by effectively performing one pass of bubble sort
    // The largest element will "bubble" to the last position (arr[num_elements - 1])
    for (i = 0; i < num_elements - 1; i++) { // Outer loop for passes
        for (j = i + 1; j < num_elements; j++) { // Inner loop for comparisons
            if (arr[i] > arr[j]) {
                // Swap elements if they are in the wrong order
                temp_val = arr[i];
                arr[i] = arr[j];
                arr[j] = temp_val;
            }
        }
    }

    // After the loops, arr[num_elements - 1] will contain the maximum element
    printf("The maximum element in the array is: %d\n", arr[num_elements - 1]);

    return 0; // Indicate successful execution
}
