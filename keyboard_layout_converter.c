/*
* Purpose: Converts characters in an input string based on a predefined keyboard-like mapping.
* Topic: Strings, Character Manipulation, Lookup Tables, Input/Output
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to initialize the character mapping table
void initialize_mapping(char map[]) {
    // Initialize with identity mapping (each character maps to itself)
    for (int i = 0; i < 256; i++) {
        map[i] = (char)i;
    }

    // Apply specific character substitutions based on original file's logic
    // These mappings simulate a keyboard shift or specific cipher

    // Punctuation and symbols
    map[']'] = 'p';
    map['['] = 'o';
    map['\''] = 'l';
    map[';'] = 'k';
    map['.'] = 'm';
    map[','] = 'n';
    map['/'] = ',';
    map['='] = '0';
    map['-'] = '9';

    // Number shifts
    map['0'] = '8';
    map['9'] = '7';
    map['8'] = '6';
    map['7'] = '5';
    map['6'] = '4';
    map['5'] = '3';
    map['4'] = '2';
    map['3'] = '1';
    map['2'] = '`';

    // QWERTY keyboard letter shifts (right shift on keyboard)
    // Lowercase letters
    map['p'] = 'i';
    map['o'] = 'u';
    map['i'] = 'y';
    map['u'] = 't';
    map['y'] = 'r';
    map['t'] = 'e';
    map['r'] = 'w';
    map['e'] = 'q';

    map['l'] = 'j';
    map['k'] = 'h';
    map['j'] = 'g';
    map['h'] = 'f';
    map['g'] = 'd';
    map['f'] = 's';
    map['d'] = 'a';

    map['m'] = 'b';
    map['n'] = 'v';
    map['b'] = 'c';
    map['v'] = 'x';
    map['c'] = 'z';

    // Uppercase letters (mirroring lowercase shifts)
    map['P'] = 'I';
    map['O'] = 'U';
    map['I'] = 'Y';
    map['U'] = 'T';
    map['Y'] = 'R';
    map['T'] = 'E';
    map['R'] = 'W';
    map['E'] = 'Q';

    map['L'] = 'J';
    map['K'] = 'H';
    map['J'] = 'G';
    map['H'] = 'F';
    map['G'] = 'D';
    map['F'] = 'S';
    map['D'] = 'A';

    map['M'] = 'B';
    map['N'] = 'V';
    map['B'] = 'C';
    map['V'] = 'X';
    map['C'] = 'Z';
}

int main() {
    char input_line[10001]; // Buffer to store input line, +1 for null terminator
    char char_map[256];     // Lookup table for character mapping

    initialize_mapping(char_map); // Populate mapping table

    printf("Enter text to convert (press Ctrl+D to exit):\n");

    // Read input line by line using fgets for safety (prevents buffer overflow)
    while (fgets(input_line, sizeof(input_line), stdin) != NULL) {
        int length = strlen(input_line);

        // Remove trailing newline character if present (fgets includes it)
        if (length > 0 && input_line[length - 1] == '\n') {
            input_line[length - 1] = '\0';
            length--; // Adjust length after removing newline
        }

        // Apply character mapping to each character in input line
        for (int i = 0; i < length; i++) {
            // Cast to unsigned char to ensure correct indexing for all possible char values
            input_line[i] = char_map[(unsigned char)input_line[i]];
        }

        printf("%s\n", input_line); // Print converted line
    }

    printf("\nExiting program.\n");
    return EXIT_SUCCESS;
}