/*
 * Purpose: Calculates the integer square root of a non-negative integer using the binary search algorithm.
 * Topic: Algorithms, Binary Search, Integer Math
 */

#include <stdio.h>

int main() {
    int number;
    printf("Enter a non-negative integer to find its square root (0 to exit): ");
    while (scanf("%d", &number) == 1 && number >= 0) {
        if (number == 0) {
            printf("Exiting.\n");
            break;
        }

        int low = 0;
        int high = number;
        int result = 0;

        // Binary search to find integer square root
        while (low <= high) {
            int mid = low + (high - low) / 2; // Prevents overflow for large values
            
            // Check if mid*mid is the square root
            // Cast to long long to prevent overflow when mid*mid is large
            if ((long long)mid * mid == number) {
                result = mid;
                break;
            }
            
            // If mid*mid is less than number, mid could be answer
            // or we need to search in upper half
            if ((long long)mid * mid < number) {
                result = mid; // Store mid as potential answer
                low = mid + 1;
            }
            // If mid*mid is greater than number, search in lower half
            else {
                high = mid - 1;
            }
        }
        printf("Integer square root of %d is %d\n", number, result);
        printf("Enter a non-negative integer to find its square root (0 to exit): ");
    }
    return 0;
}
