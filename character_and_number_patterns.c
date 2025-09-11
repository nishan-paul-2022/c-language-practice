/*
 * Purpose: Demonstrates printing various character and number patterns using nested loops.
 * Topic: Patterns, Nested Loops, Functions, Characters, Numbers
*/

#include <stdio.h>

int get_num_rows() {
    printf("Enter the number of rows: ");
    int num_rows;
    if (scanf("%d", &num_rows) != 1) {
        printf("Error: Invalid input for rows.\n");
        return 0;
    }
    return num_rows;
}

char get_start_char() {
    printf("Enter the starting character: ");
    char start_char;
    if (scanf(" %c", &start_char) != 1) { // Space before %c to consume leftover newline
        printf("Error: Invalid input for character.\n");
        return 0;
    }
    return start_char;
}

// Pattern 1: Right-aligned character triangle
void print_right_aligned_char_triangle() {
    printf("--- Right-aligned Character Triangle ---\n");
    
    int num_rows = get_num_rows();
    char start_char = get_start_char();

    if (num_rows <= 0) return;

    for (int row = 1; row <= num_rows; row++) {
        char current_char = start_char;
        for (int space = 1; space <= num_rows - row; space++) {
            printf("  ");
        }
        for (int col = 1; col <= row; col++) {
            printf("%c ", current_char++);
        }
        printf("\n");
    }
}

// Pattern 2: Left-aligned character triangle
void print_left_aligned_char_triangle() {
    printf("--- Left-aligned Character Triangle ---\n");

    int num_rows = get_num_rows();
    char start_char = get_start_char();

    if (num_rows <= 0) return;

    for (int row = 1; row <= num_rows; row++) {
        char current_char = start_char;
        for (int col = 1; col <= row; col++) {
            printf("%c", current_char++);
        }
        printf("\n");
    }
}

// Pattern 3: Right-aligned number triangle
void print_right_aligned_number_triangle() {
    printf("--- Right-aligned Number Triangle ---\n");

    int num_rows = get_num_rows();

    if (num_rows <= 0) return;

    for (int row = 1; row <= num_rows; row++) {
        for (int space = 1; space <= num_rows - row; space++) {
            printf(" ");
        }
        for (int col = 1; col <= row; col++) {
            printf("%d ", row);
        }
        printf("\n");
    }
}

int main(void) {
    print_right_aligned_char_triangle();
    print_left_aligned_char_triangle();
    print_right_aligned_number_triangle();

    return 0;
}
