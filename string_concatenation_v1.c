/*
 * Purpose: Concatenates two strings manually using loops.
 * Topic: Strings, Arrays, Loops
 */

#include <stdio.h>
#include <string.h>

int main(void) {
    printf("Enter the first string: ");
    char str1[100];
    if (fgets(str1, sizeof(str1), stdin) == NULL) {
        return 0;
    }
    str1[strcspn(str1, "\n")] = 0;

    printf("Enter the second string: ");
    char str2[100];
    if (fgets(str2, sizeof(str2), stdin) == NULL) return 0;
    str2[strcspn(str2, "\n")] = 0;

    char result[200];

    int i;
    for (i = 0; str1[i] != '\0'; i++) {
        result[i] = str1[i];
    }

    int j;
    for (j = 0; str2[j] != '\0'; j++) {
        result[i + j] = str2[j];
    }

    result[i + j] = '\0';

    printf("Concatenated string: %s\n", result);

    return 0;
}
