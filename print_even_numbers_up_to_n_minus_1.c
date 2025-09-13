/*
 * Purpose: Prints all even numbers starting from 2 up to (but not including) a user-defined limit.
 * Topic: Loops, Conditional Logic, Basic I/O
 */

#include <stdio.h>

int main(void) {
    int limit;

    // Prompt the user to enter a positive integer
    printf("Enter an integer value: ");
    if (scanf("%d", &limit) != 1 || limit < 2) {
        printf("Invalid input. Please enter an integer >= 2.\n");
        return 0;
    }

    // Loop from 2 up to limit-1, printing even numbers
    for (int i = 2; i < limit; i += 2) {
        printf("%d\n", i);
    }

    return 0;
}
