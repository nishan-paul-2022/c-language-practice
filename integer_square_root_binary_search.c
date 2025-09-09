/*
 * Purpose: Demonstrates integer square root calculation using binary search.
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

        // Binary search to find the integer square root
        while (low <= high) {
            int mid = low + (high - low) / 2; // Avoids potential overflow for large low + high
            
            // Check if mid*mid is the square root
            // Using (long long) to prevent overflow when mid*mid is large
            if ((long long)mid * mid == number) {
                result = mid;
                break;
            }
            
            // If mid*mid is less than number, then mid could be the answer
            // or we need to search in the upper half.
            if ((long long)mid * mid < number) {
                result = mid; // Store mid as a potential answer
                low = mid + 1;
            } 
            // If mid*mid is greater than number, search in the lower half.
            else {
                high = mid - 1;
            }
        }
        printf("Integer square root of %d is %d\n", number, result);
        printf("Enter a non-negative integer to find its square root (0 to exit): ");
    }
    return 0;
}
