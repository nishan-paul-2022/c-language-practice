/*
 * Purpose: Demonstrates various printf functions for string output
 * Topic: printf, fprintf, sprintf, formatted output
 */

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 256

int main(void) {    
    printf("String Output with printf() Variants Demo\n");
    printf("=========================================\n");
    
    char sample[] = "UC Berkeley (BAIR)";
    printf("Basic printf: %s\n", sample);
    
    fprintf(stderr, "Error message to stderr: %s\n", "This goes to error stream");
    
    char formatted[BUFFER_SIZE];
    sprintf(formatted, "Formatted: '%s' has %zu characters", sample, strlen(sample));
    printf("sprintf result: %s\n", formatted);
    
    return 0;
}
