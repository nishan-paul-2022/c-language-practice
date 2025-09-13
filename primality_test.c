/*
 * Purpose: Determines if a given positive integer is a prime number.
 * Topic: Number Theory, Loops, Conditional Logic, Math Functions (sqrt)
 */

#include <stdio.h>
#include <math.h>

int is_prime(long long int number) {
    if (number <= 1) {
        return 0;
    }
    if (number == 2 || number == 3) {
        return 1;
    }
    if (number % 2 == 0) {
        return 0;
    }

    for (long long int i = 3; i <= sqrt(number); i += 2) {
        if (number % i == 0) {
            return 0;
        }
    }
    
    return 1;
}

int main(void) {
    long long int num_test_cases;
    scanf("%lld", &num_test_cases);

    while (num_test_cases--) {
        long long int number;
        scanf("%lld", &number);
        printf("%s\n", is_prime(number) ? "Yes" : "No");
    }

    return 0;
}
