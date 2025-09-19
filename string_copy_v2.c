/*
 * Purpose: Demonstrates copying a substring using strcpy and pointer manipulation.
 * Topic: Strings, Pointers
 */

#include <stdio.h>
#include <string.h>

int main(void) {
    char src1[100] = "UC Berkeley";
    char src2[100] = "(BAIR)";
    char *pointer1 = src1;
    char *pointer2 = strcpy(src2, src1 + 3);

    printf("src1: %s\n", src1);
    printf("src2: %s\n", src2);
    printf("pointer1: %s\n", pointer1);
    printf("pointer2: %s\n", pointer2);
    printf("(void*)pointer1: %p\n", (void*)pointer1);
    printf("pointer1 + 3: %s\n", pointer1 + 3);
    printf("(void*)(pointer1 + 3): %p\n", (void*)(pointer1 + 3));
    printf("strlen(src1 + 3): %zu\n", strlen(src1 + 3));
    printf("strlen(pointer1 + 3): %zu\n", strlen(pointer1 + 3));

    return 0;
}
