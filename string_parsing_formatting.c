/*
 * Purpose: Demonstrates parsing strings with sscanf and formatting strings with sprintf.
 * Topic: String Manipulation, Input/Output Functions
 */

#include <stdio.h>

#define MAX_WORDS 7
#define MAX_WORD_LENGTH 50 // Increased buffer size for words

int main(void) {
    // Original data
    char input_string[] = "nishan paul 12345 cuet cse 16 batch";
    char parsed_words[MAX_WORDS][MAX_WORD_LENGTH];
    
    int integer_value = 10;
    char character_value = 'A';
    char format_string[] = "computer science & engineering";
    float float_value = 2.71f; // Use 'f' suffix for float literals
    
    char output_buffer[200]; // Buffer for formatted output

    // --- Using sscanf to parse the input string ---
    // sscanf reads formatted input from a string.
    // "%49[^ ]" reads up to 49 non-space characters into the current word buffer.
    // "%*c" consumes and discards the space character after each word.
    // This pattern is repeated to extract up to MAX_WORDS.
    // Note: This approach assumes words are separated by single spaces.
    // If there are multiple spaces or other delimiters, a different parsing strategy might be needed.
    int words_scanned = 0;
    for (int i = 0; i < MAX_WORDS; ++i) {
        // Read a word (up to MAX_WORD_LENGTH-1 characters) and then consume the separator.
        // The return value of sscanf indicates how many items were successfully scanned.
        // We expect to scan 2 items per iteration: the word and the separator.
        // However, we are only interested in the words themselves.
        // A more robust check would be to ensure words_scanned reaches MAX_WORDS.
        if (sscanf(input_string, "%49[^ ]%*c", parsed_words[i]) == 1) {
            words_scanned++;
        } else {
            // If sscanf fails to read a word, break the loop.
            // This handles cases where the input string has fewer than MAX_WORDS.
            break; 
        }
        // Advance the input string pointer for the next sscanf call.
        // This is implicitly handled by how sscanf works when called repeatedly on the same string
        // in a loop, but it's good to be aware of the underlying mechanism.
        // For a more explicit control, one might use a pointer to the current position in input_string.
    }

    // --- Using sprintf to format output ---
    // sprintf writes formatted output to a string.
    sprintf(output_buffer, "Formatted Output: %d %c %s %.2f", 
            integer_value, character_value, format_string, float_value);
    
    puts(output_buffer); // Print the formatted string

    // Print each parsed word
    printf("\nParsed Words:\n");
    for (int i = 0; i < words_scanned; ++i) {
        printf("%s\n", parsed_words[i]);
    }

    return 0;
}
