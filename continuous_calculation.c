/*
 * Purpose: To continuously read two integers, calculate a value, and print the result.
 * Topic: Loops, Basic I/O
 */

#include <stdio.h>

// Print program header and instructions
void print_header() {
    printf("=== Continuous Distance Calculator ===\n");
    printf("Formula: Distance = 2 * Velocity * Time\n");
    printf("Enter velocity and time pairs (invalid input to quit)\n\n");
}

// Read velocity and time values
int read_values(int *velocity, int *time) {
    printf("Enter velocity and time: ");
    return scanf("%d %d", velocity, time) == 2;
}

// Calculate distance using the formula
int calculate_distance(int velocity, int time) {
    return 2 * velocity * time;
}

// Display the calculation result
void display_result(int velocity, int time, int distance) {
    printf("Result: Distance = 2 * %d * %d = %d\n\n", velocity, time, distance);
}

// Process calculations until invalid input
void process_calculations() {
    int velocity, time, distance;
    
    while (read_values(&velocity, &time)) {
        distance = calculate_distance(velocity, time);
        display_result(velocity, time, distance);
    }
}

int main(void) {
    print_header();
    process_calculations();
    printf("Calculator terminated. Thanks for using!\n");
    return 0;
}
