/*
 * Purpose: To determine the type of a triangle based on its side lengths.
 * Topic: Conditional Statements, Basic I/O
 */

#include <stdio.h>

void check_triangle(int x, int y, int z, int case_num) {
    // Check for valid triangle
    if ((x + y > z) && (x + z > y) && (y + z > x)) {
        if (x == y && y == z) {
            printf("Case %d: Equilateral\n", case_num);
        } else if (x == y || y == z || z == x) {
            printf("Case %d: Isosceles\n", case_num);
        } else {
            printf("Case %d: Scalene\n", case_num);
        }
    } else {
        printf("Case %d: Invalid\n", case_num);
    }
}

int main(void) {
    int num_tests, i, x, y, z;

    printf("Enter the number of test cases: ");
    scanf("%d", &num_tests);

    for (i = 1; i <= num_tests; i++) {
        printf("Enter the three side lengths for case %d: ", i);
        scanf("%d %d %d", &x, &y, &z);
        check_triangle(x, y, z, i);
    }

    return 0;
}
