/*
 * Purpose: Demonstrates copying a substring using strcpy and pointer manipulation.
 * Topic: Strings, Pointers
 */

#include <stdio.h>
#include <string.h>

int main(void) {
    char src[100] = "ABCDEFGHIJ";
    char dest[100] = "KLM";
    char *pointer1 = dest;

    // Copy substring starting from 4th character of src ("E1604085") into dest
    char *pointer2 = strcpy(dest, src + 3);

    printf("Substring of original dest: %s\n", pointer1 + 1); // "UET"
    printf("Pointer returned by strcpy: %p\n", (void*)pointer2);
    printf("Copied string in dest: %s\n", dest);
    printf("Length of copied string: %zu\n", strlen(src + 3));

    return 0;
}
