/*
 * Purpose: Reads a single character and determines if it is a vowel or consonant.
 * Topic: Character Handling, Conditional Statements, Functions
 */

#include <stdio.h>
#include <ctype.h>

// Function to check if a character is a vowel (a, e, i, o, u)
int is_vowel(char ch) {
    ch = tolower(ch); // Convert to lowercase for uniform check
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

// Function to check if a character is a lowercase or uppercase alphabet
int is_alphabet(char ch) {
    return ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'));
}

// Function to classify and print the character type
void classify_character(char ch) {
    if (!is_alphabet(ch)) {
        printf("Not an alphabet character.\n");
    } else if (is_vowel(ch)) {
        printf("%c is a vowel\n", ch);
    } else {
        printf("%c is a consonant\n", ch);
    }
}

int main(void) {
    char input_char;

    printf("Enter a single alphabet character: ");
    if (scanf(" %c", &input_char) != 1) {
        printf("[ERROR] Invalid input.\n");
        return 0;
    }

    classify_character(input_char);

    return 0;
}
