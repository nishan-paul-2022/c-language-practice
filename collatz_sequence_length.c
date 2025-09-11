/*
 * Purpose: Calculates and prints the length of Collatz sequences for numbers in a given range.
 * Topic: Recursion, Loops, Input Parsing, Collatz Conjecture
 */

#include <stdio.h>

// Recursively calculates Collatz sequence length for a number
// Collatz rule: if even, divide by 2; if odd, multiply by 3 and add 1
// Steps count is tracked via pointer parameter
void calculate_collatz_length(int current_num, int *steps) {
    // Continue recursion until reaching 1 (base case implicitly handled by condition)
    if (current_num != 1) {
        // Apply Collatz transformation based on parity
        if (current_num % 2 != 0) { // Odd number
            current_num = 3 * current_num + 1;
        } else { // Even number
            current_num = current_num / 2;
        }
        // Increment step count
        (*steps)++;
        // Recursive call with transformed number
        calculate_collatz_length(current_num, steps);
    }
}

int main(void) {
    int start_range, end_range; // Range boundaries
    int current_number;         // Current number being processed
    int sequence_length;      // Length of Collatz sequence

    // Parse range input in format "start - end"
    if (scanf("%d - %d", &start_range, &end_range) != 2) {
        fprintf(stderr, "Invalid input format. Please enter range as 'start - end'.\n");
        return 0;
    }

    // Process each number in range
    for (current_number = start_range; current_number <= end_range; current_number++) {
        // Initialize step count to 1 (includes starting number)
        sequence_length = 1;
        
        // Calculate Collatz sequence length
        calculate_collatz_length(current_number, &sequence_length);
        
        // Print sequence length
        printf("%d ", sequence_length);
    }
    
    // New line for clean output formatting
    printf("\n");

    return 0;
}
