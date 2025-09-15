/*
 * Purpose: Counts the number of words in multiple input lines.
 * Topic: Strings, Tokenization, Loops, Functions
 */

#include <stdio.h>
#include <string.h>

// Function to safely read a line of input
void read_line(char *buffer, int size) {
    if (fgets(buffer, size, stdin) != NULL) {
        // Remove trailing newline if present
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
        }
    }
}

// Function to count words in a given string
int count_words(const char *line) {
    int count = 0;
    char copy[1000];
    char *token;

    // Make a copy since strtok modifies the string
    strncpy(copy, line, sizeof(copy));
    copy[sizeof(copy) - 1] = '\0';

    token = strtok(copy, " ");
    while (token != NULL) {
        count++;
        token = strtok(NULL, " ");
    }

    return count;
}

int main(void) {
    int num_test_cases;
    char input_line[1000];

    // Ask for number of test cases
    printf("Enter number of test cases: ");
    scanf("%d", &num_test_cases);
    getchar(); // consume leftover newline

    // Process each test case
    for (int i = 1; i <= num_test_cases; i++) {
        printf("\nTest case %d - Enter a line of text:\n", i);
        read_line(input_line, sizeof(input_line));

        int word_count = count_words(input_line);
        printf("Word count for test case %d: %d\n", i, word_count);
    }

    return 0;
}
