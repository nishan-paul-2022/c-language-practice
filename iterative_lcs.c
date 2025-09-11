/*
 * Purpose: Calculates the length of the Longest Common Subsequence (LCS) of two strings using an iterative dynamic programming approach.
 * Topic: String Manipulation, Dynamic Programming (Iterative LCS), 2D Arrays
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Helper function to find maximum of two integers
int max_int(int a, int b) {
    return (a > b) ? a : b;
}

// Function to calculate LCS length and store directions for reconstruction
// a: first string, b: second string
// r: length of string a, c: length of string b
// T: 2D array to store LCS lengths (T[i][j] stores LCS length of a[0..i-1] and b[0..j-1])
// directions: 2D array to store directions ('m' for match, 'u' for up, 'f' for forward)
void calculate_lcs_and_directions(const char a[], const char b[], int r, int c, int T[][c + 1], char directions[][c]) {
    int i, j;

    // Initialize first row and first column of DP table to 0
    // Represents LCS length when one string is empty
    for (i = 0; i <= r; i++) {
        T[i][0] = 0;
    }
    for (j = 0; j <= c; j++) {
        T[0][j] = 0;
    }

    // Fill DP table and directions table
    for (i = 1; i <= r; i++) {
        for (j = 1; j <= c; j++) {
            // If current characters match
            if (a[i - 1] == b[j - 1]) {
                T[i][j] = 1 + T[i - 1][j - 1]; // LCS length increases by 1
                directions[i - 1][j - 1] = 'm'; // Mark as match
            }
            // If current characters do not match
            else {
                // Take maximum LCS length from either excluding last char of 'a' (up)
                // or excluding last char of 'b' (forward)
                if (T[i - 1][j] >= T[i][j - 1]) {
                    T[i][j] = T[i - 1][j]; // Take value from above
                    directions[i - 1][j - 1] = 'u'; // Mark direction as 'up'
                } else {
                    T[i][j] = T[i][j - 1]; // Take value from left
                    directions[i - 1][j - 1] = 'f'; // Mark direction as 'forward'
                }
            }
        }
    }
}

// Function to reconstruct and print LCS string using directions table
// a: first string
// r: current row index in directions table (corresponds to string 'a' length)
// c: current column index in directions table (corresponds to string 'b' length)
void reconstruct_lcs_string(const char a[], int r, int c, const char directions[][c]) {
    // Base case: If we've reached beginning of either string, stop
    if (r == 0 || c == 0) {
        return;
    }

    // If direction indicates a match ('m')
    if (directions[r - 1][c - 1] == 'm') {
        // Recursively call for previous characters and then print current matching character
        reconstruct_lcs_string(a, r - 1, c - 1, directions);
        printf("%c", a[r - 1]); // Print the character from string 'a' (or 'b', they are the same)
    }
    // If direction indicates 'up' (character from 'a' was not part of LCS at this step)
    else if (directions[r - 1][c - 1] == 'u') {
        // Move up in table (effectively skipping character from string 'a')
        reconstruct_lcs_string(a, r - 1, c, directions);
    }
    // If direction indicates 'forward' (character from 'b' was not part of LCS at this step)
    else if (directions[r - 1][c - 1] == 'f') {
        // Move left in table (effectively skipping character from string 'b')
        reconstruct_lcs_string(a, r, c - 1, directions);
    }
}

int main(void) {
    int num_test_cases;
    int test_case_num = 1;
    char str1[1000]; // Buffer for first string
    char str2[1000]; // Buffer for second string
    int len1, len2;
    int lcs_length;

    printf("Enter the number of test cases:\n");
    // Read number of test cases and validate input
    if (scanf("%d", &num_test_cases) != 1) {
        fprintf(stderr, "Error: Invalid input for number of test cases.\n");
        while (getchar() != '\n'); // Clear buffer
        return EXIT_FAILURE;
    }
    // Consume newline character after reading number of test cases
    getchar();

    // Process each test case
    while (test_case_num <= num_test_cases) {
        printf("\n--- Test Case %d ---\n", test_case_num);

        printf("Enter the first string:\n");
        // Read first string safely
        if (scanf("%999[^\n]", str1) != 1) {
            fprintf(stderr, "Error reading the first string for test case %d.\n", test_case_num);
            while (getchar() != '\n');
            return EXIT_FAILURE;
        }
        getchar(); // Consume newline

        printf("Enter the second string:\n");
        // Read second string safely
        if (scanf("%999[^\n]", str2) != 1) {
            fprintf(stderr, "Error reading the second string for test case %d.\n", test_case_num);
            while (getchar() != '\n');
            return EXIT_FAILURE;
        }

        // Get lengths of strings
        len1 = strlen(str1);
        len2 = strlen(str2);

        // Declare DP table for LCS lengths and directions table
        // Using Variable Length Arrays (VLAs) for dynamic sizing based on input lengths
        int T[len1 + 1][len2 + 1];
        char directions[len1][len2]; // Directions table size matches string lengths

        // Calculate LCS length and fill directions table
        calculate_lcs_and_directions(str1, str2, len1, len2, T, directions);

        // Get final LCS length from DP table
        lcs_length = T[len1][len2];

        // Print results for current test case
        printf("Case %d: LENGTH %d & STRING \" ", test_case_num, lcs_length);
        // Reconstruct and print LCS string
        reconstruct_lcs_string(str1, len1, len2, directions);
        printf(" \"\n");

        test_case_num++; // Move to the next test case
    }

    return 0;
}
