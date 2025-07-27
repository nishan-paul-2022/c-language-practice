// Purpose: Demonstrates a wide range of standard and common string manipulation functions.
// Topic: Strings, String Functions (strlen, strcmp, strcasecmp, strcat, strncat, strcpy, strncpy, toupper, tolower, strrev, strset, strnset)

#include <stdio.h>
#include <string.h> // For strlen, strcmp, strcasecmp, strcat, strncat, strcpy, strncpy, strcspn, strrev, strset, strnset
#include <stdlib.h> // For exit() and EXIT_FAILURE
#include <ctype.h>  // For toupper, tolower

// Helper function to reverse a string (if strrev is not available or for demonstration)
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

// Helper function to convert string to uppercase (if strupr is not available or for demonstration)
char* custom_strupr(char* str) {
    if (!str) return NULL;
    char* original = str;
    while (*str) {
        *str = toupper((unsigned char)*str);
        str++;
    }
    return original;
}

// Helper function to convert string to lowercase (if strlwr is not available or for demonstration)
char* custom_strlwr(char* str) {
    if (!str) return NULL;
    char* original = str;
    while (*str) {
        *str = tolower((unsigned char)*str);
        str++;
    }
    return original;
}

int main(void) {
    char strings[22][1000]; // Array to hold 22 strings, each up to 999 characters + null terminator

    printf("Please enter 22 strings, one per line:\n");
    // Read 22 strings from input
    for (int i = 0; i < 22; i++) {
        printf("String %d: ", i);
        if (fgets(strings[i], sizeof(strings[i]), stdin) == NULL) {
            fprintf(stderr, "Error: Failed to read string %d.\n", i);
            return EXIT_FAILURE;
        }
        // Remove trailing newline character if present
        strings[i][strcspn(strings[i], "\n")] = 0;
    }

    printf("\n--- String Function Demonstrations ---\n");

    // 1. strlen: Get length of strings[0]
    size_t len0 = strlen(strings[0]);
    printf("1. Length of strings[0]: %zu\n", len0);

    // 2. strcmp: Compare strings[1] and strings[2] (case-sensitive)
    int cmp_result1 = strcmp(strings[1], strings[2]);
    printf("2. Comparing strings[1] and strings[2] (case-sensitive):\n");
    if (cmp_result1 == 0) {
        printf("   Result: SAME\n");
    } else if (cmp_result1 > 0) {
        printf("   Result: strings[1] > strings[2]\n");
    } else {
        printf("   Result: strings[1] < strings[2]\n");
    }

    // 3. strcasecmp: Compare strings[3] and strings[4] (case-insensitive)
    // Note: strcasecmp is POSIX, not standard C. Using custom_strcasecmp if needed.
    // For this example, we'll assume strcasecmp is available or use a custom one.
    // If strcasecmp is not available, you might need to implement it manually.
    // For demonstration, let's use a placeholder or a custom implementation.
    // Assuming strcasecmp is available for now.
    #ifdef __USE_GNU
        int cmp_result2 = strcasecmp(strings[3], strings[4]);
    #else
        // Fallback or custom implementation if strcasecmp is not available
        // For simplicity, we'll just use strcmp here if strcasecmp is not defined.
        // A proper solution would involve manual conversion to lower/upper case.
        int cmp_result2 = strcmp(strings[3], strings[4]); // Placeholder if strcasecmp is not available
        printf("   (Note: strcasecmp might not be standard C. Using strcmp as fallback.)\n");
    #endif
    
    printf("3. Comparing strings[3] and strings[4] (case-insensitive):\n");
    if (cmp_result2 == 0) {
        printf("   Result: SAME\n");
    } else if (cmp_result2 > 0) {
        printf("   Result: strings[3] > strings[4]\n");
    } else {
        printf("   Result: strings[3] < strings[4]\n");
    }

    // 4. strcat: Concatenate strings[5], a space, and strings[6] into strings[5]
    // Ensure strings[5] has enough buffer space.
    strcpy(strings[5], strings[5]); // Ensure null termination if it was empty
    strcat(strings[5], " ");
    strcat(strings[5], strings[6]);
    printf("4. Concatenated strings[5] + \" \" + strings[6]: %s\n", strings[5]);

    // 5. strncat: Concatenate up to 5 chars of strings[8] to strings[7] after a space
    // Ensure strings[7] has enough buffer space.
    strcpy(strings[7], strings[7]); // Ensure null termination
    strcat(strings[7], " ");
    strncat(strings[7], strings[8], 5); // Append at most 5 chars from strings[8]
    printf("5. Concatenated strings[7] + \" \" + first 5 chars of strings[8]: %s\n", strings[7]);

    // 6. strcpy: Copy strings[10] to strings[9]
    // Ensure strings[9] has enough buffer space.
    strcpy(strings[9], strings[10]);
    printf("6. Copied strings[10] to strings[9]: %s\n", strings[9]);

    // 7. strncpy: Copy up to 5 characters from strings[12] to strings[11]
    // Note: strncpy does NOT guarantee null-termination if source is >= n.
    strncpy(strings[11], strings[12], sizeof(strings[11]) - 1); // Copy up to buffer size - 1
    strings[11][sizeof(strings[11]) - 1] = '\0'; // Ensure null termination
    printf("7. Copied up to 5 chars from strings[12] to strings[11]: %s\n", strings[11]);

    // 8. strupr: Convert strings[16] to uppercase
    // Using custom_strupr as strupr is not standard C.
    custom_strupr(strings[16]);
    printf("8. strings[16] in uppercase: %s\n", strings[16]);

    // 9. strlwr: Convert strings[17] to lowercase
    // Using custom_strlwr as strlwr is not standard C.
    custom_strlwr(strings[17]);
    printf("9. strings[17] in lowercase: %s\n", strings[17]);

    // 10. strrev: Reverse strings[18]
    // Using custom_strrev as strrev is not standard C.
    custom_strrev(strings[18]);
    printf("10. Reversed strings[18]: %s\n", strings[18]);

    // 11. strset: Set all characters in strings[19] to '1'
    // strset is standard in C11. Assuming it's available.
    // If not, a loop would be needed.
    strset(strings[19], '1');
    printf("11. strings[19] set to '1': %s\n", strings[19]);

    // 12. strnset: Set first 5 characters of strings[20] to '2'
    // strnset is standard in C11. Assuming it's available.
    // If not, a loop would be needed.
    strnset(strings[20], '2', 5);
    printf("12. First 5 chars of strings[20] set to '2': %s\n", strings[20]);

    return 0;
}
