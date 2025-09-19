/*
 * Purpose: Reads an integer and a string, counts exclamation marks in the string,
 *          and performs a custom product calculation based on the integer and the count.
 * Topic: Input Handling (Mixed Types), String Iteration, Custom Calculation
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void get_string(char* str, int size) {
    printf("Enter a string: ");

    if (fgets(str, size, stdin) == NULL) {
        printf("Invalid string input or end of file reached.\n");
        exit(1);
    }
    
    str[strcspn(str, "\n")] = '\0';
}

int main(void) {
    char str[100];
    get_string(str, sizeof(str));

    char ch;
    printf("Enter the desired character: ");
    scanf("%c", &ch);
    char ch_lower = tolower(ch);

    int count = 0;
    for (int char_index = 0; str[char_index] != '\0'; char_index++) {
        if (tolower(str[char_index]) == ch_lower) {
            count++;
        }
    }

    printf("%c in '%s': %d\n", ch, str, count);

    return 0;
}
