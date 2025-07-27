// Purpose: Generates a specific number sequence based on input ranges.
// Topic: Algorithmic Number Transformation

#include <stdio.h>

int main() {
    int n;

    // Prompt the user for input and validate it.
    printf("Enter an integer (or a non-integer to exit): ");
    if (scanf("%d", &n) != 1) {
        printf("Invalid input. Exiting program.\n");
        return 1; // Indicate an error
    }

    int output;

    // Process input based on defined ranges and patterns.
    if (n <= 0) {
        // Handle non-positive input, though original code didn't specify.
        // Assuming positive integers are expected based on ranges.
        printf("Input must be a positive integer.\n");
        return 1;
    } else if (n <= 9) {
        // Range 1: 1 to 9
        // Output is the number itself.
        output = n;
        printf("Output for %d: %d\n", n, output);
    } else if (n <= 18) {
        // Range 2: 10 to 18
        // Output is (n - 9) * 11.
        output = (n - 9) * 11;
        printf("Output for %d: %d\n", n, output);
    } else if (n <= 108) {
        // Range 3: 19 to 108
        // This range involves blocks of 10 numbers.
        // Calculate the block index (0 for 19-28, 1 for 29-38, etc.)
        int block_index = (n - 19) / 10;
        // Determine the starting number of the block.
        int block_start = 19 + block_index * 10;
        // Calculate the offset within the current block.
        int offset_in_block = n - block_start;
        // Calculate the output based on the pattern: (block_index + 1) * 101 + offset_in_block * 10
        output = (block_index + 1) * 101 + offset_in_block * 10;
        printf("Output for %d: %d\n", n, output);
    } else if (n <= 198) {
        // Range 4: 109 to 198
        // This range also involves blocks, with a different pattern.
        // Calculate the block index (0 for 109-118, 1 for 119-128, etc.)
        int block_index = (n - 109) / 10;
        // Determine the starting number of the block.
        int block_start = 109 + block_index * 10;
        // Calculate the offset within the current block.
        int offset_in_block = n - block_start;
        // Calculate the output based on the pattern: (block_index + 1) * 1001 + offset_in_block * 110
        output = (block_index + 1) * 1001 + offset_in_block * 110;
        printf("Output for %d: %d\n", n, output);
    } else {
        // Handle inputs greater than 198, as the original code implicitly handled them
        // by continuing the loop. For a single-input program, we can indicate this.
        printf("Input %d is outside the defined processing ranges (1-198).\n", n);
        // If we wanted to extend the pattern, we would add more else if blocks here.
        // For now, we'll just inform the user.
        return 1; // Indicate that the input was out of range for defined processing.
    }

    return 0; // Indicate successful execution
}
