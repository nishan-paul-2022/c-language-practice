/*
 * Purpose: Prints the multiplication table for a given number up to 10.
 * Topic: Multiplication Table, Loops, Input/Output
 */

#include <stdio.h>

int read_number() {
    int number;

    printf("Enter an integer to see its multiplication table: ");

    if (scanf("%d", &number) != 1) {
        printf("Invalid input. Please enter an integer.\n");
        return -1;
    }

    return number;
}

void print_multiplication_table(int number) {
    printf("\nMultiplication table for %d:\n", number);
    
    for (int multiplier = 1; multiplier <= 10; multiplier++) {
        printf("%d X %d = %d\n", number, multiplier, number * multiplier);
    }
}

int main(void) {
    int number = read_number();
    if (number == -1) {
        return 0;
    }
    
    print_multiplication_table(number);

    return 0;
}
