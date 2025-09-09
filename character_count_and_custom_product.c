// Purpose: Reads an integer and a string, counts exclamation marks in the string,
//          and performs a custom product calculation based on the integer and the count.
// Topic: Input Handling (Mixed Types), String Iteration, Custom Calculation

#include <stdio.h>
#include <string.h> // Required for strlen if we were to remove trailing newline, but not strictly needed for this logic.

int main() {
    int input_number;
    char input_string[100]; // Buffer for the input string.
    int exclamation_count = 0;
    long long result_product = 1; // Use long long for product to avoid overflow.
    int current_n; // Variable to hold the changing value of n in the loop.
    int char_index;

    // --- Input Handling ---
    printf("Enter an integer followed by a string (e.g., 5 Hello! World!!): ");

    // Read the integer.
    if (scanf("%d", &input_number) != 1) {
        printf("Error: Invalid integer input.\n");
        return 1; // Indicate an error
    }

    // Consume the newline character left in the input buffer by scanf.
    // This is crucial before reading the string with fgets.
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    // Read the rest of the line as the string.
    // fgets is safer than scanf("%[^\n]s") as it handles buffer overflows better
    // and includes the newline character if space permits.
    if (fgets(input_string, sizeof(input_string), stdin) == NULL) {
        printf("Error: Invalid string input or end of file reached.\n");
        return 1;
    }

    // Note: fgets might include a trailing newline character ('\n') if it fits in the buffer.
    // The original code iterates until '\0', so a trailing newline would be processed.
    // If the newline itself were '!', it would be counted.

    // --- Character Counting ---
    // Iterate through the input string to count exclamation marks.
    for (char_index = 0; input_string[char_index] != '\0'; char_index++) {
        if (input_string[char_index] == '!') {
            exclamation_count++;
        }
    }

    // Print the initial integer and the count of exclamation marks.
    printf("Input integer: %d, Exclamation count: %d\n", input_number, exclamation_count);

    // --- Custom Product Calculation ---
    // The loop calculates a product based on the input number and the exclamation count.
    // It iteratively multiplies 'result_product' by 'current_n',
    // and decrements 'current_n' by 'exclamation_count' in each step,
    // as long as 'current_n' remains positive.
    current_n = input_number; // Initialize current_n with the input number.
    
    // Ensure we don't perform calculations if exclamation_count is 0 and input_number is 0,
    // or if input_number is not positive to begin with.
    if (input_number <= 0) {
        printf("Input number is not positive, product calculation is not applicable.\n");
        // If input_number was 0, result_product remains 1. If it was negative, it's also not applicable.
        // We can decide to print 0 or 1 in such cases, or indicate an error.
        // For now, we'll just print the initial result_product (1) if input_number <= 0.
    } else if (exclamation_count == 0) {
        // If there are no exclamation marks, the original code's loop condition (n>0)
        // would still run if n > 0. The calculation would be n * (n-0) * (n-0) ...
        // This seems like it would lead to n^k if n was decremented by 0.
        // However, the original code's loop is `while(n>0) { t = t*n; n = n-m; }`.
        // If m=0, n would never decrease, leading to an infinite loop if n > 0.
        // To avoid infinite loops, we should handle this case.
        // A reasonable interpretation is that if m=0, the product is just the input number itself,
        // or perhaps 1 if the number of terms is considered 0.
        // Given the original code's structure, if n>0 and m=0, it would be an infinite loop.
        // Let's assume for educational purposes, if m=0, the product is just the input number itself.
        // Or, if the loop is meant to run 'm' times, and m=0, it runs 0 times, so product is 1.
        // Let's follow the original code's logic as closely as possible but prevent infinite loops.
        // If m=0, the loop `while(n>0)` would be infinite if n>0.
        // We will assume that if m=0, the product is 1 (as if the loop ran 0 times).
        result_product = 1; // Or input_number, depending on interpretation. Let's stick to 1 for 0 terms.
        printf("No exclamation marks found. Product calculation results in 1 (as if 0 terms were multiplied).\n");
    }
    else {
        // Perform the custom product calculation.
        while (current_n > 0) {
            result_product *= current_n; // Multiply the result by the current value of n.
            current_n -= exclamation_count; // Decrement n by the count of exclamation marks.
        }
        // Print the final calculated product.
        printf("Custom product calculation result: %lld\n", result_product);
    }

    return 0;
}
