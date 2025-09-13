/*
 * Purpose: Reads three integers and determines the largest among them using nested ternary operators.
 *          This version fixes an issue where character types were incorrectly used for integer input/output.
 * Topic: Conditional Operator (Ternary), Basic I/O, Data Types
 */

#include <stdio.h>

int find_largest(int a, int b, int c) {
    return (a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c);
}

int main(void) {
    int num1, num2, num3;

    printf("Enter three integers: ");
    scanf("%d %d %d", &num1, &num2, &num3);

    int largest_number = find_largest(num1, num2, num3);
    printf("The largest number is: %d\n", largest_number);

    return 0;
}
