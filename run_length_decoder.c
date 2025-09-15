/*
 * Purpose: Decodes a custom run-length encoded string, where digits indicate repetition counts, 'b' indicates spaces, and '!' indicates a newline.
 * Topic: Strings, Character Processing, Loops, Conditional Statements (switch), Input/Output
 */

#include <stdio.h>
#include <string.h>

void decode_and_print(const char *encoded_string) {
    int repetition_count = 0;

    for (int i = 0; encoded_string[i] != '\0'; i++) {
        char current_char = encoded_string[i];

        if (current_char >= '1' && current_char <= '9') {
            repetition_count += (current_char - '0');
        } else {
            if (repetition_count == 0) {
                repetition_count = 1;
            }

            switch (current_char) {
                case '!':
                    printf("\n");
                    break;
                case 'b':
                    for (int m = 0; m < repetition_count; m++) {
                        printf(" ");
                    }
                    break;
                default:
                    for (int m = 0; m < repetition_count; m++) {
                        printf("%c", current_char);
                    }
                    break;
            }
            repetition_count = 0;
        }
    }
    printf("\n");
}

int main(void) {
    char encoded_string[100001];

    printf("Enter encoded strings (digits 1-9 for repetition, 'b' for space, '!' for newline).\n");
    printf("Example: 3A2b!5X\n");
    printf("Press Ctrl+D to exit.\n");

    while (fgets(encoded_string, sizeof(encoded_string), stdin) != NULL) {
        int len = strlen(encoded_string);
        if (len > 0 && encoded_string[len - 1] == '\n') {
            encoded_string[len - 1] = '\0';
        }
        decode_and_print(encoded_string);
    }

    printf("\nExiting program.\n");
    return 0;
}
