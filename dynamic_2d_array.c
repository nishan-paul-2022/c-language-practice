/*
 * Purpose: To read and print a 2D array.
 * Topic: Arrays, Functions
 */

#include <stdio.h>

void print_array(int rows, int cols, int arr[rows][cols]) {
    int i, j;
    printf("\nThe array is:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int r, c, i, j;

    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &r, &c);

    int a[r][c];

    printf("Enter the elements of the array:\n");
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    print_array(r, c, a);

    return 0;
}
