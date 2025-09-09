// Purpose: Prints all odd numbers from 1 up to a specified limit.
// Topic: Loops and Conditional Logic (Printing Odd Numbers)

#include <stdio.h>

int main() {
    int number;
    const int limit = 20; // Define the upper limit for printing numbers.

    printf("Printing odd numbers from 1 to %d:\n", limit);

    // Loop through numbers starting from 1 and incrementing by 2 in each step.
    // This directly generates odd numbers, making the code more efficient and readable
    // compared to checking for even numbers and using 'continue'.
    for (number = 1; number <= limit; number += 2) {
        // Print the current odd number.
        printf("%d ", number);
    }
    printf("\n"); // Print a newline at the end for better formatting.

    return 0;
}
