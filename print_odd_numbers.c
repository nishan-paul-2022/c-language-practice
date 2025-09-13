/*
 * Purpose: Prints all odd numbers from 1 up to a user-specified limit.
 * Topic: Loops, Odd Numbers, Incrementing by 2
 */

#include <stdio.h>

int main(void) {
    int limit;

    printf("Enter the upper limit: ");
    if (scanf("%d", &limit) != 1 || limit < 1) {
        printf("Invalid input. Please enter a positive integer.\n");
        return 0;
    }

    printf("Odd numbers from 1 to %d:\n", limit);

    // Start from 1 and increment by 2 to get all odd numbers
    for (int num = 1; num <= limit; num += 2) {
        printf("%d ", num);
    }
    printf("\n");

    return 0;
}
