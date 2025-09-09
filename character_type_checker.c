/*
 * Purpose: Determines and prints the type of a single character input by the user
 *          (uppercase, lowercase, digit, punctuation, or whitespace).
 * Topic: Character Manipulation, Conditional Statements (if-else if), Input/Output
 */

#include <stdio.h>
#include <ctype.h>

int main()
{
    char inputChar;

    printf("Enter a single character: ");
    // Read a single character from standard input
    inputChar = getchar();

    // Check the type of the character using ctype.h functions
    if (isalpha(inputChar)) // Checks if it's an alphabet character
    {
        if (isupper(inputChar)) // Checks if it's an uppercase letter
        {
            printf("UPPER CASE\n");
        }
        else // Must be a lowercase letter
        {
            printf("LOWER CASE\n");
        }
    }
    else if (isdigit(inputChar)) // Checks if it's a digit (0-9)
    {
        printf("DIGIT\n");
    }
    else if (ispunct(inputChar)) // Checks if it's a punctuation character
    {
        printf("PUNCTUATION MARK\n");
    }
    else if (isspace(inputChar)) // Checks if it's a whitespace character (space, tab, newline, etc.)
    {
        printf("WHITE SPACE\n");
    }
    else
    {
        printf("OTHER CHARACTER\n"); // For any other character type
    }

    return 0;
}
