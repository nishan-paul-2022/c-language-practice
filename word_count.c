/*
 * Purpose: Counts the number of words in multiple input lines.
 * Topic: Strings, Tokenization, Loops, Functions
 */

#include <stdio.h>
#include <string.h>

void read_line(char *buffer, int size) {
    if (fgets(buffer, size, stdin) != NULL) {
        size_t len = strlen(buffer);
        
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
        }
    }
}

int count_words(const char *line) {
    int count = 0;
    char copy[1000];
    char *token;

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

    printf("Enter number of test cases: ");

    scanf("%d", &num_test_cases);

    getchar();

    for (int i = 1; i <= num_test_cases; i++) {
        printf("\nTest case %d (enter a line of text): ", i);

        read_line(input_line, sizeof(input_line));

        int word_count = count_words(input_line);
        printf("Word count for test case %d: %d\n", i, word_count);
    }

    return 0;
}
