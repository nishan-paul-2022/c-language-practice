/*
 * Purpose: To continuously read two integers, calculate a value, and print the result.
 * Topic: Loops, Basic I/O
 */

#include <stdio.h>

int main() {
    int velocity, time, distance;
    
    printf("Continuous Distance Calculator\n");
    printf("Formula: Distance = 2 * Velocity * Time\n");
    printf("Enter velocity and time (or non-integer to quit): \n");
    while (scanf("%d %d", &velocity, &time) == 2) {
        distance = 2 * velocity * time;
        printf("Distance (2 * v * t): %d\n", distance);
    }
    
    return 0;
}
