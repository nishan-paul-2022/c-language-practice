/*
 * Purpose: Compares two integers and prints '>', '<', or '=' based on their relationship.
 * Topic: Conditional Statements, Basic I/O
 */

#include <stdio.h>

void compareIntegers(int x, int y) {
    if (x > y) {
        printf(">\n");
    } else if (x < y) {
        printf("<\n");
    } else {
        printf("=\n");
    }
}

void processTestCases() {
    int num_tests, i, x, y;

    printf("Enter number of test cases: ");
    scanf("%d", &num_tests);

    for (i = 0; i < num_tests; i++) {
        printf("Enter two integers: ");
        scanf("%d %d", &x, &y);
        compareIntegers(x, y);
    }
}

int main(void) {
    process_test_cases();
    return 0;
}
