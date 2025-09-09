#include <stdio.h>
#include <string.h> // Although not strictly needed for this version, it's good practice for string operations.

int main() {
    char input_buffer[11]; // Buffer to store the input string. Size 10 for characters + 1 for null terminator.

    // Read input using a specific scanf format:
    // "%10[^6]" : Reads up to 10 characters into input_buffer, stopping if '6' is encountered.
    //             The characters read are stored in input_buffer.
    // "%*6"     : Reads and discards the next 6 characters from the input stream.
    //             This is often used to consume specific delimiters or unwanted characters.
    //             It's important to note that if '6' is encountered by the first part,
    //             it might be consumed by the second part if it's within the next 6 characters.
    if (scanf("%10[^6]%*6", input_buffer) != 1) {
        // If scanf fails to read at least one character into input_buffer,
        // it might indicate an issue with the input or format.
        // For simplicity, we'll just print an empty string if reading fails.
        // A more robust solution might involve clearing the input buffer.
        input_buffer[0] = '\0'; // Ensure buffer is empty if read fails
    }

    // Print the string stored in input_buffer, formatted to a width of 10 characters.
    // "%10s" ensures the output string is right-aligned within a field of 10 characters.
    // If the string is shorter than 10 characters, it will be padded with spaces.
    printf("%10s\n", input_buffer);

    return 0;
}
