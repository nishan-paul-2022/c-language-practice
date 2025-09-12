/*
 * Purpose: Finds and prints the first 'n' perfect numbers.
 *          A perfect number is a positive integer that is equal to the sum of its proper positive divisors.
 * Topic: Number Theory, Loops, Divisibility
 */

#include <stdio.h>

// Checks if a number is a perfect number.
int is_perfect(int num) {
    if (num <= 1) {
        return 0;
    }

    int sum_of_divisors = 1;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            sum_of_divisors += i;
            if (i * i != num) {
                sum_of_divisors += num / i;
            }
        }
    }
    return sum_of_divisors == num;
}

// Finds and prints the first n perfect numbers.
void find_perfect_numbers(int n) {
    if (n <= 0) {
        printf("Please enter a positive integer.\n");
        return;
    }

    printf("The first %d perfect numbers are:\n", n);
    int count = 0;
    long long num = 2;
    while (count < n) {
        if (is_perfect(num)) {
            printf("%lld ", num);
            count++;
        }
        num++;
    }
    printf("\n");
}

int main(void) {
    int count_needed;
    printf("Enter the number of perfect numbers to find: ");
    if (scanf("%d", &count_needed) != 1) {
        printf("Invalid input. Please enter an integer.\n");
        return 0;
    }

    find_perfect_numbers(count_needed);

    return 0;
}
