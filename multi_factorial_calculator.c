/*
 * Purpose: Calculates the multi-factorial (n!!!...k times) of a number,
 *          where k is determined by the number of exclamation marks in the input string.
 * Topic: String Parsing, Loops, Arithmetic Operations
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 100
#define MAX_SAFE_NUMBER 20

// Clear input buffer
void clear_input_buffer() {
    long long c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Read and validate input string
long long read_input_string(char input[], long long size) {
    printf("Enter a number followed by exclamation marks (e.g., 5!, 7!!, 10!!!): ");
    
    if (fgets(input, size, stdin) == NULL) {
        fprintf(stderr, "Failed to read input.\n");
        return -1;
    }
    
    // Remove trailing newline
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
        len--;
    }
    
    // Check for empty input
    if (len == 0) {
        fprintf(stderr, "Empty input provided.\n");
        return -1;
    }
    
    return 0;
}

// Validate input format and extract components
long long parse_and_validate_input(const char input[], long long *number, long long *exclamation_count) {    
    // Skip leading whitespace
    long long i = 0;
    while (input[i] && isspace(input[i])) {
        i++;
    }
    
    // Parse number part
    if (isdigit(input[i]) == 0) {
        fprintf(stderr, "Input must start with a positive number.\n");
        return -1;
    }
    
    long long num_len = 0;
    while (input[i] && isdigit(input[i])) {
        num_len++;
        i++;
    }
    
    // Count exclamation marks
    long long excl_count = 0;
    while (input[i] && input[i] == '!') {
        excl_count++;
        i++;
    }
    
    // Check for trailing characters
    while (input[i]) {
        if (isspace(input[i] == 0)) {
            fprintf(stderr, "Invalid characters after exclamation marks.\n");
            return -1;
        }
        i++;
    }
    
    // Extract number
    if (sscanf(input, "%lld", number) != 1) {
        fprintf(stderr, "Failed to parse number.\n");
        return -1;
    }
    
    // Validate number range
    if (*number < 0) {
        fprintf(stderr, "Number must be non-negative.\n");
        return -1;
    }
    
    if (*number > MAX_SAFE_NUMBER) {
        fprintf(stderr, "Large numbers may cause overflow. Maximum recommended: %d\n", MAX_SAFE_NUMBER);
        return -1;
    }
    
    *exclamation_count = excl_count;
    return 0;
}

// Calculate multi-factorial with overflow detection
long long calculate_multi_factorial(long long number, long long step) {
    if (number < 0) {
        return -1;
    }
    
    if (number <= 1) {
        return 1;
    }
    
    // Use step = 1 for regular factorial if no exclamation marks
    if (step == 0) {
        step = 1;
    }
    
    long long result = 1;
    
    for (long long i = number; i > 0; i -= step) {
        // Check for potential overflow
        if (result > LLONG_MAX / i) {
            fprintf(stderr, "Calculation would cause overflow.\n");
            return -1;
        }
        result *= i;
    }
    
    return result;
}

// Display calculation details and result
void display_result(long long number, long long exclamation_count, long long result) {
    printf("\nCalculation Details:\n");
    printf("-------------------\n");

    printf("Base number: %lld\n", number);
    
    if (exclamation_count == 0) {
        printf("Operation: Identity (no exclamation marks)\n");
        printf("Formula: %lld\n", number);
    } else if (exclamation_count == 1) {
        printf("Operation: Regular factorial\n");
        printf("Formula: %lld! = %lld × %lld × ... × 2 × 1\n", number, number, number - 1);
    } else {
        printf("Operation: Multi-factorial (%lld exclamation marks)\n", exclamation_count);
        printf("Formula: %lld", number);
        
        for (long long i = 0; i < exclamation_count; i++) {
            printf("!");
        }

        printf(" = %lld × %lld × %lld × ...\n", number, 
               number - exclamation_count > 0 ? number - exclamation_count : 0,
               number - 2 * exclamation_count > 0 ? number - 2 * exclamation_count : 0);
        
               printf("Step size: %lld\n", exclamation_count);
    }
    
    printf("\nResult: %lld\n", result);
}

int main(void) {
    printf("Multi-Factorial Calculator\n");
    printf("==========================\n");

    char input[MAX_INPUT_LENGTH];

    printf("This program calculates multi-factorials based on exclamation marks.\n");
    printf("Examples: 5! = 120, 7!! = 105, 6!!! = 18\n\n");

    if (read_input_string(input, sizeof(input)) == -1) {
        return 0;
    }
    
    long long number, exclamation_count;
    if (parse_and_validate_input(input, &number, &exclamation_count) == -1) {
        return 0;
    }
    
    long long result = calculate_multi_factorial(number, exclamation_count);
    if (result == -1) {
        return 0;
    }
    
    display_result(number, exclamation_count, result);
    
    return 0;
}
