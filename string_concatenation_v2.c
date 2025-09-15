/*
 * Purpose: Concatenates two strings using the standard library function strcat.
 * Topic: String concatenation
 */

#include <stdio.h>
#include <string.h>

int main(void) {
    printf("Enter the first string: ");
    char str1[10000];
    if (fgets(str1, sizeof(str1), stdin) == NULL) {
        return 0;
    }
    str1[strcspn(str1, "\n")] = 0;

    printf("Enter the second string: ");
    char str2[10000];
    if (fgets(str2, sizeof(str2), stdin) == NULL) {
        return 0;
    }
    str2[strcspn(str2, "\n")] = 0;

    strcat(str1, str2);

    printf("Concatenated string is: %s\n", str1);

    return 0;
}
