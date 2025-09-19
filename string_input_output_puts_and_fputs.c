/*
 * Purpose: Demonstrates string output using puts and fputs.
 * Topic: String output, puts, fputs, Stream output
 */

#include <stdio.h>

int main(void) {
    printf("String Output with puts() and fputs() Demo\n");
    printf("==========================================\n");
    
    printf("Using puts() (adds newline): ");
    char message[] = "This is a test message";
    puts(message);
    
    printf("Using fputs() to stdout: ");
    fputs(message, stdout);
    printf("\n");
    
    printf("Using fputs() to stderr: \n");
    fputs("Error message\n", stderr);
    
    return 0;
}
