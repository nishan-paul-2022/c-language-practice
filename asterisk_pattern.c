/*
 * Purpose: Prints a specific pattern of asterisks to the console.
 * Topic: Nested Loops, Character Output, Pattern Printing
*/

#include <stdio.h>

int main() {
    int row_count, col_count, indent_count;

    // Part 1: Wide horizontal line (3 rows x 18 columns)
    for (row_count = 0; row_count < 3; row_count++) {
        for (col_count = 0; col_count < 18; col_count++) {
            printf(" *");
        }
        printf("\n");
    }

    // Part 2: Narrow horizontal line (3 rows x 4 columns)
    for (row_count = 0; row_count < 3; row_count++) {
        for (col_count = 0; col_count < 4; col_count++) {
            printf(" *");
        }
        printf("\n");
    }

    // Part 3: Repeat wide horizontal line (3 rows x 18 columns)
    for (row_count = 0; row_count < 3; row_count++) {
        for (col_count = 0; col_count < 18; col_count++) {
            printf(" *");
        }
        printf("\n");
    }

    // Part 4: Indented narrow horizontal line (3 rows x 4 columns)
    for (row_count = 0; row_count < 3; row_count++) {
        // Print 14 spaces for indentation
        for (indent_count = 0; indent_count < 14; indent_count++) {
            printf("  ");
        }
        // Print 4 asterisks
        for (col_count = 0; col_count < 4; col_count++) {
            printf(" *");
        }
        printf("\n");
    }

    // Part 5: Repeat wide horizontal line (3 rows x 18 columns)
    for (row_count = 0; row_count < 3; row_count++) {
        for (col_count = 0; col_count < 18; col_count++) {
            printf(" *");
        }
        printf("\n");
    }

    return 0; // Successful program execution
}
