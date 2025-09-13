/*
 * Purpose: Converts characters in an input string based on a predefined keyboard-like mapping.
 * Topic: Strings, Character Manipulation, Lookup Tables, Input/Output
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void initialize_mapping(char map[]) {
    for (int i = 0; i < 256; i++) {
        map[i] = (char)i;
    }

    map[']'] = 'p';
    map['['] = 'o';
    map['\''] = 'l';
    map[';'] = 'k';
    map['.'] = 'm';
    map[','] = 'n';
    map['/'] = ',';
    map['='] = '0';
    map['-'] = '9';

    map['0'] = '8';
    map['9'] = '7';
    map['8'] = '6';
    map['7'] = '5';
    map['6'] = '4';
    map['5'] = '3';
    map['4'] = '2';
    map['3'] = '1';
    map['2'] = '`';

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

void convert_line(char input_line[], const char char_map[]) {
    int length = strlen(input_line);

    if (length > 0 && input_line[length - 1] == '\n') {
        input_line[length - 1] = '\0';
        length--;
    }

    for (int i = 0; i < length; i++) {
        input_line[i] = char_map[(unsigned char)input_line[i]];
    }
}

void process_text_conversion() {
    char input_line[10001];
    char char_map[256];

    initialize_mapping(char_map);

    printf("Enter text to convert (Ctrl+D to exit):\n");

    while (fgets(input_line, sizeof(input_line), stdin) != NULL) {
        convert_line(input_line, char_map);
        printf("%s\n", input_line);
    }

    printf("\nExiting program.\n");
}

int main(void) {
    process_text_conversion();
    return 0;
}
