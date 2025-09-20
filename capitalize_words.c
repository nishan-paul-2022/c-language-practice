/*
 * Purpose: Reads a string and capitalizes the first letter of each word, converting other letters to lowercase.
 * Topic: Strings, Character Manipulation, Loops, Input/Output
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    char str[100];

    printf("Enter any string: ");
    if (fgets(str, sizeof(str), stdin) == NULL) {
        printf("Error reading input.\n");
        return 0;
    }

    int len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
        len--;
    }
    
    for (int i = 0; i < len; i++) {
        if (i == 0 || str[i - 1] == ' ') {
            if (str[i] >= 'a' && str[i] <= 'z') {
                str[i] = toupper(str[i]);
            }
        } else {
            if (str[i] >= 'A' && str[i] <= 'Z') {
                str[i] = tolower(str[i]);
            }
        }
    }

    printf("Modified string: %s\n", str);

    return 0;
}
