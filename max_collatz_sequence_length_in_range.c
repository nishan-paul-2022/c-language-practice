/*
 * Purpose: Find the maximum Collatz sequence length for numbers in a given range
 * Topic: Collatz Conjecture, Recursive Functions, Range Processing
 */

#include <stdio.h>

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

int read_range(int *start_range, int *end_range) {
    if (scanf("%d - %d", start_range, end_range) != 2) {
        fprintf(stderr, "Invalid input format. Please enter range as 'start - end'.\n");
        return -1;
    }
    return 0;
}

int find_max_collatz_length(int start_range, int end_range) {
    int current_number;
    int sequence_length;
    int max_sequence_length = 0;

    for (current_number = start_range; current_number <= end_range; current_number++) {
        sequence_length = 1;
        calculate_collatz_length(current_number, &sequence_length);
        
        if (sequence_length > max_sequence_length) {
            max_sequence_length = sequence_length;
        }
    }
    
    return max_sequence_length;
}

int main(void) {
    int start_range, end_range;
    int max_sequence_length;

    if (read_range(&start_range, &end_range) == -1) {
        return 0;
    }

    max_sequence_length = find_max_collatz_length(start_range, end_range);
    printf("%d\n", max_sequence_length);

    return 0;
}
