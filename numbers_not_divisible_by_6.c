/*
 * Purpose: Demonstrates iterating through a range of numbers, checking divisibility, and counting.
 * Topic: Loops, Conditional Statements, Basic I/O
 */

#include <stdio.h>

void read_range(int *start, int *end) {
    printf("Enter two integers (start and end of range, separated by comma): ");
    scanf("%d, %d", start, end);
}

int is_not_divisible_by_six(int number) {
    return number % 6;
}

void print_and_count_non_divisible(int start_range, int end_range, int *count) {
    for (int current_number = start_range; current_number <= end_range; current_number++) {
        if (is_not_divisible_by_six(current_number)) {
            printf("%d\n", current_number);
            (*count)++;
        }
    }
}

void print_result(int count) {
    printf("The total number of integers not divisible by 6 is: %d\n", count);
}

int main(void) {
    int start_range, end_range;
    int count_not_divisible = 0;

    read_range(&start_range, &end_range);
    print_and_count_non_divisible(start_range, end_range, &count_not_divisible);
    print_result(count_not_divisible);

    return 0;
}
