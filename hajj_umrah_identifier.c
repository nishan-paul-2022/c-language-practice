/*
 * Purpose: Identifies "Hajj" or "Umrah" strings from input and prints corresponding messages with case numbers.
 * Topic: Strings, Conditional Logic, Input/Output
 */

#include <stdio.h>
#include <string.h>

void process_string(char *input_string, int case_number) {
    if (strcmp("Hajj", input_string) == 0) {
        printf("Case %d: Hajj-e-Akbar\n", case_number);
    } else if (strcmp("Umrah", input_string) == 0) {
        printf("Case %d: Hajj-e-Asghar\n", case_number);
    }
}

int main(void) {
    char input_string[100];
    int case_number = 1;

    while (scanf("%99s", input_string) == 1 && strcmp(input_string, "*")) {
        process_string(input_string, case_number);
        case_number++;
    }

    return 0;
}
