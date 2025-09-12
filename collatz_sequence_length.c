/*
 * Purpose: Calculates and prints the length of Collatz sequences for numbers in a given range.
 * Topic: Recursion, Loops, Input Parsing, Collatz Conjecture
 */

#include <stdio.h>

// Recursively calculates Collatz sequence length, tracking steps via a pointer.
void calculate_collatz_length(int current_num, int *steps) {
    // Continue recursion until reaching 1 (base case implicitly handled by condition)
    if (current_num != 1) {
        if (current_num % 2) {
            current_num = 3 * current_num + 1;
        } else {
            current_num = current_num / 2;
        }
        (*steps)++;  
        calculate_collatz_length(current_num, steps);
    }
}

int main(void) {
    int start_range, end_range;
    printf("Enter the range (e.g., 1 - 10): ");
    if (scanf("%d - %d", &start_range, &end_range) != 2) {
        fprintf(stderr, "Invalid input format. Please enter range as 'start - end'.\n");
        return 0;
    }

    // Process each number in range
    for (int current_number = start_range; current_number <= end_range; current_number++) {
        // Initialize step count to 1 (includes starting number)
        int sequence_length = 1;
        calculate_collatz_length(current_number, &sequence_length);
        printf("%d ", sequence_length);
    }
    
    printf("\n");

    return 0;
}
