// Purpose: For each positive integer input, calculates the smallest integer k such that 2^k is greater than the number.
// Topic: Loops, Arrays, Bitwise Operations (Powers of 2), Logarithms (conceptual)

#include <stdio.h>

int main() {
    int numbers[2000]; // Array to store input numbers
    int i;
    int j;
    int k;             // Counter for power of 2

    // Read numbers into the array until a negative number is entered
    // The first element numbers[0] is unused, input starts from numbers[1]
    numbers[0] = 0; // Initialize to ensure loop starts
    for (i = 1; i < 2000; i++) { // Limit array size to prevent overflow
        scanf("%d", &numbers[i]);
        if (numbers[i] < 0) {
            break; // Stop reading if a negative number is encountered
        }
    }

    // Process each positive number read (excluding the sentinel negative number)
    for (j = 1; j < i; j++) { // Loop up to 'i-1' because 'i' holds the negative sentinel
        k = 0; // Reset k for each number

        // Find the smallest k such that (1 << k) is greater than numbers[j]
        // This is equivalent to ceil(log2(numbers[j]))
        while ((1 << k) <= numbers[j]) {
            k++;
        }
        printf("Case %d: %d\n", j, k);
    }

    return 0;
}
