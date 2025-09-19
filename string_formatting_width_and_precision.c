/*
 * Purpose: Demonstrates combined width and precision in string formatting.
 * Topic: String formatting, Width and Precision, Format specifiers
 */

#include <stdio.h>

void display_section_header(const char *title) {
    printf("\n=== %s ===\n\n", title);
}

void demonstrate_width_precision_formatting() {
    char short_str[] = "ID";
    char medium_str[] = "Name";
    char long_str[] = "Description";
    char very_long[] = "Computer Science and Engineering";

    printf("Original strings:\n");
    printf("  Short: '%s' (1 char)\n", short_str);
    printf("  Medium: '%s' (5 chars)\n", medium_str);
    printf("  Long: '%s' (11 chars)\n", long_str);
    printf("  V.Long: '%s' (16 chars)\n", very_long);
    
    printf("\nWidth 10, Precision 3:\n");
    printf("  Short:  '%10.3s' (width 10, shows max 3)\n", short_str);
    printf("  Medium: '%10.3s' (width 10, truncate to 3)\n", medium_str);
    printf("  Long:   '%10.3s' (width 10, truncate to 3)\n", long_str);
    printf("  V.Long: '%10.3s' (width 10, truncate to 3)\n", very_long);
    
    printf("\nWidth 8, Precision 6:\n");
    printf("  Short:  '%8.6s' (width 8, shows all)\n", short_str);
    printf("  Medium: '%8.6s' (width 8, shows all)\n", medium_str);
    printf("  Long:   '%8.6s' (width 8, truncate to 6)\n", long_str);
    printf("  V.Long: '%8.6s' (width 8, truncate to 6)\n", very_long);
    
    printf("\nWidth 15, Precision 8:\n");
    printf("  Medium: '%15.8s'\n", medium_str);
    printf("  Long:   '%15.8s'\n", long_str);
    printf("  V.Long: '%15.8s'\n", very_long);
    
    printf("\nSpecial cases:\n");
    printf("  Width < Precision (12.15): '%12.15s'\n", long_str);
    printf("  Width = Precision (8.8):   '%8.8s'\n", long_str);
    printf("  Large width, small prec:   '%20.4s'\n", very_long);
}

int main(void) {
    display_section_header("Width and Precision Combined");
    demonstrate_width_precision_formatting();
    return 0;
}
