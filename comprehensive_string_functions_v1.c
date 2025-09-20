/*
 * Purpose: Demonstrates a wide range of standard and common string manipulation functions.
 * Topic: String, String Functions (strlen, strcmp, strcasecmp, strcat, strncat, strcpy, strncpy)
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_STRINGS 13
#define MAX_STRING_LENGTH 1000

int custom_strcasecmp(const char* s1, const char* s2) {
    while (*s1 && *s2) {
        int diff = tolower((unsigned char)*s1) - tolower((unsigned char)*s2);
        if (diff) {
            return diff;
        }
        s1++;
        s2++;
    }

    return tolower((unsigned char)*s1) - tolower((unsigned char)*s2);
}

void print_header() {
    printf("=== String Functions Demonstration ===\n");
    printf("Enter %d strings (one per line):\n\n", MAX_STRINGS);
}

int read_strings(char strings[][MAX_STRING_LENGTH]) {
    for (int i = 0; i < MAX_STRINGS; i++) {
        printf("String %d: ", i + 1);

        if (fgets(strings[i], MAX_STRING_LENGTH, stdin) == NULL) {
            fprintf(stderr, "Failed to read string %d.\n", i + 1);
            return -1;
        }

        strings[i][strcspn(strings[i], "\n")] = '\0'; 
    }

    return 0;
}

void demo_strlen(const char strings[][MAX_STRING_LENGTH]) {
    size_t len = strlen(strings[0]);
    printf("1. Length of string 1: %zu characters\n", len);
}

void demo_strcmp(const char strings[][MAX_STRING_LENGTH]) {
    int result = strcmp(strings[1], strings[2]);

    printf("2. Comparing string 2 and string 3 (case-sensitive): ");

    if (result == 0) {
        printf("Equivalent\n");
    } else if (result > 0) {
        printf("String 2 > String 3\n");
    } else {
        printf("String 2 < String 3\n");
    }
}

void demo_strcasecmp(const char strings[][MAX_STRING_LENGTH]) {
    int result = custom_strcasecmp(strings[3], strings[4]);

    printf("3. Comparing string 4 and string 5 (case-insensitive): ");

    if (result == 0) {
        printf("Equivalent\n");
    } else if (result > 0) {
        printf("String 4 > String 5\n");
    } else {
        printf("String 4 < String 5\n");
    }
}

void demo_strcat(char strings[][MAX_STRING_LENGTH]) {
    strcat(strings[5], " ");
    strcat(strings[5], strings[6]);
    printf("4. Concatenated string 6 + space + string 7: %s\n", strings[5]);
}

void demo_strncat(char strings[][MAX_STRING_LENGTH]) {
    strcat(strings[7], " ");
    strncat(strings[7], strings[8], 5);
    printf("5. String 8 + space + first 5 chars of string 9: %s\n", strings[7]);
}

void demo_strcpy(char strings[][MAX_STRING_LENGTH]) {
    strcpy(strings[9], strings[10]);
    printf("6. Copied string 11 to string 10: %s\n", strings[9]);
}

void demo_strncpy(char strings[][MAX_STRING_LENGTH]) {
    strncpy(strings[11], strings[12], 5);
    strings[11][5] = '\0';
    printf("7. First 5 chars of string 13 copied to string 12: %s\n", strings[11]);
}

void run_demonstrations(char strings[][MAX_STRING_LENGTH]) {
    printf("\n=== String Function Results ===\n");
    
    demo_strlen(strings);
    demo_strcmp(strings);
    demo_strcasecmp(strings);
    demo_strcat(strings);
    demo_strncat(strings);
    demo_strcpy(strings);
    demo_strncpy(strings);
}

int main(void) {
    char strings[MAX_STRINGS][MAX_STRING_LENGTH];
    
    print_header();
    
    if (read_strings(strings) == 0) {
        run_demonstrations(strings);
    }
    
    return 0;
}
