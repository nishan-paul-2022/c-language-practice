/*
 * Purpose: Reads a sequence of numbers and determines if they are in ascending,
 *          descending, equivalent, or unsorted order.
 * Topic: Arrays, Conditional Logic, Loops
 */

#include <stdio.h>

int main() {
    int numbers[5];
    int i;
    int is_ascending = 1;
    int is_descending = 1;
    int is_equivalent = 1;

    printf("Enter 5 integers, separated by spaces or newlines:\n");

    for (i = 0; i < 5; i++) {
        // Use " %d" to consume any leading whitespace, including newlines
        if (scanf(" %d", &numbers[i]) != 1) {
            printf("Invalid input. Please enter integers only.\n");
            return 0;
        }
    }

    // Check the order of the numbers
    for (i = 0; i < 4; i++) {
        // Check for ascending order (allows duplicates)
        if (numbers[i] > numbers[i+1]) {
            is_ascending = 0;
        }
        // Check for descending order (allows duplicates)
        if (numbers[i] < numbers[i+1]) {
            is_descending = 0;
        }
        // Check for equivalent numbers
        if (numbers[i] != numbers[i+1]) {
            is_equivalent = 0;
        }
    }

    // Output the result
    if (is_equivalent) {
        printf("EQUIVALENT\n");
    } else if (is_ascending) {
        printf("ASCENDING\n");
    } else if (is_descending) {
        printf("DESCENDING\n");
    } else {
        printf("NOT SORTED\n");
    }

    return 0;
}
