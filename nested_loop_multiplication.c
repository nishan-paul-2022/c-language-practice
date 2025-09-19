/*
 * Purpose: Demonstrates nested loops to generate a pattern of numbers based on row and column indices, and calculates their sum.
 * Topic: Nested Loops and Pattern Generation with Multiplication
 */

#include <stdio.h>

int read_input_limit() {
    int input_limit;
    printf("Enter a positive integer (determines the number of rows): ");
    if (scanf("%d", &input_limit) != 1) {
        printf("Invalid input. Please enter an integer.\n");
        return 0;
    }

    if (input_limit <= 0) {
        printf("Input must be a positive integer.\n");
        return 0;
    }
    
    return input_limit;
}

int generate_pattern_and_calculate_sum(int input_limit) {
    int row, column;
    int current_value;
    int total_sum = 0;

    printf("Pattern:\n");

    for (row = 1; row <= input_limit; row++) {
        for (column = 1; column <= row; column++) {
            current_value = row * column;
            printf("%d ", current_value);
            total_sum += current_value;
        }
        printf("\n");
    }

    return total_sum;
}

void display_sum(int total_sum) {
    printf("Sum of all numbers in the pattern: %d\n", total_sum);
}

int main(void) {
    int input_limit = read_input_limit();
    
    if (input_limit == 0) {
        return 0;
    }

    int total_sum = generate_pattern_and_calculate_sum(input_limit);
    display_sum(total_sum);

    return 0;
}
