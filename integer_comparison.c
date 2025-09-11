/*
 * Purpose: Compares two integers and prints '>', '<', or '=' based on their relationship.
 * Topic: Conditional Statements, Basic I/O
 */

#include <stdio.h>

int main(void) {
    int num_tests, i, x, y;

    printf("Enter the number of test cases: ");
    scanf("%d", &num_tests);

    for (i = 0; i < num_tests; i++) {
        printf("Enter two integers to compare: ");
        scanf("%d %d", &x, &y);

        if (x > y) {
            printf(">\n");
        } else if (x < y) {
            printf("<\n");
        } else {
            printf("=\n");
        }
    }

    return 0;
}
