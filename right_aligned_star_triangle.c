/*
 * Purpose: Demonstrates printing a right-aligned triangle of asterisks using nested loops.
 * Topic: Loops, Nested Loops, Character Output
 */

#include <stdio.h>


int get_num_rows() {
    int rows;
    printf("Enter the number of rows for the star triangle: ");
    
    
    while (scanf("%d", &rows) != 1 || rows <= 0) {
        printf("Invalid input. Please enter a positive integer for the number of rows: ");
        while (getchar() != '\n'); 
        return -1;
    }
    
    return rows;
}


void print_star_triangle(int rows, char star_char) {
    for (int i = 1; i <= rows; i++) {
        
        for (int space = 1; space <= rows - i; space++) {
            printf(" ");
        }
        
        for (int j = 1; j <= i; j++) {
            printf("%c", star_char);
        }
        printf("\n"); 
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
