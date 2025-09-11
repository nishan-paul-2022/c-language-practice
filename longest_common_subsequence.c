/*
 * Purpose: Calculates length of Longest Common Subsequence (LCS) of two strings.
 * Topic: String Manipulation, Recursion, Dynamic Programming (LCS Algorithm)
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Helper function to find maximum of two integers
// Renamed from 'cmp' to 'max_int' for clarity
int max_int(int a, int b) {
    return (a > b) ? a : b;
}

// Recursive function to calculate length of Longest Common Subsequence (LCS)
// This is classic dynamic programming problem
// a: first string, b: second string
// m: current length of string a being considered (from the end)
// n: current length of string b being considered (from the end)
int calculate_lcs_length(const char a[], const char b[], int m, int n) {
    // Base case: If either string is empty, LCS length is 0
    if (m == 0 || n == 0) {
        return 0;
    }
    // If last characters of both strings match
    else if (a[m - 1] == b[n - 1]) {
        // Include this character in LCS and recurse on remaining parts of strings
        return 1 + calculate_lcs_length(a, b, m - 1, n - 1);
    }
    // If last characters do not match
    else {
        // Consider two possibilities:
        // 1. Exclude last character of string 'a' and find LCS of a[0..m-2] and b[0..n-1]
        // 2. Exclude last character of string 'b' and find LCS of a[0..m-1] and b[0..n-2]
        // Return maximum of these two possibilities
        return max_int(calculate_lcs_length(a, b, m - 1, n), calculate_lcs_length(a, b, m, n - 1));
    }
}

int main(void) {
    char str1[1000]; // Buffer for first string
    char str2[1000]; // Buffer for second string
    int len1, len2;
    int lcs_length;

    printf("Enter the first string:\n");
    // Read first string, ensuring not to exceed buffer size and handling potential errors
    // %[^\n] reads characters until newline is encountered
    // %999 limits read to 999 characters to leave space for null terminator
    if (scanf("%999[^\n]", str1) != 1) {
        fprintf(stderr, "Error reading the first string.\n");
        // Clear input buffer
        while (getchar() != '\n');
        return EXIT_FAILURE;
    }
    // Consume newline character left by scanf
    getchar();

    printf("Enter the second string:\n");
    // Read second string
    if (scanf("%999[^\n]", str2) != 1) {
        fprintf(stderr, "Error reading the second string.\n");
        // Clear input buffer
        while (getchar() != '\n');
        return EXIT_FAILURE;
    }

    // Get lengths of strings
    len1 = strlen(str1);
    len2 = strlen(str2);

    // Calculate length of Longest Common Subsequence
    lcs_length = calculate_lcs_length(str1, str2, len1, len2);

    // Print result
    printf("Length of the Longest Common Subsequence: %d\n", lcs_length);

    return 0;
}
