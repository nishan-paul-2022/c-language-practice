/*
 * Purpose: Demonstrates passing pointers to a function to allow the function to modify the original variables.
 * Topic: Pointers, Functions, Pass-by-Reference (for arrays), Variable Modification
 */

#include <stdio.h>
#include <stdlib.h>

// Function to potentially modify the values pointed to by ptr_val1 and ptr_val2.
// If the value pointed to by ptr_val1 is less than 40, it increments it by 5.
// Otherwise, if the value pointed to by ptr_val2 is less than 40, it increments it by 5.
// This function modifies the original variables passed by address.
void modify_values_if_less_than_40(int *ptr_val1, int *ptr_val2) {
    // Check for NULL pointers to ensure safety
    if (ptr_val1 == NULL || ptr_val2 == NULL) {
        fprintf(stderr, "Error: NULL pointer passed to modify_values_if_less_than_40.\n");
        return; // Exit the function if pointers are invalid
    }

    // Check the value pointed to by ptr_val1
    if (*ptr_val1 < 40) {
        *ptr_val1 += 5; // Increment the value pointed to by ptr_val1
    }
    // Check the value pointed to by ptr_val2 only if the first condition was false
    else if (*ptr_val2 < 40) {
        *ptr_val2 += 5; // Increment the value pointed to by ptr_val2
    }
}

int main(void) {
    int value1, value2;
    int original_value1, original_value2; // To store original values for comparison

    // Get two integer values from the user
    printf("Enter two integers separated by a comma (e.g., 30, 50): ");
    if (scanf("%d, %d", &value1, &value2) != 2) {
        fprintf(stderr, "Error: Invalid input format. Please enter two integers separated by a comma.\n");
        return 0;
    }
    // Consume any remaining characters on the line after the second integer, including the newline
    while (getchar() != '\n');

    // Store original values for comparison in output
    original_value1 = value1;
    original_value2 = value2;

    // Call the function, passing the addresses of value1 and value2.
    // This allows the function to modify the original variables.
    modify_values_if_less_than_40(&value1, &value2);

    // Print the original and potentially modified values
    printf("Original values: %d, %d\n", original_value1, original_value2);
    printf("Modified values: %d, %d\n", value1, value2);

    return 0;
}
