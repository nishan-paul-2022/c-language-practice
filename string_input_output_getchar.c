/*
 * Purpose: Demonstrates character-by-character string input using getchar.
 * Topic: Character input/output, getchar, String construction
 */

#include <stdio.h>

#define BUFFER_SIZE 256

int main(void) {
    printf("String Input with getchar() Demo\n");
    printf("================================\n");
    
    int ch;
    int i = 0;
    char buffer[BUFFER_SIZE];

    printf("Enter text (press Enter to finish): ");

    while ((ch = getchar()) != '\n' && ch != EOF && i < BUFFER_SIZE - 1) {
        buffer[i++] = ch;
    }
    buffer[i] = '\0';
    
    printf("Read with getchar(): %s\n", buffer);
    
    return 0;
}
