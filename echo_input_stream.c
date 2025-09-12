/*
 * Purpose: Reads characters from standard input until EOF and echoes them to standard output.
 * Topic: Character Input/Output, Reading Input Streams, EOF Handling
 */

#include <stdio.h>
#include <stdlib.h>

void display_instructions(void) {
    printf("Enter text (press Ctrl+D on Unix/Linux or Ctrl+Z on Windows to signal EOF):\n");
}

void echo_stream(void) {
    int input_char;
    
    while ((input_char = getchar()) != EOF) {
        putchar((char)input_char);
    }
}

int check_stream_error(void) {
    if (ferror(stdin)) {
        perror("Error reading from standard input");
        return -1;
    }
    return 0;
}

int main(void) {
    display_instructions();
    echo_stream();
    check_stream_error();
    
    return 0;
}
