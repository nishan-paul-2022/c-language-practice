/*
 * Purpose: To read a number of test cases and print the sum of two integers for each case.
 * Topic: Loops, Basic I/O
 */

#include <stdio.h>

int main(void) {
    int test_cases;
    int m, n, i;

    printf("Enter the number of test cases: ");
    scanf("%d", &test_cases);

    for (i = 1; i <= test_cases; i++) {
        printf("Enter two numbers for case %d: ", i);
        scanf("%d %d", &m, &n);
        printf("Case %d: %d\n", i, m + n);
    }

    return 0;
}
