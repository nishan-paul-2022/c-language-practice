/*
 * Purpose: Demonstrate basic string formatting with printf.
 * Topic: Simple string output, basic %s specifier
 */

#include <stdio.h>

void display_section_header(const char *title) {
    printf("\n=== %s ===\n\n", title);
}

void demonstrate_basic_formatting() {
    char str1[] = "UC Berkeley";
    char str2[] = "BAIR";
    char str3[] = "California";
    char str4[] = "promise";
        
    printf("Basic output (str1): %s\n", str1);
    printf("Basic output (str2): %s\n", str2);
    printf("Basic output (str3): %s\n", str3);
    printf("A promise was once made, that promise will be kept.\n");
    printf("A promise was once made, that %s will be kept.\n", str4);
}

int main(void) {
    display_section_header("Basic String Formatting");
    demonstrate_basic_formatting();
    return 0;
}
