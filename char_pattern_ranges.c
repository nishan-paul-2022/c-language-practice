/*
 * Purpose: Reads three characters to define a pattern.
 *          Prints characters from start to row-end for each row, with columns from start to column-end character.
 * Topic: Character Input, Nested Loops, Character Arithmetic, Pattern Printing
 */

#include <stdio.h>
#include <ctype.h>

void consume_newline(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        
    }
}

void display_instructions(void) {
    printf("Enter pattern parameters in the format: start_char_for_rows, end_char_for_rows, end_char_for_cols\n");
    printf("Example: A, E, G\n");
}

int get_start_char(void) {
    char start_char_for_rows;
    if (scanf(" %c", &start_char_for_rows) != 1) {
        fprintf(stderr, "Invalid input for start_char_for_rows.\n");
        consume_newline();
        return -1;
    }
    return start_char_for_rows;
}

int get_end_char_rows(void) {
    char end_char_for_rows;
    if (scanf(" , %c", &end_char_for_rows) != 1) {
        fprintf(stderr, "Invalid input for end_char_for_rows.\n");
        consume_newline();
        return -1;
    }
    return end_char_for_rows;
}

int get_end_char_cols(void) {
    char end_char_for_cols;
    if (scanf(" , %c", &end_char_for_cols) != 1) {
        fprintf(stderr, "Invalid input for end_char_for_cols.\n");
        consume_newline();
        return -1;
    }
    return end_char_for_cols;
}

int validate_characters(char start_char_for_rows, char end_char_for_rows, char end_char_for_cols) {
    if (start_char_for_rows > end_char_for_rows) {
        fprintf(stderr, "start_char_for_rows must be <= end_char_for_rows.\n");
        return -1;
    }
    if (start_char_for_rows > end_char_for_cols) {
        fprintf(stderr, "start_char_for_rows must be <= end_char_for_cols.\n");
        return -1;
    }
    return 0;
}

void print_pattern_row(char current_row_char, char start_char_for_rows, char end_char_for_cols) {
    printf("\t\t\t");
    
    for (char current_col_char = current_row_char; current_col_char <= end_char_for_cols; current_col_char++) {
        printf(" %c ", current_col_char);
    }
    
    for (char fill_char = 0; fill_char < (current_row_char - start_char_for_rows); fill_char++) {
        printf(" %c ", end_char_for_cols);
    }
    
    printf("\n");
}

void generate_pattern(char start_char_for_rows, char end_char_for_rows, char end_char_for_cols) {
    for (char current_row_char = start_char_for_rows; current_row_char <= end_char_for_rows; current_row_char++) {
        print_pattern_row(current_row_char, start_char_for_rows, end_char_for_cols);
    }
}

int main(void) {
    display_instructions();
    
    printf("Enter start_char_for_rows, end_char_for_rows, end_char_for_cols: ");
    
    int start_char_for_rows = get_start_char();
    if (start_char_for_rows == -1) {
        return 0;
    }
    
    int end_char_for_rows = get_end_char_rows();
    if (end_char_for_rows == -1) {
        return 0;
    }
    
    int end_char_for_cols = get_end_char_cols();
    if (end_char_for_cols == -1) {
        return 0;
    }
    
    consume_newline();

    if (validate_characters(start_char_for_rows, end_char_for_rows, end_char_for_cols) != 0) {
        return 0;
    }

    generate_pattern(start_char_for_rows, end_char_for_rows, end_char_for_cols);

    return 0;
}
