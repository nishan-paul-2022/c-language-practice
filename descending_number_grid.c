// Purpose: Prints a sequence of numbers in a descending order, formatted into rows of 5 numbers each.
// Topic: Nested Loops, Descending Order, Tab Separation, Newline Formatting

#include <stdio.h>

int main() {
    int i; // Outer loop counter, controls the start of each row.
    int j; // Inner loop counter, prints numbers within a row.

    // Outer loop: counts down from 1000, decrementing by 5 in each iteration.
    // This sets the starting number for each row.
    for (i = 1000; i >= 1; i -= 5) {
        // Inner loop: iterates 5 times, starting from the current value of 'i'.
        // It prints numbers from 'i' down to 'i-4'.
        for (j = i; j > i - 5; j--) {
            // Print the current number followed by a tab for spacing.
            printf("%d\t", j);
        }
        // After printing 5 numbers in a row, print a newline character
        // to move to the next line for the next set of numbers.
        printf("\n");
    }

    return 0;
}
