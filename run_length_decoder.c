/*
 * Purpose: Decodes a custom run-length encoded string, where digits indicate repetition counts, 'b' indicates spaces, and '!' indicates a newline.
 * Topic: Strings, Character Processing, Loops, Conditional Statements (switch), Input/Output
 */

#include <stdio.h>
#include <string.h> // For strlen()
#include <stdlib.h> // For EXIT_SUCCESS, EXIT_FAILURE

int main()
{
    char encodedString[100001]; // Buffer for input string, +1 for null terminator
    int repetitionCount; // k in original
    int i;

    printf("Enter encoded strings (digits 1-9 for repetition, 'b' for space, '!' for newline).\n");
    printf("Example: 3A2b!5X\n");
    printf("Press Ctrl+D to exit.\n");

    // Use fgets for safer input reading
    while (fgets(encodedString, sizeof(encodedString), stdin) != NULL)
    {
        // Remove trailing newline character if present (fgets includes it)
        int len = strlen(encodedString);
        if (len > 0 && encodedString[len - 1] == '\n')
        {
            encodedString[len - 1] = '\0';
        }

        repetitionCount = 0; // Reset repetition count for each new line

        for (i = 0; encodedString[i] != '\0'; i++)
        {
            char currentChar = encodedString[i];

            if (currentChar >= '1' && currentChar <= '9')
            {
                // Accumulate repetition count from digits
                repetitionCount += (currentChar - '0');
            }
            else
            {
                // Process characters based on accumulated repetitionCount
                if (repetitionCount == 0)
                {
                    // If no digit was encountered, default to 1 repetition for the character
                    repetitionCount = 1;
                }

                if (currentChar == '!')
                {
                    printf("\n"); // Print a newline
                }
                else if (currentChar == 'b')
                {
                    for (int m = 0; m < repetitionCount; m++)
                    {
                        printf(" "); // Print spaces
                    }
                }
                else
                {
                    for (int m = 0; m < repetitionCount; m++)
                    {
                        printf("%c", currentChar); // Print the character
                    }
                }
                repetitionCount = 0; // Reset count after processing the character
            }
        }
        printf("\n"); // Ensure a newline after each processed line
    }

    printf("\nExiting program.\n");
    return EXIT_SUCCESS;
}
