/*
 * Purpose: Demonstrates left alignment in string formatting.
 * Topic: String formatting, Left alignment, Format specifiers
 */

#include <stdio.h>

void display_section_header(const char *title) {
    printf("\n=== %s ===\n\n", title);
}

void demonstrate_left_alignment() {
    char short_str[] = "ID";
    char medium_str[] = "Name";
    char long_str[] = "Description";
        
    printf("Comparison of alignments (width 12):\n");
    printf("Right aligned: '%12s' (default)\n", medium_str);
    printf("Left aligned:  '%-12s' (with - flag)\n", medium_str);
    
    printf("\nLeft alignment with different widths:\n");
    printf("Width 8:  '%-8s' (end)\n", short_str);
    printf("Width 10: '%-10s' (end)\n", medium_str);
    printf("Width 15: '%-15s' (end)\n", long_str);
    printf("Width 20: '%-20s' (end)\n", medium_str);
    
    printf("\nLeft alignment with precision:\n");
    printf("Width 12, prec 5: '%-12.5s' (end)\n", long_str);
    printf("Width 10, prec 3: '%-10.3s' (end)\n", medium_str);
    printf("Width 15, prec 8: '%-15.8s' (end)\n", long_str);
    
    printf("\nPractical table formatting:\n");
    printf("| %-10s | %-8s | %-6s |\n", "Name", "Age", "Score");
    printf("| %-10s | %-8s | %-6s |\n", "Alice", "25", "95.5");
    printf("| %-10s | %-8s | %-6s |\n", "Bob", "30", "87.2");
    printf("| %-10s | %-8s | %-6s |\n", "Charlie", "22", "92.0");
    
    printf("\nMixed alignment in same line:\n");
    printf("Left: %-10s | Center-ish: %6s | Right: %8s\n", "Left", "Mid", "Right");
    printf("Left: %-10s | Center-ish: %6s | Right: %8s\n", "Data1", "Data2", "Data3");
}

int main(void) {
    display_section_header("Left Alignment vs Right Alignment");
    demonstrate_left_alignment();
    return 0;
}
