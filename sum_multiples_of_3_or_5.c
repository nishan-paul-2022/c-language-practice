#include <stdio.h>

int main(void) {
    int sum_of_multiples = 0; // Variable to store the sum
    int limit = 1000;         // The upper limit (exclusive) for numbers to consider

    // Iterate through numbers from 1 up to (but not including) the limit.
    // The original code used two loops, which would double-count multiples of 15.
    // This single loop correctly sums numbers divisible by 3 OR 5.
    for (int i = 1; i < limit; i++) {
        // Check if the current number 'i' is a multiple of 3 OR a multiple of 5.
        if (i % 3 == 0 || i % 5 == 0) {
            // If it is, add it to the total sum.
            sum_of_multiples += i;
        }
    }

    // Print the final calculated sum.
    printf("%d\n", sum_of_multiples);

    return 0;
}
