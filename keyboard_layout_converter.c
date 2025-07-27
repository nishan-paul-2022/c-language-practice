/*
 * Purpose: Converts characters in an input string based on a predefined keyboard-like mapping.
 * Topic: Strings, Character Manipulation, Lookup Tables, Input/Output
 */

#include <stdio.h>
#include <string.h> // For strlen()
#include <stdlib.h> // For EXIT_SUCCESS, EXIT_FAILURE

// Function to initialize the character mapping table
void initializeMapping(char map[])
{
    // Initialize with identity mapping (each character maps to itself)
    for (int i = 0; i < 256; i++)
    {
        map[i] = (char)i;
    }

    // Apply specific character substitutions based on the original file's logic
    // These mappings appear to simulate a keyboard shift or a specific cipher.

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

int main()
{
    char inputLine[10001]; // Buffer to store input line, +1 for null terminator
    char charMap[256];     // Lookup table for character mapping

    initializeMapping(charMap); // Populate the mapping table

    printf("Enter text to convert (press Ctrl+D to exit):\n");

    // Read input line by line using fgets for safety (prevents buffer overflow)
    while (fgets(inputLine, sizeof(inputLine), stdin) != NULL)
    {
        int length = strlen(inputLine);

        // Remove trailing newline character if present (fgets includes it)
        if (length > 0 && inputLine[length - 1] == '\n')
        {
            inputLine[length - 1] = '\0';
            length--; // Adjust length after removing newline
        }

        // Apply the character mapping to each character in the input line
        for (int i = 0; i < length; i++)
        {
            // Cast to unsigned char to ensure correct indexing for all possible char values
            inputLine[i] = charMap[(unsigned char)inputLine[i]];
        }

        printf("%s\n", inputLine); // Print the converted line
    }

    printf("\nExiting program.\n");
    return EXIT_SUCCESS;
}
