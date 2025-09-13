/*
 * Purpose: Calculates the length of the Longest Common Subsequence (LCS) of two strings using an iterative dynamic programming approach.
 * Topic: String Manipulation, Dynamic Programming (Iterative LCS), 2D Arrays
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int max_int(int a, int b) {
    return (a > b) ? a : b;
}

void calculate_lcs_and_directions(const char a[], const char b[], int r, int c, int T[][c + 1], char directions[][c]) {
    int i, j;

    for (i = 0; i <= r; i++) {
        T[i][0] = 0;
    }
    for (j = 0; j <= c; j++) {
        T[0][j] = 0;
    }

    for (i = 1; i <= r; i++) {
        for (j = 1; j <= c; j++) {
            if (a[i - 1] == b[j - 1]) {
                T[i][j] = 1 + T[i - 1][j - 1];
                directions[i - 1][j - 1] = 'm';
            } else {
                if (T[i - 1][j] >= T[i][j - 1]) {
                    T[i][j] = T[i - 1][j];
                    directions[i - 1][j - 1] = 'u';
                } else {
                    T[i][j] = T[i][j - 1];
                    directions[i - 1][j - 1] = 'f';
                }
            }
        }
    }
}

void reconstruct_lcs_string(const char a[], int r, int c, const char directions[][c]) {
    if (r == 0 || c == 0) {
        return;
    }

    if (directions[r - 1][c - 1] == 'm') {
        reconstruct_lcs_string(a, r - 1, c - 1, directions);
        printf("%c", a[r - 1]);
    } else if (directions[r - 1][c - 1] == 'u') {
        reconstruct_lcs_string(a, r - 1, c, directions);
    } else if (directions[r - 1][c - 1] == 'f') {
        reconstruct_lcs_string(a, r, c - 1, directions);
    }
}

int get_strings(char str1[], char str2[], int case_num) {
    printf("Enter first string:\n");
    if (scanf("%999[^\n]", str1) != 1) {
        fprintf(stderr, "Error reading first string for test case %d.\n", case_num);
        while (getchar() != '\n');
        return -1;
    }
    getchar();

    printf("Enter second string:\n");
    if (scanf("%999[^\n]", str2) != 1) {
        fprintf(stderr, "Error reading second string for test case %d.\n", case_num);
        while (getchar() != '\n');
        return -1;
    }
    
    return 0;
}

void process_lcs(const char str1[], const char str2[], int case_num) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    int T[len1 + 1][len2 + 1];
    char directions[len1][len2];

    calculate_lcs_and_directions(str1, str2, len1, len2, T, directions);

    int lcs_length = T[len1][len2];

    printf("Case %d: LENGTH %d & STRING \" ", case_num, lcs_length);
    reconstruct_lcs_string(str1, len1, len2, directions);
    printf(" \"\n");
}

int main(void) {
    int num_test_cases;
    int test_case_num = 1;
    char str1[1000];
    char str2[1000];

    printf("Enter number of test cases:\n");
    if (scanf("%d", &num_test_cases) != 1) {
        fprintf(stderr, "Error: Invalid input for number of test cases.\n");
        while (getchar() != '\n');
        return 0;
    }
    getchar();

    while (test_case_num <= num_test_cases) {
        printf("\n--- Test Case %d ---\n", test_case_num);

        if (get_strings(str1, str2, test_case_num) == 0) {
            process_lcs(str1, str2, test_case_num);
        } else {
            return 0;
        }

        test_case_num++;
    }

    return 0;
}
