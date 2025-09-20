/*
 * Purpose: Reads a single character from standard input and echoes it back to standard output.
 * Topic: Character Input/Output, getchar(), putchar()
 */

#include <stdio.h>
#include <stdlib.h>

int read_character() {
    printf("Enter a single character: ");
    return getchar();
}

int handle_eof_error(int input_char) {
    if (input_char == EOF) {
        if (ferror(stdin)) {
            perror("Error reading character");
            return -1;
        } else {
            printf("\nEnd of input reached.\n");
            return -1;
        }
    }
    return 0;
}

void echo_character(int input_char) {
    printf("Entered character: ");
    putchar((char)input_char);
    putchar('\n');
}

int main(void) {
    int input_char = read_character();
    
    if (handle_eof_error(input_char) == 0) {
        echo_character(input_char);
    }
    
    return 0;
}
