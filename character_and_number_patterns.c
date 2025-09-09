// Purpose: Demonstrates printing various character and number patterns using nested loops.
// Topic: Patterns, Nested Loops, Functions, Characters, Numbers

#include <stdio.h>

// Function to print a right-aligned character triangle pattern
void print_right_aligned_char_triangle(int num_rows, char start_char) {
    if (num_rows <= 0) return; // Handle invalid input

    printf("--- Right-aligned Character Triangle ---\n");
    for (int row = 1; row <= num_rows; row++) {
        char current_char = start_char;
        // Print spaces for alignment
        for (int space = 1; space <= num_rows - row; space++) {
            printf("  "); // Two spaces for better visual separation
        }
        // Print characters for the current row
        for (int col = 1; col <= row; col++) {
            printf("%c ", current_char++);
        }
        printf("\n");
    }
    printf("--------------------------------------\n");
}

// Function to print a left-aligned character triangle pattern
void print_left_aligned_char_triangle(int num_rows, char start_char) {
    if (num_rows <= 0) return; // Handle invalid input

    printf("--- Left-aligned Character Triangle ---\n");
    for (int row = 1; row <= num_rows; row++) {
        char current_char = start_char;
        // Print characters for the current row
        for (int col = 1; col <= row; col++) {
            printf("%c", current_char++);
        }
        printf("\n");
    }
    printf("-------------------------------------\n");
}

// Function to print a right-aligned number triangle pattern
void print_right_aligned_number_triangle(int num_rows) {
    if (num_rows <= 0) return; // Handle invalid input

    printf("--- Right-aligned Number Triangle ---\n");
    for (int row = 1; row <= num_rows; row++) {
        // Print spaces for alignment
        for (int space = 1; space <= num_rows - row; space++) {
            printf(" "); // Single space for alignment
        }
        // Print numbers for the current row
        for (int col = 1; col <= row; col++) {
            printf("%d ", row); // Print the current row number
        }
        printf("\n");
    }
    printf("-------------------------------------\n");
}

int main() {
    int rows1, rows2, rows3;
    char char1, char2;

    // Pattern 1: Right-aligned character triangle
    printf("--- Pattern 1 Configuration ---\n");
    printf("Enter the number of rows for the first pattern: ");
    if (scanf("%d", &rows1) != 1) {
        printf("Error: Invalid input for rows.\n");
        return 1;
    }
    printf("Enter the starting character: ");
    if (scanf(" %c", &char1) != 1) { // Space before %c to consume any leftover newline
        printf("Error: Invalid input for character.\n");
        return 1;
    }

    // Pattern 2: Left-aligned character triangle
    printf("\n--- Pattern 2 Configuration ---\n");
    printf("Enter the number of rows for the second pattern: ");
    if (scanf("%d", &rows2) != 1) {
        printf("Error: Invalid input for rows.\n");
        return 1;
    }
    printf("Enter the starting character: ");
    if (scanf(" %c", &char2) != 1) { // Space before %c
        printf("Error: Invalid input for character.\n");
        return 1;
    }

    // Pattern 3: Right-aligned number triangle
    printf("\n--- Pattern 3 Configuration ---\n");
    printf("Enter the number of rows for the third pattern: ");
    if (scanf("%d", &rows3) != 1) {
        printf("Error: Invalid input for rows.\n");
        return 1;
    }

    // Print the patterns
    print_right_aligned_char_triangle(rows1, char1);
    print_left_aligned_char_triangle(rows2, char2);
    print_right_aligned_number_triangle(rows3);

    return 0;
}
