/*
 * Purpose: Demonstrates reading a string and printing words separated by spaces.
 * Topic: String manipulation, input/output, loops.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_SIZE 256

void read_input(char str[BUFFER_SIZE]) {
    printf("Enter a string: ");
    if (fgets(str, BUFFER_SIZE, stdin) == NULL) {
        printf("Error reading input.\n");
        exit(0);
    }
    str[strcspn(str, "\n")] = 0; // Remove trailing newline
}

void print_words(const char str[BUFFER_SIZE]) {
    int i = 0, j;

    printf("Words in the string:\n");
    while (str[i] != '\0') {
        while (str[i] == ' ') i++;
        if (str[i] == '\0') break;

        // Find end of word
        j = i;
        while (str[j] != ' ' && str[j] != '\0') {
            j++;
        }

        for (int k = i; k < j; k++) {
            printf("%c", str[k]);
        }
        printf("\n");

        i = j; // Move to next word
    }
}

int main(void) {
    char input_string[BUFFER_SIZE];

    read_input(input_string);
    print_words(input_string);

    return 0;
}
