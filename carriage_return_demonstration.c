/*
 * Purpose: Demonstrates the effect of the carriage return (\r) escape sequence in printf.
 *          The text after \r overwrites the beginning of the current line.
 * Topic: Basic I/O, Escape Sequences
 */

#include <stdio.h>

int main() {
    // Demonstrate carriage return effect
    // "WOLVERINE CAPTAINAMERICA WONDER WOMAN" overwrites "BATMAN SUPERTMAN IRONMAN"
    printf("Demonstrating carriage return effect:\n");
    printf("BATMAN SUPERTMAN IRONMAN\r WOLVERINE CAPTAINAMERICA WONDER WOMAN\n");

    return 0;
}
