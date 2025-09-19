/*
 * Purpose: Demonstrates creating and printing a 2D array with values based on row and column indices.
 * Topic: 2D Arrays, Nested Loops, Input/Output
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_DIMENSION 100

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int read_dimensions(int *rows, int *cols) {
    printf("Enter number of rows and columns (space-separated, max %d each): ", MAX_DIMENSION);
    
    if (scanf("%d %d", rows, cols) != 2) {
        fprintf(stderr, "Invalid input format. Please enter two integers.\n");
        clear_input_buffer();
        return -1;
    }
    
    if (*rows <= 0 || *cols <= 0) {
        fprintf(stderr, "Dimensions must be positive integers.\n");
        return -1;
    }
    
    if (*rows > MAX_DIMENSION || *cols > MAX_DIMENSION) {
        fprintf(stderr, "Dimensions exceed maximum allowed size (%d).\n", MAX_DIMENSION);
        return -1;
    }
    
    clear_input_buffer();

    return 0;
}

// Populate array with multiplication values
void populate_array(int rows, int cols, int **array_grid) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            array_grid[i][j] = (i + 1) * (j + 1);
        }
    }
}

// Display array in formatted table
void print_array(int rows, int cols, int **array_grid) {
    printf("\n2D Array (Multiplication Table):\n");
    printf("================================\n");
    
    // Print column headers
    printf("     ");
    for (int j = 0; j < cols; j++) {
        printf("%4d", j + 1);
    }
    printf("\n");
    
    // Print separator line
    printf("     ");
    for (int j = 0; j < cols; j++) {
        printf("----");
    }
    printf("\n");
    
    // Print rows with row headers
    for (int i = 0; i < rows; i++) {
        printf("%2d | ", i + 1);
        for (int j = 0; j < cols; j++) {
            printf("%4d", array_grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Allocate memory for 2D array
int** allocate_array(int rows, int cols) {
    int **array = (int**)malloc(rows * sizeof(int*));
    if (array == NULL) {
        return NULL;
    }
    
    for (int i = 0; i < rows; i++) {
        array[i] = (int*)malloc(cols * sizeof(int));
        if (array[i] == NULL) {
            for (int j = 0; j < i; j++) {
                free(array[j]);
            }
            free(array);
            return NULL;
        }
    }
    return array;
}

// Free allocated memory
void free_array(int **array, int rows) {
    if (array != NULL) {
        for (int i = 0; i < rows; i++) {
            free(array[i]);
        }
        free(array);
    }
}

// Display array creation summary
void display_summary(int rows, int cols) {
    printf("Array Summary:\n");
    printf("- Dimensions: %d x %d\n", rows, cols);
    printf("- Formula: array[i][j] = (i+1) * (j+1)\n");
    printf("- Total elements: %d\n", rows * cols);
}

int main(void) {
    printf("2D Array Generator\n");
    printf("==================\n");

    int rows, cols;

    printf("This program creates a 2D array where each element equals (row+1) * (column+1)\n\n");

    if (read_dimensions(&rows, &cols) == -1) {
        return 0;
    }
    
    int **array_grid = allocate_array(rows, cols);
    if (array_grid == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 0;
    }
    
    populate_array(rows, cols, array_grid);
    print_array(rows, cols, array_grid);
    display_summary(rows, cols);
    
    free_array(array_grid, rows);
    
    return 0;
}
