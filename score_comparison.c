/*
 * Purpose: Compares two sets of scores (or values) based on specific sum conditions.
 * Topic: Basic Input/Output, Loops, Conditional Logic
 */

#include <stdio.h>

int main(void) {
    int num_test_cases; // Number of test cases

    // Read the number of test cases
    if (scanf("%d", &num_test_cases) != 1 || num_test_cases <= 0) {
        printf("Invalid input for number of test cases.\n");
        return 0;
    }

    // Process each test case
    for (int i = 0; i < num_test_cases; i++) {
        int t1p1, t1p2, t1p3, t1p4;
        int t2p1, t2p2, t2p3, t2p4;

        // Read scores for both teams
        if (scanf("%d %d %d %d", &t1p1, &t1p2, &t1p3, &t1p4) != 4 ||
            scanf("%d %d %d %d", &t2p1, &t2p2, &t2p3, &t2p4) != 4) {
            printf("Invalid input for team scores.\n");
            return 0;
        }

        // Check condition and print result
        if ((t1p1 + t1p2 > t1p3 + t1p4) && (t2p1 + t2p2 > t2p3 + t2p4)) {
            printf("Banglawash\n");
        } else {
            printf("Miss\n");
        }
    }

    return 0;
}
