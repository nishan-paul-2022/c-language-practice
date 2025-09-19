/*
 * Purpose: Reads a sequence of numbers and determines if they are in ascending,
 *          descending, equivalent, or unsorted order.
 * Topic: Arrays, Conditional Logic, Loops
 */

#include <stdio.h>

int main(void) {
    int size = 5;
    int numbers[size];
    int is_ascending = 1;
    int is_descending = 1;
    int is_equivalent = 1;

    printf("Enter %d integers, separated by spaces or newlines:\n", size);

    for (int i = 0; i < size; i++) {
        // Use " %d" to consume any leading whitespace, including newlines
        if (scanf(" %d", &numbers[i]) != 1) {
            printf("Invalid input. Please enter integers only.\n");
            return 0;
        }
    }

    // Check the order of the numbers
    for (int i = 0; i < 4; i++) {
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
        printf("Equivalent\n");
    } else if (is_ascending) {
        printf("Ascending\n");
    } else if (is_descending) {
        printf("Descending\n");
    } else {
        printf("Unsorted\n");
    }

    return 0;
}
