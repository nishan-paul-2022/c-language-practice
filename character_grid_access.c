/*
 * Purpose: Demonstrates accessing a specific character within a 2D array of characters.
 * Topic: 2D Arrays, Character Arrays, Input/Output
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_ROW_LEN 100 // Define a maximum length for each row to prevent buffer overflow with fgets

int main(void) {
    int rows, cols;
    int row_index, col_index;
    char input_buffer[MAX_ROW_LEN]; // Buffer for reading lines

    // Prompt for and read the dimensions of the 2D array
    printf("Enter the number of rows and columns (e.g., 3 4): ");
    if (scanf("%d %d", &rows, &cols) != 2) {
        fprintf(stderr, "Error: Invalid input for dimensions.\n");
        return EXIT_FAILURE;
    }

    // Consume the newline character left by scanf
    while (getchar() != '\n');

    // Dynamically allocate memory for the 2D array of characters
    // Note: For simplicity and to avoid complex memory management in this example,
    // we'll use a fixed-size array of character pointers and then allocate each row.
    // A true dynamic 2D array would involve more careful allocation and error checking.
    // For this example, we'll stick to a VLA-like approach with fgets for simplicity,
    // but with better safety.
    char (*char_grid)[cols] = malloc(rows * sizeof(*char_grid));
    if (char_grid == NULL) {
        fprintf(stderr, "Error: Memory allocation failed for character grid.\n");
        return EXIT_FAILURE;
    }

    printf("Enter the characters for the %d x %d grid, one row per line:\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        printf("Row %d: ", i);
        if (fgets(char_grid[i], cols + 1, stdin) == NULL) { // Read up to 'cols' characters + null terminator
            fprintf(stderr, "Error: Failed to read row %d.\n", i);
            free(char_grid); // Free allocated memory before exiting
            return EXIT_FAILURE;
        }
        // Remove trailing newline character if present
        char_grid[i][strcspn(char_grid[i], "\n")] = 0;
    }

    printf("\nGrid entered:\n");
    for (int i = 0; i < rows; i++) {
        printf("%s\n", char_grid[i]);
    }

    // Prompt for and read the row and column index to access
    printf("\nEnter the row and column index to access (e.g., 1 2): ");
    if (scanf("%d %d", &row_index, &col_index) != 2) {
        fprintf(stderr, "Error: Invalid input for indices.\n");
        free(char_grid);
        return EXIT_FAILURE;
    }

    // Validate indices
    if (row_index < 0 || row_index >= rows || col_index < 0 || col_index >= cols) {
        fprintf(stderr, "Error: Indices out of bounds.\n");
        free(char_grid);
        return EXIT_FAILURE;
    }

    // Print the character at the specified index
    printf("\nCharacter at [%d][%d]: %c\n", row_index, col_index, char_grid[row_index][col_index]);

    // Free the dynamically allocated memory
    free(char_grid);

    return 0;
}
