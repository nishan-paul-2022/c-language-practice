// Purpose: Demonstrates printing a right-aligned triangle of asterisks using nested loops.
// Topic: Loops, Nested Loops, Character Output

#include <stdio.h>

int main() {
    int rows;
    char star_char = '*';
    
    printf("Enter the number of rows for the star triangle: ");
    // Read the number of rows from the user.
    // Basic input validation: ensure a positive integer is entered.
    while (scanf("%d", &rows) != 1 || rows <= 0) {
        printf("Invalid input. Please enter a positive integer for the number of rows: ");
        // Clear the input buffer in case of non-integer input
        while (getchar() != '\n'); 
    }

    // Outer loop controls the number of rows.
    for (int i = 1; i <= rows; i++) {
        // Inner loop controls the number of stars and spaces for each row.
        // For a right-aligned triangle, we print (rows - i) spaces, then i stars.
        
        // Print leading spaces for right alignment
        for (int space = 1; space <= rows - i; space++) {
            printf(" ");
        }
        
        // Print stars for the current row
        for (int j = 1; j <= i; j++) {
            printf("%c", star_char);
        }
        
        // Move to the next line after printing stars for the current row.
        printf("\n");
    }
    
    return 0;
}
