/*
 * Purpose: Counts the frequency of each lowercase letter in a given string.
 * Topic: Strings, Character Handling, Arrays, Loops, Frequency Counting
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    printf("Enter the number of test cases: ");
    int num_test_cases;
    if (scanf("%d", &num_test_cases) != 1) {
        printf("Error: Invalid input for number of test cases.\n");
        return 1;
    }
    getchar();

    for (int case_num = 1; case_num <= num_test_cases; case_num++) {
        int frequency[26] = {0};

        // Read input string with buffer overflow protection
        printf("Enter string %d (lowercase letters only): ", case_num);
        char input_string[100];
        if (scanf("%99s", input_string) != 1) {
            printf("Error: Invalid input for string.\n");
            continue;
        }
        getchar();

        // Count frequency of each character
        int string_length = strlen(input_string);
        for (int i = 0; i < string_length; i++) {
            char current_char = tolower(input_string[i]);
            if (current_char >= 'a' && current_char <= 'z') {
                frequency[current_char - 'a']++;
            }
        }

        // Print frequencies of letters that appeared
        printf("Case %d:\n", case_num);
        for (int i = 0; i < 26; i++) {
            if (frequency[i] > 0) {
                printf("%c %d\n", (char)('a' + i), frequency[i]);
            }
        }
    }

    return 0;
}
