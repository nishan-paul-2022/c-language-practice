/*
 * Purpose: Demonstrates character output using putchar
 * Topic: putchar, character-by-character output
 */

#include <stdio.h>

int main(void) {
    printf("String Output with putchar() Demo\n");
    printf("=================================\n");
    
    char text[] = "Character by character output";

    printf("Using putchar(): ");

    for (int i = 0; text[i] != '\0'; i++) {
        putchar(text[i]);
    }

    printf("\n");
    
    return 0;
}
