/*
 * Purpose: Prints a sequence of numbers in a descending order, formatted into rows of 5 numbers each.
 * Topic: Nested Loops, Descending Order, Tab Separation, Newline Formatting
 */

#include <stdio.h>

int main() {
    int i;
    int j;

    // Outer loop: counts down from 1000, decrementing by 5 each iteration
    // This sets the starting number for each row
    for (i = 1000; i >= 1; i -= 5) {
        // Inner loop: iterates 5 times, starting from current value of 'i'
        // Prints numbers from 'i' down to 'i-4'
        for (j = i; j > i - 5; j--) {
            // Print current number followed by a tab for spacing
            printf("%d\t", j);
        }
        // After printing 5 numbers, print a newline to move to next row
        printf("\n");
    }

    return 0;
}
