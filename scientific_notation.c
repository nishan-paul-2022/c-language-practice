/*
 * Purpose: Demonstrates printing numbers in scientific notation using different format specifiers.
 * Topic: Data Types, Format Specifiers, Scientific Notation
 */

#include <stdio.h>

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


void demonstrate_basic_formats(double large_number, double small_number, double regular_number) {
    printf("=== Scientific Notation Examples ===\n\n");
    
    
    printf("Large number (%%e): %e\n", large_number);
    printf("Small number (%%e): %e\n", small_number);
    printf("Regular number (%%e): %e\n\n", regular_number);
    
    
    printf("Large number (%%E): %E\n", large_number);
    printf("Small number (%%E): %E\n", small_number);
    printf("Regular number (%%E): %E\n\n", regular_number);
    
    
    printf("Large number (%%g): %g\n", large_number);
    printf("Small number (%%g): %g\n", small_number);
    printf("Regular number (%%g): %g\n\n", regular_number);
    
    
    printf("Large number (%%f): %f\n", large_number);
    printf("Small number (%%f): %f\n", small_number);
    printf("Regular number (%%f): %f\n\n", regular_number);
}


void demonstrate_precision_control(double large_number, double small_number, double regular_number) {
    printf("=== Precision Control ===\n");
    printf("Large number (%%.2e): %.2e\n", large_number);
    printf("Small number (%%.3e): %.3e\n", small_number);
    printf("Regular number (%%.4e): %.4e\n\n", regular_number);
}


void demonstrate_width_alignment(double regular_number) {
    printf("=== Width and Alignment ===\n");
    printf("Right-aligned in 15 chars: %15e\n", regular_number);
    printf("Left-aligned in 15 chars: %-15e\n", regular_number);
}


int get_user_input(double *user_number) {
    printf("Enter a number to see its scientific notation: ");

    if (scanf("%lf", user_number) != 1) {
        printf("Invalid input. Using default value.\n");
        *user_number = 1234.567;
        clear_input_buffer();
        return -1;
    }

    return 0;
}


void demonstrate_user_input() {
    double user_number;

    if (get_user_input(&user_number) != -1) {
        printf("\n=== Entered Number in Different Formats ===\n");
        printf("Scientific notation (%%e): %e\n", user_number);
        printf("Scientific notation (%%E): %E\n", user_number);
        printf("Automatic format (%%g): %g\n", user_number);
        printf("Fixed-point format (%%f): %f\n", user_number);
    }
}

int main(void) {
    
    double large_number = 1.23e10;
    double small_number = 4.56e-7;
    double regular_number = 1234.567;

    
    demonstrate_basic_formats(large_number, small_number, regular_number);

    
    demonstrate_precision_control(large_number, small_number, regular_number);

    
    demonstrate_width_alignment(regular_number);

    
    demonstrate_user_input();
    
    return 0;
}