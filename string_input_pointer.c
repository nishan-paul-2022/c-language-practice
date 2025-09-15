/*
 * Purpose: Reads a string using fgets and prints it via a pointer.
 * Topic: Pointers, Strings, I/O
 */

#include <stdio.h>
#include <string.h>

int main(void) {
    char input_buf[100];
    char *str_ptr = input_buf;

    printf("Enter a string: ");
    if (fgets(input_buf, sizeof(input_buf), stdin) != NULL) {
        input_buf[strcspn(input_buf, "\n")] = '\0';
        if (*str_ptr != '\0') {
            printf("You entered: %s\n", str_ptr);
        } else {
            printf("You entered an empty string.\n");
        }
    } else {
        printf("Error reading input.\n");
    }

    return 0;
}
