/*
 * Purpose: Compares two sets of scores (or values) based on specific sum conditions.
 * Topic: Basic Input/Output, Loops, Conditional Logic
 */

#include <stdio.h>

int main(void) {
    int num_test_cases;

    printf("Enter the number of test cases: ");

    if (scanf("%d", &num_test_cases) != 1 || num_test_cases <= 0) {
        printf("Invalid input for number of test cases.\n");
        return 0;
    }

    for (int i = 0; i < num_test_cases; i++) {
        int t1p1, t1p2, t1p3, t1p4;
        int t2p1, t2p2, t2p3, t2p4;
        
        printf("\nEnter 4 scores for Team 1 (test case %d): ", i + 1);
        if (scanf("%d %d %d %d", &t1p1, &t1p2, &t1p3, &t1p4) != 4) {
            printf("Invalid input for Team 1 scores.\n");
            return 0;
        }
        
        printf("Enter 4 scores for Team 2 (test case %d): ", i + 1);
        if (scanf("%d %d %d %d", &t2p1, &t2p2, &t2p3, &t2p4) != 4) {
            printf("Invalid input for Team 2 scores.\n");
            return 0;
        }
        
        if ((t1p1 + t1p2 > t1p3 + t1p4) && (t2p1 + t2p2 > t2p3 + t2p4)) {
            printf("Result: Banglawash\n");
        } else {
            printf("Result: Miss\n");
        }
    }

    return 0;
}
