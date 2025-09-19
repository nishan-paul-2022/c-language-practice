/*
 * Purpose: Prints a rectangle filled with a user-specified integer.
 * Topic: Nested Loops, Input Validation, Pattern Printing
 */

#include <stdio.h>

int main(void) {
    int number, rows, cols;

    
    printf("Enter the integer to fill the rectangle: ");
    if (scanf("%d", &number) != 1) {
        printf("Invalid input. Please enter an integer.\n");
        return 0;
    }

    
    printf("Enter the number of rows: ");
    if (scanf("%d", &rows) != 1 || rows <= 0) {
        printf("Invalid input. Rows must be a positive integer.\n");
        return 0;
    }

    
    printf("Enter the number of columns: ");
    if (scanf("%d", &cols) != 1 || cols <= 0) {
        printf("Invalid input. Columns must be a positive integer.\n");
        return 0;
    }

    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%4d", number); 
        }
        printf("\n");
    }

    return 0;
}
