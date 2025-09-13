/*
 * Purpose: For each positive integer input, calculates smallest integer k such that 2^k is greater than number.
 * Topic: Loops, Arrays, Bitwise Operations (Powers of 2), Logarithms (conceptual)
 */

#include <stdio.h>

int find_smallest_power_of_two(int number) {
    int k = 0;
    while ((1 << k) <= number) {
        k++;
    }
    return k;
}

int read_numbers(int numbers[]) {
    int i;
    for (i = 1; i < 2000; i++) {
        printf("Enter number (negative to stop): ");
        scanf("%d", &numbers[i]);
        if (numbers[i] < 0) {
            break;
        }
    }
    return i;
}

void process_numbers(int numbers[], int count) {
    int j, k;
    for (j = 1; j < count; j++) {
        k = find_smallest_power_of_two(numbers[j]);
        printf("Case %d: %d\n", j, k);
    }
}

int main(void) {
    int numbers[2000];
    int count;

    numbers[0] = 0; // unused
    count = read_numbers(numbers);
    process_numbers(numbers, count);

    return 0;
}
