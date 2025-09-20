/*
 * Purpose: Finds and prints the first 'n' perfect numbers.
 *          A perfect number is a positive integer that is equal to the sum of its proper positive divisors.
 * Topic: Number Theory, Loops, Divisibility
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int get_number_count() {
    int n;
    printf("Enter the number of perfect numbers to find: ");
    if (scanf("%d", &n) == -1) {
        fprintf(stderr, "Invalid input. Please enter a valid integer.\n");
        return -1;
    }
    
    if (n <= 0) {
        fprintf(stderr, "Number must be positive.\n");
        return -1;
    }
    
    if (n > 10) {
        printf("Finding more than 10 perfect numbers may take a very long time.\n");
        printf("Continue? (y/n): ");
        char choice;
        if (scanf(" %c", &choice) == 1 && (choice == 'n' || choice == 'N')) {
            return -1;
        }
    }
    
    return n;
}

long calculate_divisor_sum(long number) {
    if (number <= 1) {
        return 0;
    }
    
    long sum = 1;
    long sqrt_num = (long)sqrt(number);
    
    for (long i = 2; i <= sqrt_num; i++) {
        if (number % i == 0) {
            sum += i;
            if (i != number / i) {
                sum += number / i;
            }
        }
    }
    
    return sum;
}

int is_perfect_number(long number) {
    return (number > 1 && calculate_divisor_sum(number) == number);
}

void find_perfect_numbers(int count) {
    printf("\nFirst %d perfect number%s:\n\n", count, (count == 1) ? "" : "s");
    printf("%-10s %-15s\n", "Position", "Perfect Number");
    printf("%-10s %-15s\n", "--------", "--------------");
    
    int found = 0;
    long candidate = 2;
    
    while (found < count) {
        if (is_perfect_number(candidate)) {
            found++;
            printf("%-10d %-15ld\n", found, candidate);
        }
        candidate++;
        
        if (candidate > 100000 && found < 4) {
            printf("Searching beyond 100,000. This may take considerable time.\n");
        }
    }
}

void display_perfect_number_info() {
    printf("Perfect Number Finder\n");
    printf("=====================\n");
}

int main(void) {
    display_perfect_number_info();
    
    int count = get_number_count();
    if (count == -1) {
        return 0;
    }
    
    find_perfect_numbers(count);
    
    printf("\nSearch completed successfully.\n");
    return 0;
}
