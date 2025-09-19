/*
 * Purpose: Checks if a string is a palindrome, a mirrored string, or a mirrored palindrome.
 * Topic: Strings, Conditionals, Character Handling, Modular Programming
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_STRING_LEN 10000


char get_mirrored_char(char c) {
    
    static char mirror_map[128] = {0}; 
    static int initialized = 0;
    
    if (!initialized) {
        
        char self_mirror[] = "AHIMOTUVWXY018";
        for (int i = 0; self_mirror[i]; i++) {
            mirror_map[self_mirror[i]] = self_mirror[i];
        }
        
        
        mirror_map['E'] = '3'; mirror_map['3'] = 'E';
        mirror_map['S'] = '2'; mirror_map['2'] = 'S';
        mirror_map['Z'] = '5'; mirror_map['5'] = 'Z';
        mirror_map['L'] = 'J'; mirror_map['J'] = 'L';
        
        initialized = 1;
    }
    
    char mirrored = (c >= 0 && c < 128) ? mirror_map[c] : '\0';
    return mirrored;
}


int is_palindrome(const char *str) {
    size_t len = strlen(str);

    for (size_t i = 0; i < len / 2; i++) {
        if (str[i] != str[len - 1 - i]) {
            return 0; 
        }
    }

    return 1; 
}


int is_mirrored_string(const char *str) {
    size_t len = strlen(str);

    for (size_t i = 0; i <= (len - 1) / 2; i++) {
        char mirrored = get_mirrored_char(str[i]);
        if (mirrored == '\0' || mirrored != str[len - 1 - i]) {
            return 0; 
        }
    }

    return 1; 
}


void classify_string(const char *str) {
    int palindrome = is_palindrome(str);
    int mirrored = is_mirrored_string(str);

    if (palindrome && mirrored) {
        printf("%s is a mirrored palindrome.\n\n", str);
    } else if (palindrome) {
        printf("%s is a regular palindrome.\n\n", str);
    } else if (mirrored) {
        printf("%s is a mirrored string.\n\n", str);
    } else {
        printf("%s is not a palindrome.\n\n", str);
    }
}

int main(void) {
    char input_string[MAX_STRING_LEN];

    printf("Enter strings (Ctrl+D to end input on Unix/Linux or Ctrl+Z on Windows):\n");

    while (scanf("%s", input_string) != EOF) {
        classify_string(input_string);
    }

    return 0;
}
