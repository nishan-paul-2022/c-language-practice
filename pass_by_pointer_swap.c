// Purpose: Demonstrates swapping two integer values using pass-by-pointer.
// Topic: Pointers, Function Parameters, Swapping Variables
#include <stdio.h>
#include <stdlib.h> // For EXIT_SUCCESS, EXIT_FAILURE

// Function to swap two integer values using pointers
void swap(int *ptr1, int *ptr2) {
    int temp; // Temporary variable to hold one of the values during swap

    // Check if the pointers are valid (not NULL) to prevent dereferencing NULL pointers
    if (ptr1 == NULL || ptr2 == NULL) {
        fprintf(stderr, "Error: Invalid pointers passed to swap function.\n");
        return; // Exit the function if pointers are invalid
    }

    // Perform the swap using a temporary variable
    temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

int main() {
    int num1, num2;

    printf("Enter two integers separated by a space (e.g., '10 20'):\n");

    // Read two integers from standard input
    // scanf returns the number of successfully matched and assigned input items.
    // We expect 2 items (num1 and num2) to be successfully read.
    if (scanf("%d %d", &num1, &num2) == 2) {
        printf("Before swap: num1 = %d, num2 = %d\n", num1, num2);

        // Call the swap function, passing the addresses of num1 and num2
        swap(&num1, &num2);

        // Print the values after swapping
        printf("After swap:  num1 = %d, num2 = %d\n", num1, num2);

        return 0; // Indicate success
    } else {
        // Handle cases where the input format is incorrect or EOF is reached prematurely
        fprintf(stderr, "Error: Invalid input. Please enter two integers separated by a space.\n");
        // Clear the input buffer in case of partial reads or invalid characters
        while (getchar() != '\n');
        return EXIT_FAILURE; // Indicate failure
    }
}
