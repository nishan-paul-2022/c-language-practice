/*
 * Purpose: Checks if a given integer is a prime number.
 * Topic: Prime Numbers, Loops, Conditional Statements
 */

#include <stdio.h>
#include <math.h>

int is_prime(int num) {
    if (num < 2) {
        return 0;
    }
    if (num == 2) {
        return 1;
    }
    if (num % 2 == 0) {
        return 0;
    }

    for (int i = 3; i <= sqrt(num); i += 2) {
        if (num % i == 0) {
            return 0;
        }
    }
    
    return 1;
}

int main(void) {
    int number;
    printf("Enter an integer: ");
    if (scanf("%d", &number) != 1) {
        printf("Error: Invalid input. Please enter an integer.\n");
        return 0;
    }

    printf("%d is %sprime.\n", number, is_prime(number) ? "" : "not ");
    return 0;
}
