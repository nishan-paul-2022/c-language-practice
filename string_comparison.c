/*
 * Purpose: Compares two strings lexicographically and prints the result.
 * Topic: String Manipulation, Input Safety
 */

#include <stdio.h>
#include <string.h>

int main(void) {
    printf("Enter the first string:\n");
    char str1[256];
    if (fgets(str1, sizeof(str1), stdin) == NULL) return 0;
    str1[strcspn(str1, "\n")] = 0;

    printf("Enter the second string:\n");
    char str2[256];
    if (fgets(str2, sizeof(str2), stdin) == NULL) return 0;
    str2[strcspn(str2, "\n")] = 0;

    int comparison = strcmp(str1, str2);

    if (comparison == 0) {
        printf("EQUAL\n");
    } else if (comparison < 0) {
        printf("%s\n", str2);
    } else {
        printf("%s\n", str1);
    }

    return 0;
}
