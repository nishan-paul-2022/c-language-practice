/*
 * Purpose: Prints all numbers divisible by 7 within a specified range.
 * Topic: Divisibility, Loops, Conditional Statements, Input Parsing
 */

#include <stdio.h>

int main() {
    int start_num, end_num;
    int current_num;
    int remainder;

    printf("Enter the start and end of the range (e.g., 1, 100): ");
    // Read the range from user input in "start, end" format and validate
    // scanf returns the number of successfully matched and assigned input items.
    // We expect 2 integers to be read.
    if (scanf("%d, %d", &start_num, &end_num) != 2) {
        printf("Error: Invalid input format. Please use 'start, end' format (e.g., 1, 100).\n");
        return 0;
    }

    printf("\nNumbers divisible by 7 between %d and %d are:\n", start_num, end_num);

    // Iterate through the range
    for (current_num = start_num; current_num <= end_num; current_num++) {
        // Check if the current number is divisible by 7
        remainder = current_num % 7;
        if (remainder == 0) {
            printf("%d\n", current_num);
        }
    }

    return 0;
}
