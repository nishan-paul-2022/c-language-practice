/*
 * Purpose: Demonstrates printing a right-aligned triangle of asterisks using nested loops.
 * Topic: Loops, Nested Loops, Character Output
 */

#include <stdio.h>

// Function to safely read the number of rows
int get_num_rows(void) {
    int rows;
    printf("Enter the number of rows for the star triangle: ");
    
    // Input validation loop
    while (scanf("%d", &rows) != 1 || rows <= 0) {
        printf("Invalid input. Please enter a positive integer for the number of rows: ");
        while (getchar() != '\n'); // Clear input buffer
        return -1;
    }
    
    return rows;
}

// Function to print the right-aligned star triangle
void print_star_triangle(int rows, char star_char) {
    for (int i = 1; i <= rows; i++) {
        // Print leading spaces
        for (int space = 1; space <= rows - i; space++) {
            printf(" ");
        }
        // Print stars
        for (int j = 1; j <= i; j++) {
            printf("%c", star_char);
        }
        printf("\n"); // Move to next line
    }
}

int main(void) {
    int rows = get_num_rows();
    if (rows == -1) {
        return 0;
    }

    char star_char = '*';

    print_star_triangle(rows, star_char);

    return 0;
}
