/*
 * Purpose: Prints a hollow diamond pattern using numbers.
 * Topic: Nested Loops, Diamond Patterns, Number Sequences, Hollow Patterns
 */

#include <stdio.h>
#include <stdlib.h>

int get_size() {
    int size;
    printf("Enter the size of the diamond (number of rows in the upper half): ");
    if (scanf("%d", &size) != 1 || size <= 0) {
        fprintf(stderr, "Invalid input for size. Please enter a positive integer.\n");
        return -1;
    }
    return size;
}

void print_leading_spaces(int count) {
    for (int col = 1; col < count; col++) {
        printf(" ");
    }
}

void print_diamond_row(int row_width, int current_number) {
    for (int col = 1; col <= row_width; col++) {
        if (col == 1 || col == row_width) {
            printf("%d", current_number);
        } else {
            printf(" ");
        }
    }
}

void print_upper_half(int effective_size) {
    int space_offset = 1;
    int current_number = 1;
    
    for (int row = 1; row <= effective_size; row += 2) {
        print_leading_spaces(space_offset);
        print_diamond_row(row, current_number);
        space_offset++;
        current_number++;
        printf("\n");
    }
}

void print_lower_half(int effective_size) {
    int space_offset = (effective_size + 1) / 2;
    int current_number = (effective_size + 1) / 2 - 1;
    
    for (int row = effective_size - 2; row >= 1; row -= 2) {
        print_leading_spaces(space_offset + 1);
        print_diamond_row(row, current_number);
        space_offset++;
        current_number--;
        printf("\n");
    }
}

int main(void) {
    int size = get_size();
    if (size == -1) {
        return 0;
    }

    int effective_size = (size % 2 == 0) ? size - 1 : size;
    if (effective_size <= 0) {
        effective_size = 1;
    }

    print_upper_half(effective_size);
    print_lower_half(effective_size);

    return 0;
}
