/*
 * Purpose: Prints all numbers divisible by a user-specified number within a given range.
 * Topic: Divisibility, Loops, User Input, Functions
 */

#include <stdio.h>

int get_inputs(int *start, int *end, int *divisor) {
    printf("Enter the start and end of the range (e.g., 1, 100): ");
    if (scanf("%d, %d", start, end) != 2) {
        printf("Error: Invalid input format for range. Please use 'start, end'.\n");
        return 0;
    }

    printf("Enter the divisor: ");
    if (scanf("%d", divisor) != 1) {
        printf("Error: Invalid input for divisor.\n");
        return 0;
    }

    if (*divisor == 0) {
        printf("Error: Divisor cannot be zero.\n");
        return 0;
    }

    return 1;
}

void find_and_print_divisible_numbers(int start_num, int end_num, int divisor) {
    printf("\nNumbers divisible by %d between %d and %d are:\n", divisor, start_num, end_num);
    
    for (int current_num = start_num; current_num <= end_num; current_num++) {
        if (current_num % divisor == 0) {
            printf("%d ", current_num);
        }
    }

    printf("\n");
}

int main(void) {
    int start_num, end_num, divisor;
    
    if (!get_inputs(&start_num, &end_num, &divisor)) {
        fprintf(stderr, "Exiting due to input error.\n");
        return 1;
    }
    
    find_and_print_divisible_numbers(start_num, end_num, divisor);
    return 0;
}