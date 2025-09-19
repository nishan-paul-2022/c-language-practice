/*
 * Purpose: Demonstrate precision specification in string formatting.
 * Topic: String truncation, maximum characters to print
 */

#include <stdio.h>

void display_section_header(const char *title) {
    printf("\n=== %s ===\n\n", title);
}

void demonstrate_precision_formatting() {
    char short_str[] = "ID";
    char medium_str[] = "Name";
    char long_str[] = "Description";
    char very_long[] = "Computer Science and Engineering";
        
    printf("String truncation with precision:\n");
    printf("Original 'Name':         '%s'\n", medium_str);
    printf("Precision 3 with 'Name': '%.3s' (first 3 chars)\n", medium_str);
    printf("Precision 2 with 'Name': '%.2s' (first 2 chars)\n", medium_str);
    printf("Precision 1 with 'Name': '%.1s' (first 1 char)\n", medium_str);
    
    printf("\nPrecision with different string lengths:\n");
    printf("Precision 5 with 'ID':          '%.5s' (shorter than precision)\n", short_str);
    printf("Precision 5 with 'Name':       '%.5s' (equals precision)\n", medium_str);
    printf("Precision 5 with 'Description': '%.5s' (truncated)\n", long_str);
    
    printf("\nVarious precision values:\n");
    printf("%.1s | %.3s | %.5s | %.8s | %.12s\n", very_long, very_long, very_long, very_long, very_long);
    
    printf("\nPractical truncation examples:\n");
    printf("Full string: '%s'\n", very_long);
    printf("First word:  '%.8s...'\n", very_long);
    printf("Abbreviate:  '%.10s...'\n", very_long);
    printf("Preview:     '%.15s...'\n", very_long);
}

int main(void) {
    display_section_header("Precision Specification Examples");
    demonstrate_precision_formatting();
    return 0;
}
