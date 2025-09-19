/*
 * Purpose: Demonstrates different ways to print a string to the console.
 * Topic: Basic I/O, Strings
 */

#include <stdio.h>

int main(void) {
    char str[] = "A promise was once made, that promise will be kept.\n";
    
    printf("1. Using printf: %s", str);
    
    printf("2. Using puts: ");
    puts(str);
    
    printf("3. Using fputs: ");
    fputs(str, stdout);
    
    printf("4. Using putchar (character by character):\n   ");
    for (int i = 0; str[i] != '\0'; i++) {
        putchar(str[i]);
    }
    
    return 0;
}
