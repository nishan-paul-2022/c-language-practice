/*
 * Purpose: Demonstrates pointer arithmetic with a 2D array, showing how to access elements using pointer notation.
 * Topic: Pointers, 2D Arrays, Pointer Arithmetic
 */

#include <stdio.h>

int* get_element_ptr(int matrix[2][3], int row, int col) {
    int* ptr = *(matrix + row) + col;
    return ptr;
}

int* get_element_ptr_flat(int *base_pointer, int row, int col, int cols_per_row) {
    int* ptr = base_pointer + row * cols_per_row + col;
    return ptr;
}

int main(void) {
    int matrix[2][3] = { {1, 2, 3}, {10, 20, 30} };
    int *base_pointer = (int *)matrix;

    int *ptr1 = get_element_ptr(matrix, 1, 2); // matrix[1][2]
    int *ptr2 = get_element_ptr_flat(base_pointer, 1, 1, 3); // matrix[1][1]

    printf("Value at matrix[1][2] (regular): %d\n", *ptr1);
    printf("Value at matrix[1][1] (via flat pointer): %d\n", *ptr2);

    return 0;
}
