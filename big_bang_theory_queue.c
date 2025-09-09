/*
 * Purpose: Solves a problem where a sequence of names repeats with doubling frequency.
 *          This is a classic problem often seen in programming contests.
 * Topic: Loops, Arrays, Large Integers (long long int), Problem Solving
 */

#include <stdio.h>
#include <string.h>

int main() {
    long long int n_th_person; // Target position in the sequence (1-indexed)
    long long int current_block_size = 1; // Repetition count for current name block

    // Character names in the sequence
    char names[5][100] = {"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};

    // Input target position
    printf("Enter the N-th person's position: ");
    scanf("%lld", &n_th_person);

    // Skip complete blocks with 5*current_block_size names
    // Reduce problem size by subtracting previous blocks
    while (current_block_size * 5 < n_th_person) {
        n_th_person -= current_block_size * 5; // Remove processed names count
        current_block_size *= 2; // Next block has 2x repetitions
    }

    // Map reduced position to name index in current block
    // Formula: (position-1) / repetitions gives 0-4 index
    printf("%s\n", names[(n_th_person - 1) / current_block_size]);

    return 0;
}
