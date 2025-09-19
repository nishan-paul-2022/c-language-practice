/*
 * Purpose: Reada and printa 2D array.
 * Topic: Arrays, Functions
 */

#include <stdio.h>
#include <stdlib.h>

void get_dimensions(int *rows, int *cols) {
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", rows, cols);
}

void input_array(int rows, int cols, int **arr) {
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
}

void print_array(int rows, int cols, int **arr) {
    printf("\nThe array is:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int **allocate_2d_array(int rows, int cols) {
    int **arr = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        arr[i] = (int *)malloc(cols * sizeof(int));
    }
    return arr;
}

void free_2d_array(int **arr, int rows) {
    for (int i = 0; i < rows; i++) {
        free(arr[i]);
    }
    free(arr);
}

int main(void) {
    int r, c;
    
    get_dimensions(&r, &c);
    
    int **a = allocate_2d_array(r, c);
    
    input_array(r, c, a);
    print_array(r, c, a);
    
    free_2d_array(a, r);
    
    return 0;
}
