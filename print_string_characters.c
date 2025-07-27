// Purpose: Demonstrates reading strings into a 2D array and printing each character.
// Topic: 2D Arrays, Strings, Character Access, Input/Output

#include <stdio.h>
#include <string.h> // For strlen, strcspn
#include <stdlib.h> // For exit() and EXIT_FAILURE

#define MAX_ROWS 100 // Maximum number of rows
#define MAX_COLS 100 // Maximum number of columns for each string

int main(void) {
    int rows, cols;
    char char_array[MAX_ROWS][MAX_COLS]; // 2D array to store strings

    // Prompt for and read the number of rows and columns
    printf("Enter the number of rows and columns (e.g., 3 4): ");
    if (scanf("%d %d", &rows, &cols) != 2) {
        fprintf(stderr, "Error: Invalid input for dimensions.\n");
        return EXIT_FAILURE;
    }

    // Consume the newline character left by scanf
    while (getchar() != '\n');

    // Validate dimensions
    if (rows <= 0 || rows > MAX_ROWS || cols <= 0 || cols > MAX_COLS) {
        fprintf(stderr, "Error: Dimensions out of range. Rows: 1-%d, Cols: 1-%d\n", MAX_ROWS, MAX_COLS);
        return EXIT_FAILURE;
    }

    printf("Enter the strings for each row (max %d characters per string):\n", cols - 1);
    // Read strings into the 2D array
    for (int i = 0; i < rows; i++) {
        printf("Row %d: ", i);
        // Use fgets for safe string input, reading up to 'cols-1' characters to leave space for null terminator
        if (fgets(char_array[i], cols, stdin) == NULL) {
            fprintf(stderr, "Error: Failed to read string for row %d.\n", i);
            return EXIT_FAILURE;
        }
        // Remove trailing newline character if present
        char_array[i][strcspn(char_array[i], "\n")] = 0;
    }

    printf("\nCharacters in the array:\n");
    // Print each character of each string
    for (int i = 0; i < rows; i++) {
        // Iterate up to the length of the string in the current row, or up to 'cols-1' if string is longer
        // Note: strlen(char_array[i]) is used to print only the characters entered,
        // not the full allocated 'cols' if the input string was shorter.
        for (int j = 0; j < strlen(char_array[i]); j++) {
            printf("%c ", char_array[i][j]);
        }
        printf("\n"); // Newline after processing each row
    }

    return 0;
}
