// Purpose: Identifies "Hajj" or "Umrah" strings from input and prints corresponding messages with case numbers.
// Topic: Strings, Conditional Logic, Input/Output

#include <stdio.h>
#include <string.h>

int main() {
    char input_string[100]; // Buffer to store each input string
    int case_number = 1;    // Counter for case numbers

    // Read strings until "*" is encountered
    while (scanf("%99s", input_string) == 1 && strcmp(input_string, "*") != 0) {
        // %99s ensures that no more than 99 characters are read, preventing buffer overflow.
        // scanf("%s") automatically handles whitespace and does not leave a newline.

        if (strcmp("Hajj", input_string) == 0) {
            printf("Case %d: Hajj-e-Akbar\n", case_number);
        } else if (strcmp("Umrah", input_string) == 0) {
            printf("Case %d: Hajj-e-Asghar\n", case_number);
        }
        case_number++;
    }

    return 0;
}
