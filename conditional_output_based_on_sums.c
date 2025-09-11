/*
 * Purpose: Reads sets of four integers, calculates two sums based on alternating signs, and prints "BANGLADESH" or "MISS" based on whether both sums are positive.
 * Topic: Input/Output, Loops, Conditional Statements, Basic Arithmetic
 */

#include <stdio.h>

int main(void) {
    int number_of_test_cases;
    int current_test_case = 0;

    printf("Enter the number of test cases: ");
    if (scanf("%d", &number_of_test_cases) != 1 || number_of_test_cases < 0) {
        printf("Invalid input for number of test cases.\n");
        return 0;
    }

    while (current_test_case < number_of_test_cases) {
        int k1, k2, k3, k4;
        int m1, m2, m3, m4;
        int sum1, sum2;

        printf("\n--- Test Case %d ---\n", current_test_case + 1);
        printf("Enter four integers for the first set (k1 k2 k3 k4): ");
        if (scanf("%d %d %d %d", &k1, &k2, &k3, &k4) != 4) {
            printf("Invalid input for first set. Skipping this test case.\n");
            while (getchar() != '\n' && !feof(stdin) && !ferror(stdin)); // Clear input buffer
            current_test_case++;
            continue;
        }
        sum1 = k1 - k2 + k3 - k4;

        printf("Enter four integers for the second set (K1 K2 K3 K4): ");
        if (scanf("%d %d %d %d", &m1, &m2, &m3, &m4) != 4) {
            printf("Invalid input for second set. Skipping this test case.\n");
            while (getchar() != '\n' && !feof(stdin) && !ferror(stdin)); // Clear input buffer
            current_test_case++;
            continue;
        }
        sum2 = m1 - m2 + m3 - m4;

        if (sum1 > 0 && sum2 > 0) {
            printf("HIT\n");
        } else {
            printf("MISS\n");
        }
        current_test_case++;
    }

    return 0;
}