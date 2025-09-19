/*
 * Purpose: Demonstrates width specification in string formatting.
 * Topic: Field width, right alignment, padding with spaces
 */

 #include <stdio.h>

void display_section_header(const char *title) {
    printf("\n=== %s ===\n\n", title);
}

void demonstrate_width_formatting() {
    char short_str[] = "ID";
    char medium_str[] = "Name";
    char long_str[] = "Description";
    char very_long[] = "Computer Science and Engineering";
    
    printf("Right-aligned with different widths:\n");
    printf("Width 10 with 'short_str':          '%10s' (8 spaces + 2 chars)\n", short_str);
    printf("Width 10 with 'medium_str':       '%10s' (5 spaces + 5 chars)\n", medium_str);
    printf("Width 10 with 'long_str': '%10s' (no padding - exceeds width)\n", long_str);
    printf("Width 15 with 'medium_str':       '%15s' (10 spaces + 5 chars)\n", medium_str);
    
    printf("\nVarious widths with same string:\n");
    printf("Width 5:  '%5s'\n", medium_str);
    printf("Width 8:  '%8s'\n", medium_str);
    printf("Width 12: '%12s'\n", medium_str);
    printf("Width 20: '%20s'\n", medium_str);
    
    printf("\nWidth behavior with different string lengths:\n");
    printf("Width 15 - Short:   '%15s'\n", short_str);
    printf("Width 15 - Medium:  '%15s'\n", medium_str);
    printf("Width 15 - Long:    '%15s'\n", long_str);
    printf("Width 15 - V.Long:  '%15s'\n", very_long);
}

int main(void) {
    display_section_header("Width Specification Formatting");
    demonstrate_width_formatting();
    return 0;
}
