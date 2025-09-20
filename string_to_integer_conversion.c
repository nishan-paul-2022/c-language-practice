/*
 * Purpose: Converts a string of digits into its integer representation.
 * Topic: String to Integer Conversion, Basic Input/Output
 */

#include <stdio.h>
#include <string.h>

void consume_newline() {
    while (getchar() != '\n'); 
}

int string_to_integer(const char str[], int test_case) {
    int value = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            value = value * 10 + (str[i] - '0');
        } else {
            fprintf(stderr, "Non-digit character '%c' in test case %d skipped.\n", str[i], test_case);
        }
    }
    return value;
}

int read_line(char buffer[], int size) {
    if (fgets(buffer, size, stdin) != NULL) {
        buffer[strcspn(buffer, "\n")] = '\0';
        return 1;
    }
    return 0;
}

int main(void) {
    int num_test_cases;
    char input_string[100];

    if (scanf("%d", &num_test_cases) == -1) {
        fprintf(stderr, "Error reading number of test cases.\n");
        return 0;
    }
    
    consume_newline();

    for (int t = 1; t <= num_test_cases; t++) {
        if (!read_line(input_string, sizeof(input_string))) {
            fprintf(stderr, "Error reading input string for test case %d.\n", t);
            continue;
        }

        int result = string_to_integer(input_string, t);
        printf("%d\n", result);
    }

    return 0;
}
