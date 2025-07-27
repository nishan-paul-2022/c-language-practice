/*
 * Purpose: Reads sets of four integers, calculates two sums based on alternating signs, and prints "BANGLADESH" or "MISS" based on whether both sums are positive.
 * Topic: Input/Output, Loops, Conditional Statements, Basic Arithmetic
 */

#include <stdio.h>

int main()
{
    int numberOfTestCases; // n in original
    int currentTestCase = 0; // x in original

    printf("Enter the number of test cases: ");
    if (scanf("%d", &numberOfTestCases) != 1 || numberOfTestCases < 0)
    {
        printf("Invalid input for number of test cases.\n");
        return 1;
    }

    while (currentTestCase < numberOfTestCases)
    {
        int k1, k2, k3, k4;
        int K1, K2, K3, K4;
        int sum1, sum2; // y1, y2 in original

        printf("\n--- Test Case %d ---\n", currentTestCase + 1);
        printf("Enter four integers for the first set (k1 k2 k3 k4): ");
        if (scanf("%d %d %d %d", &k1, &k2, &k3, &k4) != 4)
        {
            printf("Invalid input for first set. Skipping this test case.\n");
            // Clear input buffer
            while (getchar() != '\n' && !feof(stdin) && !ferror(stdin));
            currentTestCase++;
            continue;
        }
        sum1 = k1 - k2 + k3 - k4;

        printf("Enter four integers for the second set (K1 K2 K3 K4): ");
        if (scanf("%d %d %d %d", &K1, &K2, &K3, &K4) != 4)
        {
            printf("Invalid input for second set. Skipping this test case.\n");
            // Clear input buffer
            while (getchar() != '\n' && !feof(stdin) && !ferror(stdin));
            currentTestCase++;
            continue;
        }
        sum2 = K1 - K2 + K3 - K4;

        if (sum1 > 0 && sum2 > 0)
        {
            printf("BANGLADESH\n");
        }
        else
        {
            printf("MISS\n");
        }
        currentTestCase++;
    }

    return 0;
}
