/*
 * Purpose: Demonstrates iterating through a range of numbers, checking divisibility, and counting.
 * Topic: Loops, Conditional Statements, Basic I/O
 */

#include <stdio.h>

int main(void) {
    int start_range, end_range; // Variables to store the start and end of the range
    int count_not_divisible = 0; // Counter for numbers not divisible by 6
    int current_number; // Loop variable for iterating through the range

    // Prompt user for input and read the range
    printf("Enter two integers (start and end of range, separated by comma): ");
    scanf("%d, %d", &start_range, &end_range);

    // Loop through the numbers in the specified range
    for (current_number = start_range; current_number <= end_range; current_number++) {
        // Check if the current number is not divisible by 6
        if (current_number % 6) {
            printf("%d\n", current_number); // Print the number if it's not divisible by 6
            count_not_divisible++; // Increment the counter
        }
    }

    // Print the total count of numbers not divisible by 6
    printf("The total number of integers not divisible by 6 is: %d\n", count_not_divisible);

    return 0;
}
