/*
 * Purpose: Prints a diamond pattern using numbers.
 * Topic: Nested Loops, Diamond Patterns, Number Sequences
 */

#include <stdio.h>
#include <stdlib.h>

int read_diamond_size(void) {
    int size;
    printf("Enter the size of the diamond (number of rows in the upper half): ");
    if (scanf("%d", &size) != 1 || size <= 0) {
        fprintf(stderr, "Error: Invalid input for size. Please enter a positive integer.\n");
        return 0;
    }
    return size;
}

void print_upper_half(int size) {
    int current_number = 1;
    int row, col;
    
    for (row = 1; row <= size; row++) {
        for (col = 1; col <= size - row; col++) {
            printf(" ");
        }
        for (col = 1; col <= row; col++) {
            printf(" %d", current_number);
            current_number++;
        }
        printf("\n");
    }
}

void print_lower_half(int size) {
    int current_number = size - 1;
    int row, col;
    
    for (row = size - 1; row >= 1; row--) {
        for (col = 1; col <= size - row; col++) {
            printf(" ");
        }
        for (col = 1; col <= row; col++) {
            printf(" %d", current_number);
            current_number--;
        }
        printf("\n");
    }
}

int main(void) {
    int size = read_diamond_size();
    
    if (size == 0) {
        return 0;
    }

    print_upper_half(size);
    print_lower_half(size);

    return 0;
}
