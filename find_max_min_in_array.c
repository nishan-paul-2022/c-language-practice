/*
 * Purpose: Finds the maximum and minimum values in an array of 5 integers for multiple test cases.
 * Topic: Arrays, Loops, Max/Min Finding
 */

#include <stdio.h>

void find_max_min(int arr[], int size, int *max, int *min) {
    *max = arr[0];
    *min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > *max) {
            *max = arr[i];
        }
        if (arr[i] < *min) {
            *min = arr[i];
        }
    }
}

void run_test_cases() {
    int num_test_cases;
    printf("Enter the number of test cases: ");
    scanf("%d", &num_test_cases);

    while (num_test_cases--) {
        int numbers[5];
        printf("Enter 5 integers: ");
        for (int i = 0; i < 5; i++) {
            scanf("%d", &numbers[i]);
        }

        int max_val, min_val;
        find_max_min(numbers, 5, &max_val, &min_val);

        printf("Maximum: %d, Minimum: %d\n", max_val, min_val);
    }
}

int main(void) {
    run_test_cases();
    return 0;
}
