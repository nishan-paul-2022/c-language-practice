/*
 * Purpose: Checks if a given string is a palindrome.
 * Topic: String manipulation, palindrome checking, loops, input/output.
 */

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 256

int is_palindrome(const char *str) {
    int len = strlen(str);
    
    if (len <= 1) {
        return 1;
    }
    
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - 1 - i]) {
            return 0; 
        }
    }

    return 1;
}

int main(void) {
    char input_string[BUFFER_SIZE];
    int continue_processing = 1;

    printf("Enter strings to check if they are palindromes.\n");

    while (continue_processing) {
        printf("Enter a string: ");
        
        if (fgets(input_string, BUFFER_SIZE, stdin) == NULL) {
            printf("Error reading input.\n");
            continue_processing = 0;
            break;
        }
        
        input_string[strcspn(input_string, "\n")] = 0;
        
        if (strcmp(input_string, "quit") == 0) {
            continue_processing = 0;
            break;
        }
        
        if (is_palindrome(input_string)) {
            printf("'%s' is a palindrome.\n", input_string);
        } else {
            printf("'%s' is not a palindrome.\n", input_string);
        }
    }

    return 0;
}
