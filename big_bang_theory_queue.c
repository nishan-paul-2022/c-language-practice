/*
 * Purpose: Solves a problem where a sequence of names repeats with doubling frequency.
 *          This is a classic problem often seen in programming contests.
 * Topic: Loops, Arrays, Large Integers (long long int), Problem Solving
 */

#include <stdio.h> // Required for printf and scanf
#include <string.h> // Required for string manipulation (though not strictly used here, good practice for string arrays)

int main() {
    long long int n_th_person; // Represents the N-th person in the queue
    long long int current_block_size = 1; // Represents the size of the current block of names (1, 2, 4, 8, ...)

    // Array of names
    char names[5][100] = {"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};

    // Read the N-th person's position
    printf("Enter the N-th person's position: ");
    scanf("%lld", &n_th_person);

    // Adjust n_th_person and current_block_size until n_th_person falls within the current block
    // Each block consists of 5 names, and the block size doubles in each iteration.
    while (current_block_size * 5 < n_th_person) {
        n_th_person -= current_block_size * 5; // Subtract the names from previous blocks
        current_block_size *= 2; // Double the block size for the next iteration
    }

    // Calculate the index of the name in the 'names' array
    // (n_th_person - 1) because array indices are 0-based
    // Divided by current_block_size to find which of the 5 names it corresponds to within the current block
    printf("%s\n", names[(n_th_person - 1) / current_block_size]);

    return 0; // Indicate successful execution
}
