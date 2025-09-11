/*
 * Purpose: Solves a problem where a sequence of names repeats with doubling frequency.
 *          This is a classic problem often seen in programming contests.
 * Topic: Loops, Arrays, Large Integers (long long int), Problem Solving
 */

#include <stdio.h>
#include <string.h>

int main(void) {
    long long int n_th_person; // The 1-indexed position of the person in the queue.
    long long int current_block_size = 1; // Number of times each person is repeated in the current block.

    char names[5][100] = {"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};

    printf("Enter the N-th person's position: ");
    scanf("%lld", &n_th_person);

    // Skip full rounds of characters until we reach the round containing the N-th person
    // Each round has (5 * current_block_size) people, block size doubles each round
    while (current_block_size * 5 < n_th_person) {
        n_th_person -= current_block_size * 5;
        current_block_size *= 2;
    }

    // n_th_person is now the position within the current block
    // Find the character index by dividing (n_th_person - 1) by block size
    printf("%s\n", names[(n_th_person - 1) / current_block_size]);

    return 0;
}
