/*
 * Purpose: Demonstrates a wide range of standard and common string manipulation functions.
 * Topic: Strings, String Functions (strlen, strcmp, strcasecmp, strcat, strncat, strcpy, strncpy, toupper, tolower, strrev, strset, strnset)
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_STRINGS 22
#define MAX_STRING_LENGTH 1000

// Reverse a string in place
char* custom_strrev(char* str) {
    if (!str) return NULL;
    char* start = str;
    char* end = str + strlen(str) - 1;
    char temp;
    while (end > start) {
        temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
    return str;
}

// Convert string to uppercase
char* custom_strupr(char* str) {
    if (!str) return NULL;
    char* original = str;
    while (*str) {
        *str = toupper((unsigned char)*str);
        str++;
    }
    return original;
}

// Convert string to lowercase
char* custom_strlwr(char* str) {
    if (!str) return NULL;
    char* original = str;
    while (*str) {
        *str = tolower((unsigned char)*str);
        str++;
    }
    return original;
}

// Case-insensitive string comparison
int custom_strcasecmp(const char* s1, const char* s2) {
    while (*s1 && *s2) {
        int diff = tolower((unsigned char)*s1) - tolower((unsigned char)*s2);
        if (diff != 0) return diff;
        s1++;
        s2++;
    }
    return tolower((unsigned char)*s1) - tolower((unsigned char)*s2);
}

// Set all characters in string to specified character
char* custom_strset(char* str, int ch) {
    if (!str) return NULL;
    char* original = str;
    while (*str) {
        *str = (char)ch;
        str++;
    }
    return original;
}

// Set first n characters in string to specified character
char* custom_strnset(char* str, int ch, size_t n) {
    if (!str) return NULL;
    char* original = str;
    for (size_t i = 0; i < n && *str; i++) {
        *str = (char)ch;
        str++;
    }
    return original;
}

// Print program header
void print_header(void) {
    printf("=== String Functions Demonstration ===\n");
    printf("Enter %d strings (one per line):\n\n", MAX_STRINGS);
}

// Read all strings from user input
int read_strings(char strings[][MAX_STRING_LENGTH]) {
    for (int i = 0; i < MAX_STRINGS; i++) {
        printf("String %d: ", i + 1);
        if (fgets(strings[i], MAX_STRING_LENGTH, stdin) == NULL) {
            fprintf(stderr, "Error: Failed to read string %d.\n", i + 1);
            return 0;
        }
        strings[i][strcspn(strings[i], "\n")] = '\0'; // Remove newline
    }
    return 1;
}

// Demonstrate string length function
void demo_strlen(const char strings[][MAX_STRING_LENGTH]) {
    size_t len = strlen(strings[0]);
    printf("1. Length of string 1: %zu characters\n", len);
}

// Demonstrate case-sensitive string comparison
void demo_strcmp(const char strings[][MAX_STRING_LENGTH]) {
    int result = strcmp(strings[1], strings[2]);
    printf("2. Comparing string 2 and string 3 (case-sensitive): ");
    if (result == 0) {
        printf("EQUAL\n");
    } else if (result > 0) {
        printf("String 2 > String 3\n");
    } else {
        printf("String 2 < String 3\n");
    }
}

// Demonstrate case-insensitive string comparison
void demo_strcasecmp(const char strings[][MAX_STRING_LENGTH]) {
    int result = custom_strcasecmp(strings[3], strings[4]);
    printf("3. Comparing string 4 and string 5 (case-insensitive): ");
    if (result == 0) {
        printf("EQUAL\n");
    } else if (result > 0) {
        printf("String 4 > String 5\n");
    } else {
        printf("String 4 < String 5\n");
    }
}

// Demonstrate string concatenation
void demo_strcat(char strings[][MAX_STRING_LENGTH]) {
    strcat(strings[5], " ");
    strcat(strings[5], strings[6]);
    printf("4. Concatenated string 6 + space + string 7: %s\n", strings[5]);
}

// Demonstrate limited string concatenation
void demo_strncat(char strings[][MAX_STRING_LENGTH]) {
    strcat(strings[7], " ");
    strncat(strings[7], strings[8], 5);
    printf("5. String 8 + space + first 5 chars of string 9: %s\n", strings[7]);
}

// Demonstrate string copy
void demo_strcpy(char strings[][MAX_STRING_LENGTH]) {
    strcpy(strings[9], strings[10]);
    printf("6. Copied string 11 to string 10: %s\n", strings[9]);
}

// Demonstrate limited string copy
void demo_strncpy(char strings[][MAX_STRING_LENGTH]) {
    strncpy(strings[11], strings[12], 5);
    strings[11][5] = '\0';
    printf("7. First 5 chars of string 13 copied to string 12: %s\n", strings[11]);
}

// Demonstrate string to uppercase conversion
void demo_strupr(char strings[][MAX_STRING_LENGTH]) {
    custom_strupr(strings[16]);
    printf("8. String 17 in uppercase: %s\n", strings[16]);
}

// Demonstrate string to lowercase conversion
void demo_strlwr(char strings[][MAX_STRING_LENGTH]) {
    custom_strlwr(strings[17]);
    printf("9. String 18 in lowercase: %s\n", strings[17]);
}

// Demonstrate string reversal
void demo_strrev(char strings[][MAX_STRING_LENGTH]) {
    custom_strrev(strings[18]);
    printf("10. String 19 reversed: %s\n", strings[18]);
}

// Demonstrate setting all characters
void demo_strset(char strings[][MAX_STRING_LENGTH]) {
    custom_strset(strings[19], '1');
    printf("11. String 20 with all chars set to '1': %s\n", strings[19]);
}

// Demonstrate setting first n characters
void demo_strnset(char strings[][MAX_STRING_LENGTH]) {
    custom_strnset(strings[20], '2', 5);
    printf("12. String 21 with first 5 chars set to '2': %s\n", strings[20]);
}

// Run all string function demonstrations
void run_demonstrations(char strings[][MAX_STRING_LENGTH]) {
    printf("\n=== String Function Results ===\n");
    
    demo_strlen(strings);
    demo_strcmp(strings);
    demo_strcasecmp(strings);
    demo_strcat(strings);
    demo_strncat(strings);
    demo_strcpy(strings);
    demo_strncpy(strings);
    demo_strupr(strings);
    demo_strlwr(strings);
    demo_strrev(strings);
    demo_strset(strings);
    demo_strnset(strings);
}

int main(void) {
    char strings[MAX_STRINGS][MAX_STRING_LENGTH];
    
    print_header();
    
    if (!read_strings(strings)) {
        return 1;
    }
    
    run_demonstrations(strings);
    
    return 0;
}
