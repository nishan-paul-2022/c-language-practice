/*
 * Purpose: Prints a pyramid pattern using asterisks.
 * Topic: Nested Loops, Star Patterns
 */

#include <stdio.h>

int main(void) {
    int total_rows;
    printf("Enter total number of rows: ");
    if (scanf("%d", &total_rows) == -1 || total_rows <=0) {
        printf("Invalid input.");
        return 0;
    }

    for (int row = 1; row <= total_rows; row++) {
        int stars;

        if (row <= (total_rows + 1) / 2) {
            stars = row;
        } else {
            stars = total_rows - row + 1;
        }

        for (int space = 1; space <= total_rows - stars; space++) {
            printf(" ");
        }

        for (int col = 1; col <= stars; col++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
