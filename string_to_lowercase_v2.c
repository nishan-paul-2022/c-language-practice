/*
 * Purpose: Reads a line of text and prints only the lowercase alphabet characters from it.
 * Topic: String Manipulation, Loops, Character Handling (ctype.h)
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int get_input_string(char *input_string, int buffer_size) {
    printf("Enter a string (e.g., 'Hello World 123!'): ");
    
    if (fgets(input_string, buffer_size, stdin) == NULL) {
        printf("Error reading input.\n");
        return -1;
    }
    
    input_string[strcspn(input_string, "\n")] = '\0'; 
    
    return 0;
}

void extract_and_print_lowercase(const char *input_string) {
    printf("Result: ");
    
    for (int i = 0; input_string[i] != '\0'; i++) {
        putchar(tolower(input_string[i]));
    }
    printf("\n");
}

int main(void) {
    char input_string[100];
    
    if (get_input_string(input_string, sizeof(input_string)) == 0) {
        extract_and_print_lowercase(input_string);
    }
    
    return 0;
}
