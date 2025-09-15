/*
 * Purpose: Demonstrates parsing strings with sscanf and formatting strings with sprintf.
 * Topic: String Manipulation, Input/Output Functions
 */

#include <stdio.h>

#define MAX_WORDS 7
#define MAX_WORD_LENGTH 50

int parse_words(const char input[], char words[][MAX_WORD_LENGTH], int max_words) {
    int count = 0;
    const char *ptr = input;

    for (int i = 0; i < max_words; ++i) {
        if (sscanf(ptr, "%49[^ ]", words[i]) == 1) {
            count++;
            while (*ptr != ' ' && *ptr != '\0') { // Skip current word
                ptr++;
            }
            if (*ptr == ' ') {
                ptr++; // Skip space
            }
        } else {
            break; // No more words
        }
    }
    return count;
}

void format_output(char buffer[], int int_val, char char_val, const char str_val[], float float_val) {
    sprintf(buffer, "Formatted Output: %d %c %s %.2f", int_val, char_val, str_val, float_val);
}

int main(void) {
    char input_string[] = "UC Berkely (BAIR)";
    char parsed_words[MAX_WORDS][MAX_WORD_LENGTH];
    int integer_value = 10;
    char character_value = 'A';
    char format_string[] = "PhD in CSE";
    float float_value = 2.71f;
    char output_buffer[200];

    int words_scanned = parse_words(input_string, parsed_words, MAX_WORDS);
    format_output(output_buffer, integer_value, character_value, format_string, float_value);
    puts(output_buffer);

    printf("\nParsed Words:\n");
    for (int i = 0; i < words_scanned; ++i) {
        printf("%s\n", parsed_words[i]);
    }

    return 0;
}
