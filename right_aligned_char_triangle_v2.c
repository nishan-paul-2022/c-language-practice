/*
 * Purpose: Prints a right-aligned triangle pattern using characters with leading spaces.
 * Topic: Nested Loops, Character Manipulation, Spacing, Functions
 */

#include <stdio.h>

// Function to get the number of rows with validation
int get_num_rows(void) {
    int num_rows;
    printf("Enter the number of rows: ");
    if (scanf("%d", &num_rows) != 1 || num_rows <= 0) {
        fprintf(stderr, "Error: Invalid input for number of rows. Please enter a positive integer.\n");
        return -1;
    }
    return num_rows;
}

// Function to get the starting character with validation
char get_start_char(void) {
    char start_char;
    printf("Enter the starting character: ");
    while (getchar() != '\n'); // clear input buffer
    if (scanf("%c", &start_char) != 1) {
        fprintf(stderr, "Error: Invalid input for starting character.\n");
        return '\0';
    }
    return start_char;
}

// Function to print the right-aligned character triangle
void print_triangle(int num_rows, char start_char) {
    int space_count = num_rows;

    for (int row = 1; row <= num_rows; row++) {
        // Print leading spaces
        for (int space_col = 1; space_col < space_count; space_col++) {
            printf(" ");
        }

        // Print characters for current row
        char current_char = start_char;
        for (int col = 1; col <= row; col++) {
            printf(" %c", current_char);
            current_char++;
        }

        space_count--; 
        printf("\n");
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
