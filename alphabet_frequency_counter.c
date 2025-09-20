/*
 * Purpose: Reads a line of text and counts the frequency of each lowercase alphabet character within it.
 * Topic: String Manipulation, Loops, Character Handling, Arrays
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void read_input(char *buffer, int size) {
    printf("Enter a line of text: ");
    if (fgets(buffer, size, stdin) == NULL) {
        printf("\nError reading input.\n");
        exit(1);
    }
    
    buffer[strcspn(buffer, "\n")] = '\0'; 
}

void count_frequencies(const char *input, int freq[]) {
    for (int i = 0; input[i] != '\0'; i++) {
        char lower_char = tolower((unsigned char)input[i]);
        if (lower_char >= 'a' && lower_char <= 'z') {
            freq[lower_char - 'a']++;
        }
    }
}

void display_frequencies(const int freq[]) {
    printf("\nAlphabet Frequencies:\n");
    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0) {
            printf("%c - %d\n", 'a' + i, freq[i]);
        }
    }
}

int main(void) {
    char input_string[100];
    int frequency[26] = {0};

    read_input(input_string, sizeof(input_string));
    count_frequencies(input_string, frequency);
    display_frequencies(frequency);

    return 0;
}
