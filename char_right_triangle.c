/*
 * Purpose: Demonstrates printing a right-aligned character triangle pattern with input validation.
 * Topic: Pattern Printing and Character Manipulation
 */

#include <stdio.h>

void consume_newline() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int get_number_of_rows() {
    int num_rows;

    printf("Enter the number of rows for the character triangle: ");
    
    if (scanf("%d", &num_rows) == -1) {
        fprintf(stderr, "Invalid input. Please enter an integer for the number of rows.\n");
        consume_newline();
        return -1;
    }
    
    consume_newline();
    return num_rows;
}

int validate_rows(int num_rows) {
    if (num_rows <= 0) {
        fprintf(stderr, "Number of rows must be positive.\n");
        return -1;
    }

    return 0;
}

void print_triangle_row(int row_index) {
    printf("\t\t\t");
    
    char current_char = 'A';
    for (int col_index = 1; col_index <= row_index; col_index++) {
        printf(" %c ", current_char);
        current_char++;
    }
    
    printf("\n");
}

void print_triangle_pattern(int num_rows) {
    for (int row_index = 1; row_index <= num_rows; row_index++) {
        print_triangle_row(row_index);
    }
}

int main(void) {
    int num_rows = get_number_of_rows();
    if (num_rows == -1) {
        return 0;
    }
    
    int validation_result = validate_rows(num_rows);
    if (validation_result == -1) {
        return 0;
    }

    print_triangle_pattern(num_rows);
    
    return 0;
}
