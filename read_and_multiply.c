// Purpose: Reads two integers from input in a specific format ("input X*Y") and prints their product.
// Topic: Formatted Input, Arithmetic Operations
#include <stdio.h>
#include <stdlib.h> // For EXIT_SUCCESS, EXIT_FAILURE

int main() {
    int num1, num2;
    long long product; // Use long long for product to avoid potential overflow

    printf("Enter input in the format 'input X*Y' (e.g., 'input 10*20'):\n");

    // Read the input, expecting the format "input X*Y"
    // scanf returns the number of successfully matched and assigned input items.
    // We expect 2 items (num1 and num2) to be successfully read.
    if (scanf("input %d*%d", &num1, &num2) == 2) {
        // Calculate the product
        product = (long long)num1 * num2; // Cast to long long before multiplication

        // Print the product
        printf("The product of %d and %d is: %lld\n", num1, num2, product);
        return 0; // Indicate success
    } else {
        // Handle cases where the input format is incorrect or EOF is reached prematurely
        fprintf(stderr, "Error: Invalid input format. Please use 'input X*Y'.\n");
        // Clear the input buffer in case of partial reads or invalid characters
        while (getchar() != '\n');
        return EXIT_FAILURE; // Indicate failure
    }
}
