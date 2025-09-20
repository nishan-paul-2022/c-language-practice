/*
 * Purpose: Demonstrates a wide range of standard and common string manipulation functions.
 * Topic: String, String Functions (strlen, toupper, tolower, strrev, strupr, strlwr, strset, strnset)
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_STRINGS 5
#define MAX_STRING_LENGTH 1000

char* custom_strrev(char* str) {
    if (!str) {
        return NULL;
    }

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

char* custom_strupr(char* str) {
    if (!str) {
        return NULL;
    }

    char* original = str;

    while (*str) {
        *str = toupper((unsigned char)*str);
        str++;
    }

    return original;
}

char* custom_strlwr(char* str) {
    if (!str) {
        return NULL;
    }

    char* original = str;

    while (*str) {
        *str = tolower((unsigned char)*str);
        str++;
    }

    return original;
}

char* custom_strset(char* str, int ch) {
    if (!str) {
        return NULL;
    }

    char* original = str;

    while (*str) {
        *str = (char)ch;
        str++;
    }

    return original;
}


char* custom_strnset(char* str, int ch, size_t n) {
    if (!str) {
        return NULL;
    }

    char* original = str;

    for (size_t i = 0; i < n && *str; i++) {
        *str = (char)ch;
        str++;
    }

    return original;
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

void demo_strupr(char strings[][MAX_STRING_LENGTH]) {
    custom_strupr(strings[0]);
    printf("1. String 1 in uppercase: %s\n", strings[0]);
}

void demo_strlwr(char strings[][MAX_STRING_LENGTH]) {
    custom_strlwr(strings[1]);
    printf("2. String 2 in lowercase: %s\n", strings[1]);
}

void demo_strrev(char strings[][MAX_STRING_LENGTH]) {
    custom_strrev(strings[2]);
    printf("3. String 3 reversed: %s\n", strings[2]);
}

void demo_strset(char strings[][MAX_STRING_LENGTH]) {
    custom_strset(strings[3], '1');
    printf("4. String 4 with all chars set to '1': %s\n", strings[3]);
}

void demo_strnset(char strings[][MAX_STRING_LENGTH]) {
    custom_strnset(strings[4], '2', 5);
    printf("5. String 5 with first 5 chars set to '2': %s\n", strings[4]);
}

void run_demonstrations(char strings[][MAX_STRING_LENGTH]) {
    printf("\n=== String Function Results ===\n");
    
    demo_strupr(strings);
    demo_strlwr(strings);
    demo_strrev(strings);
    demo_strset(strings);
    demo_strnset(strings);
}

int main(void) {
    char strings[MAX_STRINGS][MAX_STRING_LENGTH];
    
    print_header();
    
    if (read_strings(strings) == 0) {
        run_demonstrations(strings);
    }
    
    return 0;
}
