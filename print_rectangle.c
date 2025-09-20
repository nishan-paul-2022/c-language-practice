/*
 * Purpose: Reads a character and prints a rectangle of that character using a clean, function-based approach.
 * Topic: Functions, Nested Loops, Character Output, Input Validation
 */

#include <stdio.h>

char get_character() {
    char ch;
    printf("Enter a character: ");
    if (scanf(" %c", &ch) != 1) {
        printf("Invalid input. Please enter a character.\n");
        return '\0';
    }
    return ch;
}

int get_positive_integer(const char* prompt) {
    int value;
    printf("%s", prompt);
    if (scanf("%d", &value) != 1 || value <= 0) {
        printf("Invalid input. Please enter a positive integer.\n");
        return -1;
    }
    return value;
}

void print_rectangle(char ch, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%c", ch);
        }
        printf("\n");
    }
}

int main(void) {
    char ch = get_character();
    if (ch == '\0') {
        return 0;
    }

    int rows = get_positive_integer("Enter number of rows: ");
    if (rows <= 0) {
        return 0;
    }

    int cols = get_positive_integer("Enter number of columns: ");
    if (cols <= 0) {
        return 0;
    }

    printf("\n");
    print_rectangle(ch, rows, cols);

    return 0;
}
