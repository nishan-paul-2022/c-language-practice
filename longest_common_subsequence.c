/*
 * Purpose: Calculates length of Longest Common Subsequence (LCS) of two strings.
 * Topic: String Manipulation, Recursion, Dynamic Programming (LCS Algorithm)
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 1000
int max_int(int a, int b) {
    return (a > b) ? a : b;
}

int calculate_lcs_length(const char a[], const char b[], int m, int n) {
    if (m == 0 || n == 0) {
        return 0;
    }
    else if (a[m - 1] == b[n - 1]) {
        int ans = 1 + calculate_lcs_length(a, b, m - 1, n - 1);
        return ans;
    }
    else {
        int len1 = calculate_lcs_length(a, b, m - 1, n);
        int len2 = calculate_lcs_length(a, b, m, n - 1);
        int ans = max_int(len1, len2);
        return ans;
    }
}

int read_string(char str[], const char prompt[]) {
    printf("%s", prompt);

    if (scanf("%1000[^\n]", str) != 1) {
        fprintf(stderr, "Error reading string.\n");
        while (getchar() != '\n');
        return -1;
    }
    
    getchar();

    return 0;
}

int main(void) {
    char str1[MAX_LENGTH + 1];
    if (read_string(str1, "Enter the first string: ") == -1) {
        return 0;
    }

    char str2[MAX_LENGTH + 1];
    if (read_string(str2, "Enter the second string: ") == -1) {
        return 0;
    }

    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int lcs_length = calculate_lcs_length(str1, str2, len1, len2);

    printf("Length of the longest common subsequence: %d\n", lcs_length);

    return 0;
}
