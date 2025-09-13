/*
 * Purpose: Calculates the integer square root of a non-negative integer using the binary search algorithm.
 * Topic: Algorithms, Binary Search, Integer Math
 */

#include <stdio.h>

int calculate_integer_sqrt(int number) {
    if (number == 0) {
        return 0;
    }

    int low = 0;
    int high = number;
    int result = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2; // Prevents overflow

        if ((long long)mid * mid == number) {
            result = mid;
            break;
        }

        if ((long long)mid * mid < number) {
            result = mid; // Store potential answer
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return result;
}

void process_sqrt_requests() {
    int number;
    printf("Enter non-negative integer (0 to exit): ");
    
    while (scanf("%d", &number) == 1 && number >= 0) {
        if (number == 0) {
            printf("Exiting.\n");
            break;
        }

        int result = calculate_integer_sqrt(number);
        printf("Integer square root of %d is %d\n", number, result);
        printf("Enter non-negative integer (0 to exit): ");
    }
}

int main(void) {
    process_sqrt_requests();
    return 0;
}
