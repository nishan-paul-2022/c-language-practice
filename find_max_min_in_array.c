/*
 * Purpose: Finds the maximum and minimum values in an array of 5 integers for multiple test cases.
 * Topic: Arrays, Loops, Max/Min Finding
 */

#include <stdio.h>

// Function to find the maximum and minimum values in an array
void findMaxMin(int arr[], int size, int *max, int *min) {
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

// Function to run the test cases
void runTestCases() {
    int num_test_cases;
    printf("Enter the number of test cases: ");
    scanf("%d", &num_test_cases); // Read the number of test cases

    while (num_test_cases--) {
        int numbers[5];
        printf("Enter 5 integers separated by spaces: ");
        for (int i = 0; i < 5; i++) {
            scanf("%d", &numbers[i]); // Read each integer
        }

        int max_val, min_val;
        findMaxMin(numbers, 5, &max_val, &min_val);

        printf("Maximum: %d, Minimum: %d\n", max_val, min_val);
    }
}

int main(void) {
    runTestCases();
    return 0;
}
