/*
 * Purpose: Counts the frequency of each lowercase letter in a given string.
 * Topic: Strings, Character Handling, Arrays, Loops, Frequency Counting
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    int num_test_cases; // Number of test cases
    int case_num;       // Current test case number

    // Get number of test cases
    scanf("%d", &num_test_cases);
    // Consume newline character left by scanf
    getchar();

    // Process each test case
    for (case_num = 1; case_num <= num_test_cases; case_num++) {
        char input_string[100];       // Input string buffer
        int frequency[26] = {0};      // Frequency array for 'a'-'z'
        int string_length;            // Length of input string
        int i;

        // Read input string with buffer overflow protection
        scanf("%99s", input_string);
        // Consume newline character left by scanf
        getchar();

        string_length = strlen(input_string);

        // Count frequency of each character
        for (i = 0; i < string_length; i++) {
            char current_char = tolower(input_string[i]); // Convert to lowercase

            // Check if character is a lowercase letter
            if (current_char >= 'a' && current_char <= 'z') {
                frequency[current_char - 'a']++; // Increment count
            }
        }

        // Print frequencies of letters that appeared
        printf("Case %d:\n", case_num);
        for (i = 0; i < 26; i++) {
            if (frequency[i] > 0) {
                printf("%c %d\n", (char)('a' + i), frequency[i]);
            }
        }
    }

    return 0;
}
