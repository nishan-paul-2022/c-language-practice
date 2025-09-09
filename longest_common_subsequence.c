/*
 * Purpose: Calculates the length of the Longest Common Subsequence (LCS) of two strings.
 * Topic: String Manipulation, Recursion, Dynamic Programming (LCS Algorithm)
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Helper function to find the maximum of two integers.
// Renamed from 'cmp' to 'max_int' for clarity.
int max_int(int a, int b) {
    return (a > b) ? a : b;
}

// Recursive function to calculate the length of the Longest Common Subsequence (LCS).
// This is a classic dynamic programming problem.
// a: first string, b: second string
// m: current length of string a being considered (from the end)
// n: current length of string b being considered (from the end)
int calculate_lcs_length(const char a[], const char b[], int m, int n) {
    // Base case: If either string is empty, the LCS length is 0.
    if (m == 0 || n == 0) {
        return 0;
    }
    // If the last characters of both strings match
    else if (a[m - 1] == b[n - 1]) {
        // Include this character in the LCS and recurse on the remaining parts of the strings.
        return 1 + calculate_lcs_length(a, b, m - 1, n - 1);
    }
    // If the last characters do not match
    else {
        // Consider two possibilities:
        // 1. Exclude the last character of string 'a' and find LCS of a[0..m-2] and b[0..n-1].
        // 2. Exclude the last character of string 'b' and find LCS of a[0..m-1] and b[0..n-2].
        // Return the maximum of these two possibilities.
        return max_int(calculate_lcs_length(a, b, m - 1, n), calculate_lcs_length(a, b, m, n - 1));
    }
}

int main() {
    char str1[1000]; // Buffer for the first string
    char str2[1000]; // Buffer for the second string
    int len1, len2;
    int lcs_length;

    printf("Enter the first string:\n");
    // Read the first string, ensuring not to exceed buffer size and handling potential errors.
    // %[^\n] reads characters until a newline is encountered.
    // %999 limits the read to 999 characters to leave space for the null terminator.
    if (scanf("%999[^\n]", str1) != 1) {
        fprintf(stderr, "Error reading the first string.\n");
        // Clear the input buffer
        while (getchar() != '\n');
        return EXIT_FAILURE;
    }
    // Consume the newline character left by scanf
    getchar();

    printf("Enter the second string:\n");
    // Read the second string
    if (scanf("%999[^\n]", str2) != 1) {
        fprintf(stderr, "Error reading the second string.\n");
        // Clear the input buffer
        while (getchar() != '\n');
        return EXIT_FAILURE;
    }

    // Get the lengths of the strings
    len1 = strlen(str1);
    len2 = strlen(str2);

    // Calculate the length of the Longest Common Subsequence
    lcs_length = calculate_lcs_length(str1, str2, len1, len2);

    // Print the result
    printf("Length of the Longest Common Subsequence: %d\n", lcs_length);

    return 0;
}
