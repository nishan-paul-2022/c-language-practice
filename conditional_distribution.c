/*
 * Purpose: For a given number, prints 10 and the number minus 10 if the number is greater than 10, otherwise prints the number and 0.
 * Topic: Conditional Operator, Basic I/O
 */

#include <stdio.h>

int main() {
    int num_tests, i, value;

    printf("Enter the number of test cases: ");
    scanf("%d", &num_tests);

    for (i = 0; i < num_tests; i++) {
        printf("Enter a value: ");
        scanf("%d", &value);

        if (value <= 10) {
            printf("%d %d\n", value, 0);
        } else {
            printf("%d %d\n", 10, value - 10);
        }
    }

    return 0;
}
