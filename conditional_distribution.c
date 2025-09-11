/*
 * Purpose: For a given number, prints 10 and the number minus 10 if the number is greater than 10, otherwise prints the number and 0.
 * Topic: Conditional Operator, Basic I/O
 */

#include <stdio.h>

int main(void) {
    int num_tests, i, value;
    
    printf("Conditional Distribution Calculator\n");
    printf("Enter the number of test cases: ");
    scanf("%d", &num_tests);
    
    for (i = 0; i < num_tests; i++) {
        printf("Enter a value for test case %d: ", i + 1);
        scanf("%d", &value);
        
        if (value <= 10) {
            printf("Result for test case %d: %d %d\n", i + 1, value, 0);
        } else {
            printf("Result for test case %d: %d %d\n", i + 1, 10, value - 10);
        }
    }
    
    return 0;
}
