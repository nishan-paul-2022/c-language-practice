/*
 * Purpose: Concatenates two strings manually using loops.
 * Topic: Strings, Arrays, Loops
 */

#include <stdio.h>
#include <string.h>

int main(void) {
    char str1[100], str2[100], result[200];
    int i, j;

    printf("Enter the first string: ");
    if (fgets(str1, sizeof(str1), stdin) == NULL) return 0;
    str1[strcspn(str1, "\n")] = 0;

    printf("Enter the second string: ");
    if (fgets(str2, sizeof(str2), stdin) == NULL) return 0;
    str2[strcspn(str2, "\n")] = 0;

    for (i = 0; str1[i] != '\0'; i++) result[i] = str1[i];
    for (j = 0; str2[j] != '\0'; j++) result[i + j] = str2[j];
    result[i + j] = '\0';

    printf("Concatenated string: %s\n", result);

    return 0;
}
