/*
 * Purpose: Prints an inverted right-aligned triangle pattern using characters.
 * Topic: Nested Loops, Character Manipulation, Spacing
 */

#include <stdio.h>
#include <stdlib.h>

int get_input_data(int *num_rows, char *start_char) {
    printf("Enter number of rows: ");
    if (scanf("%d", num_rows) != 1 || *num_rows <= 0) {
        fprintf(stderr, "Error: Invalid input for number of rows.\n");
        return -1;
    }

    printf("Enter starting character: ");
    while (getchar() != '\n'); // Consume newline
    if (scanf("%c", start_char) != 1) {
        fprintf(stderr, "Error: Invalid input for starting character.\n");
        return -1;
    }
    
    return 0;
}

void print_inverted_triangle(int num_rows, char start_char) {
    int space_count = 1;

    for (int row = num_rows; row >= 1; row--) {
        for (int space_col = 1; space_col <= space_count; space_col++) {
            printf(" ");
        }

        char current_char = start_char;
        for (int col = 1; col <= row; col++) {
            printf("%c", current_char);
            current_char++;
        }
        
        printf("\n");
        space_count++;
    }
}

int main(void) {
    int num_rows;
    char start_char;

    if (get_input_data(&num_rows, &start_char) == 0) {
        print_inverted_triangle(num_rows, start_char);
    }

    return 0;
}
