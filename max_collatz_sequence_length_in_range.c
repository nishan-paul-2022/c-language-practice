/*
 * Purpose: Finds the maximum Collatz sequence length for numbers in a given range.
 * Topic: Collatz Conjecture, Recursive Functions, Range Processing
 */

#include <stdio.h>

// Calculate Collatz sequence length recursively
void calculate_collatz_length(int current_num, int *steps) {
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

// Read range input from user
int read_range(int *start_range, int *end_range) {
    printf("Enter range (format: start - end): ");
    if (scanf("%d - %d", start_range, end_range) != 2) {
        fprintf(stderr, "Invalid input format. Please enter range as 'start - end'.\n");
        return -1;
    }
    
    if (*start_range > *end_range) {
        fprintf(stderr, "Invalid range. Start must be less than or equal to end.\n");
        return -1;
    }
    
    return 0;
}

// Find maximum Collatz sequence length in range
int find_max_collatz_length(int start_range, int end_range) {
    int max_sequence_length = 0;

    printf("Processing range %d to %d...\n", start_range, end_range);
        
    for (int current_number = start_range; current_number <= end_range; current_number++) {
        int sequence_length = 1;
        calculate_collatz_length(current_number, &sequence_length);
        
        if (sequence_length > max_sequence_length) {
            max_sequence_length = sequence_length;
        }
    }
    
    return max_sequence_length;
}

int main(void) {
    printf("Collatz Sequence Maximum Length Finder\n");
    printf("======================================\n");

    int start_range, end_range;
    if (read_range(&start_range, &end_range) == -1) {
        return 0;
    }

    int max_sequence_length = find_max_collatz_length(start_range, end_range);
    printf("Maximum Collatz sequence length in range [%d, %d]: %d\n", start_range, end_range, max_sequence_length);

    return 0;
}
