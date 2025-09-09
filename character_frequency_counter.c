// Purpose: Counts the frequency of each lowercase letter in a given string.
// Topic: Strings, Character Handling, Arrays, Loops, Frequency Counting

#include <stdio.h>
#include <string.h>
#include <ctype.h> // For tolower()

int main() {
    int num_test_cases; // Number of test cases
    int case_num;       // Current test case number

    // Read the number of test cases
    scanf("%d", &num_test_cases);
    // Consume the newline character left by scanf("%d")
    getchar();

    // Process each test case
    for (case_num = 1; case_num <= num_test_cases; case_num++) {
        char input_string[100];       // Buffer to store the input string
        int frequency[26] = {0};      // Array to store frequencies of 'a' through 'z'
        int string_length;            // Length of the input string
        int i;

        // Read the input string
        scanf("%99s", input_string); // %99s to prevent buffer overflow
        // Consume the newline character left by scanf("%s")
        getchar();

        string_length = strlen(input_string);

        // Count the frequency of each character
        for (i = 0; i < string_length; i++) {
            char current_char = tolower(input_string[i]); // Convert to lowercase

            // Check if the character is a lowercase letter
            if (current_char >= 'a' && current_char <= 'z') {
                frequency[current_char - 'a']++; // Increment the count for this letter
            }
        }

        // Print the frequencies of letters that appeared in the string
        printf("Case %d:\n", case_num);
        for (i = 0; i < 26; i++) {
            if (frequency[i] > 0) {
                printf("%c %d\n", (char)('a' + i), frequency[i]);
            }
        }
    }

    return 0;
}
