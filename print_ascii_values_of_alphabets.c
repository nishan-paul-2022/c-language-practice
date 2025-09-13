/*
 * Purpose: Prints the ASCII values of lowercase English alphabets ('a' to 'z').
 * Topic: Loops, Characters, ASCII Values
 */

#include <stdio.h>

int main(void) {
    for (char c = 'a'; c <= 'z'; c++) {
        printf("Character '%c' has ASCII value: %d\n", c, (int)c);
    }
    return 0;
}
