/*
 * Purpose: Demonstrates passing a string (character array) to a function and printing it using puts().
 * Topic: Functions, Strings, Arrays, Pointers
 */

#include <stdio.h> // Required for puts

// Function to print a string
// It takes a pointer to the first character of the string (char*)
void print_string_function(const char *text_string) {
    puts(text_string); // puts() prints the string followed by a newline character
}

int main() {
    // Declare and initialize a character array (string)
    char my_string[100] = "nishan paul cuet cse 16 batch";

    // Call the function to print the string
    printf("Printing string via function:\n");
    print_string_function(my_string);

    return 0;
}
