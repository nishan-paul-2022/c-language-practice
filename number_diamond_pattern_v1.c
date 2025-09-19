/*
 * Purpose: Prints a diamond-like number pattern with leading spaces.
 * Topic: Nested Loops, Number Patterns, Spacing
 */

#include <stdio.h>
#include <stdlib.h>

int read_num_rows() {
    int num_rows;
    printf("Enter the number of rows: ");
    if (scanf("%d", &num_rows) != 1 || num_rows <= 0) {
        fprintf(stderr, "Invalid input for number of rows. Please enter a positive integer.\n");
        return 0;
    }
    return num_rows;
}

void print_leading_spaces(int space_count) {
    int space_col;
    for (space_col = 1; space_col < space_count; space_col++) {
        printf(" ");
    }
}

void print_descending_numbers(int desc_start_num, int row) {
    int current_desc_num = desc_start_num;
    int desc_col;
    for (desc_col = 1; desc_col <= row; desc_col++) {
        printf("%d", current_desc_num);
        current_desc_num--;
    }
}

void print_ascending_numbers(int space_count_decrement) {
    int asc_start_num = 1;
    int asc_col;
    for (asc_col = 1; asc_col < space_count_decrement - 1; asc_col++) {
        printf("%d", asc_start_num);
        asc_start_num++;
    }
}

void generate_pattern(int num_rows) {
    int space_count_decrement = num_rows;
    int desc_start_num = 0;
    int row;

    for (row = 1; row <= num_rows; row++) {
        print_leading_spaces(space_count_decrement);
        print_descending_numbers(desc_start_num, row);
        print_ascending_numbers(space_count_decrement);
        
        space_count_decrement--;
        desc_start_num++;
        printf("\n");
    }
}

int main(void) {
    int num_rows = read_num_rows();
    
    if (num_rows == 0) {
        return 0;
    }

    generate_pattern(num_rows);

    return 0;
}
