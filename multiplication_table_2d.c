/*
 * Purpose: Demonstrates creating and printing a 2D array with values based on row and column indices.
 * Topic: 2D Arrays, Nested Loops, Input/Output
 */

#include <stdio.h>
#include <stdlib.h>

int read_dimensions(int *rows, int *cols) {
    printf("Enter the number of rows and columns (e.g., 3 4): ");
    if (scanf("%d %d", rows, cols) != 2) {
        fprintf(stderr, "Error: Invalid input for dimensions.\n");
        return -1;
    }
    while (getchar() != '\n');
    return 0;
}

void populate_array(int rows, int cols, int array_grid[rows][cols]) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            array_grid[i][j] = (i + 1) * (j + 1);
        }
    }
}

void print_array(int rows, int cols, int array_grid[rows][cols]) {
    int i, j;
    printf("\nGenerated Multiplication Table:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%4d", array_grid[i][j]);
        }
        printf("\n");
    }
}

int main(void) {
    int rows, cols;

    if (read_dimensions(&rows, &cols) == -1) {
        return 0;
    }

    int array_grid[rows][cols];
    
    populate_array(rows, cols, array_grid);
    print_array(rows, cols, array_grid);

    return 0;
}
