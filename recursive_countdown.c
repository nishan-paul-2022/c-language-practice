/*
 * Purpose: Demonstrates recursion by printing numbers in descending order.
 * Topic: Recursion, Static Variables, Function Calls
 */

#include <stdio.h>

int get_countdown_start() {
    int start_value;
    printf("Enter countdown start value: ");
    if (scanf("%d", &start_value) != 1) {
        fprintf(stderr, "Invalid input.\n");
        return -1;
    }
    
    if (start_value < 0) {
        fprintf(stderr, "Start value must be non-negative.\n");
        return -1;
    }
    
    if (start_value > 1000) {
        fprintf(stderr, "Start value too large (max 1000).\n");
        return -1;
    }
    
    return start_value;
}

void print_countdown_recursive(int n) {
    if (n < 0) {
        return;
    }
    
    printf("%d ", n);
    print_countdown_recursive(n - 1);
}

void print_countdown_ascending_recursive(int current, int max) {
    if (current > max) {
        return;
    }
    
    print_countdown_ascending_recursive(current + 1, max);
    printf("%d ", current);
}

void demonstrate_recursion_patterns(int start_value) {
    printf("\nDescending countdown (standard recursion):\n");
    print_countdown_recursive(start_value);
    
    printf("\nAscending countdown (tail recursion with delayed print):\n");
    print_countdown_ascending_recursive(1, start_value);
}

int main(void) {
    printf("Recursive Countdown Demonstration\n");
    printf("=================================\n");
    
    int start_value = get_countdown_start();
    if (start_value == -1) {
        return 1;
    }
    
    demonstrate_recursion_patterns(start_value);
    
    printf("\nCountdown demonstrations completed.\n");
    return 0;
}
