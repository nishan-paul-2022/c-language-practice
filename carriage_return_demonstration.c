/*
 * Purpose: Demonstrates the effect of the carriage return (\r) escape sequence in printf.
 *          The text after \r overwrites the beginning of the current line.
 * Topic: Basic I/O, Escape Sequences
 */

#include <stdio.h>

int main() {
    // Print a string with a carriage return character.
    // "WOLVERINE CAPTAINAMERICA WONDER WOMAN" will overwrite "BATMAN SUPERTMAN IRONMAN"
    // from the beginning of the line.
    printf("BATMAN SUPERTMAN IRONMAN\r WOLVERINE CAPTAINAMERICA WONDER WOMAN\n");

    return 0;
}
