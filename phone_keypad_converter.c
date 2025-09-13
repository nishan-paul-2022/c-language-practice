/*
 * Purpose: Converts alphabetic characters in a string to their corresponding digits on a phone keypad.
 * Topic: Strings, Character Manipulation, Conditional Statements (if-else if), Loops, Input/Output
 */

#include <stdio.h>
#include <string.h>

void print_prompt() {
    printf("Enter an alphanumeric string (max 30 chars, containing A-Z).\n");
}

int read_input(char *buffer) {
    return scanf("%30[A-Z0-9- ]s", buffer) == 1;
}

void consume_line() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void convert_to_digits(char *str) {
    for (int i = 0; str[i]; i++) {
        char ch = str[i];
        if (ch >= 'A' && ch <= 'C') {
            str[i] = '2';
        } else if (ch >= 'D' && ch <= 'F') {
            str[i] = '3';
        } else if (ch >= 'G' && ch <= 'I') {
            str[i] = '4';
        } else if (ch >= 'J' && ch <= 'L') {
            str[i] = '5';
        } else if (ch >= 'M' && ch <= 'O') {
            str[i] = '6';
        } else if (ch >= 'P' && ch <= 'S') {
            str[i] = '7';
        } else if (ch >= 'T' && ch <= 'V') {
            str[i] = '8';
        } else if (ch >= 'W' && ch <= 'Z') {
            str[i] = '9';
        }
    }
}

void print_output(const char *str) {
    printf("Converted: %s\n\n", str);
}

int main(void) {
    char input[31];
    
    print_prompt();
    while (read_input(input)) {
        consume_line();
        convert_to_digits(input);
        print_output(input);
        print_prompt();
    }
    
    printf("\nExiting program.\n");
    return 0;
}
