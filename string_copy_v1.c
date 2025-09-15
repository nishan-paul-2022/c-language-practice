/*
 * Purpose: Copy a string character by character using a loop.
 * Topic: Strings, Loops
 */

#include <stdio.h>
#include <string.h>

int main(void) {
    char src[100], dest[100];
    int i;

    printf("Enter a string: ");
    if (fgets(src, sizeof(src), stdin) == NULL) {
        return 0;
    }
    src[strcspn(src, "\n")] = 0;

    for (i = 0; src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';

    printf("Original string: %s\n", src);
    printf("Copied string: %s\n", dest);

    return 0;
}
