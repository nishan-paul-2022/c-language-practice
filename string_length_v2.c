/*
 * Purpose: Reads lines from standard input and prints their lengths.
 * Topic: Strings, Input/Output, Length Calculation
 */

#include <stdio.h>
#include <string.h>

#define MAX_INPUT 256

void remove_trailing_newline(char *str) {
    str[strcspn(str, "\n")] = '\0';
}

int main(void) {
    int valid = 0;
    char buffer[MAX_INPUT];

    while (valid == 0) {
        printf("Enter a string (max %d characters): ", MAX_INPUT - 1);

        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            remove_trailing_newline(buffer);
            int length = strlen(buffer);
            printf("Length: %d\n", length);
        } else {
            valid = 1;
        }
    }

    return 0;
}
