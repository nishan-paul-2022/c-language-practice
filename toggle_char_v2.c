/*
 * Purpose: Demonstrates reading a character, toggling its case (upper to lower, lower to upper) using built-in functions.
 * Topic: Characters, ASCII Values, Conditional Statements, Loops, Input Handling
 */

#include <stdio.h>
#include <ctype.h>

char toggle_case(char ch) {
    if (isupper(ch)) {
        return tolower(ch);
    } else {
        return toupper(ch);
    }
    
    return ch;
}

int main(void) {
    char ch;

    printf("Enter alpahabet to toggle their case (Ctrl+D to quit).\n");

    while (scanf(" %c", &ch) != -1) {
        int is_letter = (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z');

        if (is_letter) {
            char toggled = toggle_case(ch);
            printf("Toggled case: %c\n", toggled);
        }
        else {
            printf("Character is not a letter, printing as is: %c\n", ch);
        }

        printf("\n");
    }

    return 0;
}
