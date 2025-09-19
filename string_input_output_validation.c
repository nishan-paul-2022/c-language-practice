/*
 * Purpose: Demonstrates string input validation techniques.
 * Topic: String input validation, Error handling, User input verification
 */

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 256

int main(void) {
    printf("Input Validation Example Demo\n");
    printf("=============================\n");

    int valid = 0;
    char input[BUFFER_SIZE];

    while (valid == 0) {
        printf("Enter a non-empty string: ");
        
        if (fgets(input, BUFFER_SIZE, stdin) != NULL) {
            input[strcspn(input, "\n")] = '\0';
            
            if (strlen(input) > 0) {
                printf("Success! Entered string: '%s'\n", input);
                valid = 1;
            } else {
                printf("Empty string. Please try again.\n");
            }
        }
    }
    
    return 0;
}
