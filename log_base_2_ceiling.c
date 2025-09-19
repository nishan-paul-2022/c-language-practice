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

void display_result(int number, int k, int case_number) {
    printf("Case %d: For number %d, smallest k is: %d\n", case_number, number, k);
}

void process_input(int number, int case_number) {
    if (number > 0) {
        int k = find_smallest_power_of_two(number);
        display_result(number, k, case_number);
    } else {
        printf("Case %d: Invalid input (non-positive number): %d\n", case_number, number);
    }
}

int main(void) {
    int case_number = 1;

    printf("Enter positive integers to find smallest k where 2^k > number (Ctrl+D to exit):\n");

    while (1) {
        printf("Enter positive integer: ");
        int number;
        if (scanf("%d", &number) != 1) {
            printf("\nProgram terminated.\n");
            break;
        }
        
        process_input(number, case_number);
        case_number++;
    }

    return 0;
}
