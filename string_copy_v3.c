/*
 * Purpose: Reads two strings, copies the first into the second, and prints the result.
 * Topic: String copying
 */

#include <stdio.h>
#include <string.h>

int main(void) {
    char str1[10000], str2[10000];

    printf("Enter the first string: ");
    if (fgets(str1, sizeof(str1), stdin) == NULL) {
        return 0;
    }
    str1[strcspn(str1, "\n")] = 0;

    printf("Enter the second string: ");
    if (fgets(str2, sizeof(str2), stdin) == NULL) {
        return 0;
    }
    str2[strcspn(str2, "\n")] = 0;

    strcpy(str2, str1);

    printf("The copied string is: %s\n", str2);

    return 0;
}
