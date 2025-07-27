/*
 * Purpose: Solves a variant of the Josephus problem using modular arithmetic.
 * Topic: Loops, Modular Arithmetic, Problem Solving
 */

#include <stdio.h>

int main()
{
    int numberOfTestCases; // T in original
    int currentTestCase = 0;
    
    // Read the number of test cases
    printf("Enter the number of test cases: ");
    if (scanf("%d", &numberOfTestCases) != 1 || numberOfTestCases < 0)
    {
        printf("Invalid input for number of test cases.\n");
        return 1;
    }

    while (currentTestCase < numberOfTestCases)
    {
        int n; // n in original, represents the total number of items
        int resultPosition = 0; // y in original, represents the calculated position

        printf("Enter the value of n for test case %d: ", currentTestCase + 1);
        if (scanf("%d", &n) != 1 || n < 1)
        {
            printf("Invalid input for n. Skipping this test case.\n");
            // Clear input buffer in case of invalid input
            while (getchar() != '\n' && !feof(stdin) && !ferror(stdin));
            currentTestCase++;
            continue;
        }

        // The loop calculates a position based on the given formula
        // This pattern is typical for Josephus-like problems where items are removed
        // and the position of the last remaining item is sought.
        for (int x = 2; x <= n; x++)
        {
            resultPosition = (resultPosition + n + 1 - x) % x;
        }

        // The problem's output seems to be 1-indexed, so add 1 to the 0-indexed result.
        printf("Result for n = %d: %d\n", n, resultPosition + 1);
        currentTestCase++;
    }

    return 0;
}
