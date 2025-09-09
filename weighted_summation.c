// Purpose: Calculates a weighted sum of numbers from 1 to n.
// Topic: Loop-based Summation

#include <stdio.h>

int main() {
    int input_number;
    int counter;
    int multiplier;
    int total_sum = 0;

    // Prompt the user for input and validate it.
    printf("Enter a positive integer: ");
    if (scanf("%d", &input_number) != 1) {
        printf("Invalid input. Please enter an integer.\n");
        return 0;
    }

    // Ensure the input is positive, as the logic implies positive integers.
    if (input_number <= 0) {
        printf("Input must be a positive integer.\n");
        return 0;
    }

    // Calculate the weighted sum: 1*n + 2*(n-1) + 3*(n-2) + ... + n*1
    // The loop iterates from 1 up to input_number.
    // 'counter' represents the first term in the product (1, 2, 3, ...).
    // 'multiplier' represents the second term in the product (n, n-1, n-2, ...).
    for (counter = 1, multiplier = input_number; counter <= input_number; counter++, multiplier--) {
        total_sum += counter * multiplier;
    }

    // Print the calculated total sum.
    printf("The weighted sum is: %d\n", total_sum);

    return 0;
}
