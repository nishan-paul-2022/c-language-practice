/*
 * Purpose: Generates a specific number sequence based on input ranges.
 * Topic: Algorithmic Number Transformation
 */

#include <stdio.h>

int read_integer_input(void) {
    int n;
    printf("Enter an integer (or a non-integer to exit): ");
    if (scanf("%d", &n) != 1) {
        printf("Invalid input. Exiting program.\n");
        return -1;
    }
    return n;
}

int process_range_1_to_9(int n) {
    return n;
}

int process_range_10_to_18(int n) {
    return (n - 9) * 11;
}

int process_range_19_to_108(int n) {
    int block_index = (n - 19) / 10;
    int block_start = 19 + block_index * 10;
    int offset_in_block = n - block_start;
    return (block_index + 1) * 101 + offset_in_block * 10;
}

int process_range_109_to_198(int n) {
    int block_index = (n - 109) / 10;
    int block_start = 109 + block_index * 10;
    int offset_in_block = n - block_start;
    return (block_index + 1) * 1001 + offset_in_block * 110;
}

int process_number_sequence(int n) {
    int output;
    
    if (n <= 0) {
        printf("Input must be a positive integer.\n");
        return -1;
    } else if (n <= 9) {
        output = process_range_1_to_9(n);
        printf("Output for %d: %d\n", n, output);
    } else if (n <= 18) {
        output = process_range_10_to_18(n);
        printf("Output for %d: %d\n", n, output);
    } else if (n <= 108) {
        output = process_range_19_to_108(n);
        printf("Output for %d: %d\n", n, output);
    } else if (n <= 198) {
        output = process_range_109_to_198(n);
        printf("Output for %d: %d\n", n, output);
    } else {
        printf("Input %d is outside the defined processing ranges (1-198).\n", n);
        return -1;
    }
    
    return 0;
}

int main(void) {
    int n = read_integer_input();
    
    if (n == -1) {
        return 0;
    }
    
    process_number_sequence(n);

    return 0;
}
