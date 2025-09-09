#include <stdio.h>

// Function to calculate the length of the Collatz sequence for a given number x.
// The Collatz conjecture states that for any positive integer x, repeatedly applying
// the rule: if x is even, divide it by 2; if x is odd, multiply it by 3 and add 1,
// will eventually lead to 1.
// steps is a pointer to an integer that counts the number of steps.
void calculate_collatz_length(int current_num, int *steps) {
    // Base case: if the number is 1, the sequence ends.
    if (current_num != 1) {
        // Check if the number is odd or even
        if (current_num % 2 != 0) { // Odd number
            current_num = 3 * current_num + 1;
        } else { // Even number
            current_num = current_num / 2;
        }
        // Increment the step count
        (*steps)++;
        // Recursive call with the new number and updated step count
        calculate_collatz_length(current_num, steps);
    }
}

int main() {
    int start_range, end_range; // The range of numbers to check
    int current_number;         // The number currently being processed
    int sequence_length;        // To store the length of the Collatz sequence for the current number
    int max_sequence_length = 0; // To store the maximum sequence length found in the range

    // Read the start and end of the range from input, expecting format "a - b"
    // The " - " in the format string ensures scanf reads the hyphen and spaces correctly.
    if (scanf("%d - %d", &start_range, &end_range) != 2) {
        fprintf(stderr, "Invalid input format. Please enter range as 'start - end'.\n");
        return 1; // Indicate an error
    }

    // Iterate through each number in the specified range
    for (current_number = start_range; current_number <= end_range; current_number++) {
        // Initialize the step count to 1 (for the starting number itself)
        sequence_length = 1;
        
        // Calculate the Collatz sequence length for the current number
        calculate_collatz_length(current_number, &sequence_length);
        
        // Update the maximum sequence length if the current sequence is longer
        if (sequence_length > max_sequence_length) {
            max_sequence_length = sequence_length;
        }
    }
    
    // Print the overall maximum sequence length found in the range.
    printf("%d\n", max_sequence_length);

    return 0;
}
