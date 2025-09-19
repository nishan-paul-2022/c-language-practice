/*
 * Purpose: Demonstrates reading strings into a 2D array and printing each character.
 * Topic: 2D Arrays, Strings, Character Access, Input/Output
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ROWS 100 // Max rows
#define MAX_COLS 100 // Max columns per string

void read_dimensions(int *rows, int *cols) {
    printf("Enter the number of rows and columns (e.g., 3 4): "); // Prompt user
    if (scanf("%d %d", rows, cols) != 2) {
        fprintf(stderr, "Invalid input for dimensions.\n");
        exit(0);
    }
    while (getchar() != '\n'); // Clear leftover newline
}

void validate_dimensions(int rows, int cols) {
    if (rows <= 0 || rows > MAX_ROWS || cols <= 0 || cols > MAX_COLS) {
        fprintf(stderr, "Dimensions out of range. Rows: 1-%d, Cols: 1-%d\n", MAX_ROWS, MAX_COLS);
        exit(0);
    }
}

void read_strings(int rows, int cols, char array[MAX_ROWS][MAX_COLS]) {
    printf("Enter the strings for each row (max %d characters per string):\n", cols - 1);
    for (int i = 0; i < rows; i++) {
        printf("Row %d: ", i); // Prompt for row input
        if (fgets(array[i], cols, stdin) == NULL) {
            fprintf(stderr, "Failed to read string for row %d.\n", i);
            exit(0);
        }
        array[i][strcspn(array[i], "\n")] = 0; // Remove trailing newline
    }
}

void print_characters(int rows, char array[MAX_ROWS][MAX_COLS]) {
    printf("\nCharacters in the array:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < strlen(array[i]); j++) {
            printf("%c ", array[i][j]); // Print each character
        }
        printf("\n");
    }
}

int main(void) {
    int rows, cols;
    char char_array[MAX_ROWS][MAX_COLS];

    read_dimensions(&rows, &cols);
    validate_dimensions(rows, cols);
    read_strings(rows, cols, char_array);
    print_characters(rows, char_array);

    return 0;
}
