/*
 * Purpose: Demonstrates recursion by printing numbers in descending order.
 * Topic: Recursion, Static Variables, Function Calls
 */

#include <stdio.h>


void print_countdown_recursive() {
    static int counter = 0; 

    counter++; 

    if (counter > 5) {
        return; 
    }

    print_countdown_recursive(); 

    printf("%d\n", counter); 
}

int main(void) {
    printf("Starting countdown...\n");
    print_countdown_recursive(); 
    printf("Countdown finished.\n");
    return 0;
}
