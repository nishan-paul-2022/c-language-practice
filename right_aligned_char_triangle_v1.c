/*
 * Purpose: Prints a right-aligned triangle pattern using characters with leading spaces.
 * Topic: Nested Loops, Character Manipulation, Spacing
 */

#include <stdio.h>

// Get number of rows
int get_num_rows() {
    int num_rows;
    printf("Enter the number of rows: ");
    if (scanf("%d", &num_rows) != 1 || num_rows <= 0) {
        fprintf(stderr, "Invalid input for number of rows. Please enter a positive integer.\n");
        return -1;
    }
    return num_rows;
}

// Get starting character
char get_start_char() {
    char start_char;
    printf("Enter the starting character: ");
    while (getchar() != '\n');
    if (scanf("%c", &start_char) != 1) {
        fprintf(stderr, "Invalid input for starting character.\n");
        return '\0';
    }
    return start_char;
}

// Print right-aligned character triangle
void print_triangle(int num_rows, char start_char) {
    int space_count_decrement = 1;

    for (int row = 1; row <= num_rows; row++) {
        for (int space_col = 1; space_col <= num_rows - space_count_decrement; space_col++) {
            printf(" ");
        }

        char current_char = start_char;
        for (int col = 1; col <= row; col++) {
            printf("%c", current_char);
            current_char++;
        }

        printf("\n");
        space_count_decrement++;
    }
}

int main(void) {
    int num_rows = get_num_rows();
    if (num_rows == -1) {
        return 0;
    }

    char start_char = get_start_char();
    if (start_char == '\0') {
        return 0;
    }

    print_triangle(num_rows, start_char);
    
    return 0;
}
