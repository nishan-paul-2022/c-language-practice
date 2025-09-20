/*
 * Purpose: Prints a specific pattern of asterisks to the console using functions.
 * Topic: Nested Loops, Character Output, Pattern Printing, Function Decomposition
 */

#include <stdio.h>

void print_horizontal_line(int rows, int columns) {
    for (int row_count = 0; row_count < rows; row_count++) {
        for (int col_count = 0; col_count < columns; col_count++) {
            printf(" *");
        }
        printf("\n");
    }
}

void print_indented_line(int rows, int columns, int indent_spaces) {
    for (int row_count = 0; row_count < rows; row_count++) {
        for (int indent_count = 0; indent_count < indent_spaces; indent_count++) {
            printf("  ");
        }
        
        for (int col_count = 0; col_count < columns; col_count++) {
            printf(" *");
        }
        printf("\n");
    }
}

int main(void) {
    print_horizontal_line(3, 18);
    print_horizontal_line(3, 4);
    print_horizontal_line(3, 18);
    print_indented_line(3, 4, 14);
    print_horizontal_line(3, 18);

    return 0;
}
