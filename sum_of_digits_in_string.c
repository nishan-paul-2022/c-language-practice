/*
 * Purpose: Reads a string and calculates the sum of all digit characters within it.
 * Topic: Strings, Character Manipulation, Loops, Input/Output
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 100

void remove_newline(char *str) {
    int len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

int calculate_digit_sum(const char *str) {
    int sum = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (isdigit((unsigned char)str[i])) {
            sum += str[i] - '0';
        }
    }
    return sum;
}

int main(void) {
    char input_string[MAX_LEN];

    printf("Enter a numeric string (digits will be summed): ");

    if (fgets(input_string, sizeof(input_string), stdin) == NULL) {
        printf("Error reading input.\n");
        return 1;
    }

    remove_newline(input_string);

    int digit_sum = calculate_digit_sum(input_string);

    printf("Sum of digits in numeric string: %d\n", digit_sum);

    return 0;
}
