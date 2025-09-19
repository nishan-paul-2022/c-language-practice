/*
 * Purpose: Demonstrates printing various character and number patterns using nested loops.
 * Topic: Patterns, Nested Loops, Functions, Characters, Numbers
*/

#include <stdio.h>
#include <stdlib.h>

int get_num_rows() {
    int num_rows;

    printf("Enter the number of rows: ");

    if (scanf("%d", &num_rows) == -1 || num_rows <= 0) {
        printf("Invalid input for rows.\n");
        return -1;
    }

    return num_rows;
}

char get_start_char() {
    char start_char;

    printf("Enter the starting character: ");

    if (scanf(" %c", &start_char) == -1) { // Space before %c to consume leftover newline
        printf("Invalid input for character.\n");
        return 0;
    }

    return start_char;
}

void print_right_aligned_number_triangle() {
    printf("--- Right-aligned Number Triangle ---\n");

    int num_rows = get_num_rows();
    if (num_rows == -1) {
        exit(1);
    }

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

void print_right_aligned_char_triangle() {
    printf("--- Right-aligned Character Triangle ---\n");
    
    int num_rows = get_num_rows();
    if (num_rows == -1) {
        exit(1);
    }

    char start_char = get_start_char();

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

void print_left_aligned_char_triangle() {
    printf("--- Left-aligned Character Triangle ---\n");

    int num_rows = get_num_rows();
    if (num_rows == -1) {
        exit(1);
    }

    char start_char = get_start_char();

    for (int row = 1; row <= num_rows; row++) {
        char current_char = start_char;
        for (int col = 1; col <= row; col++) {
            printf("%c", current_char++);
        }
        printf("\n");
    }
}

int main(void) {
    print_right_aligned_number_triangle();
    print_right_aligned_char_triangle();
    print_left_aligned_char_triangle();

    return 0;
}
