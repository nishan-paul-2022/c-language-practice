// Purpose: Demonstrates reading user input into a string and assigning it to a structure member, highlighting safe input practices.
// Topic: Structures, String Input

#include <stdio.h>
#include <string.h>

// Define a structure to hold different data types
struct ExampleStructure {
    int integerValue;      // An integer member
    double doubleValue;    // A double-precision floating-point member
    char stringValue[100]; // A character array (string) member
};

int main() {
    // Declare an instance of the structure
    struct ExampleStructure myStruct;
    // Declare a buffer for user input
    char inputString[100];

    // Prompt user for input
    printf("Enter a string: ");

    // Safely read user input using fgets to prevent buffer overflow
    if (fgets(inputString, sizeof(inputString), stdin) != NULL) {
        // Remove the trailing newline character read by fgets, if present
        inputString[strcspn(inputString, "\n")] = 0;

        // Assign values to the structure members
        myStruct.integerValue = 10;
        myStruct.doubleValue = 10.12345;
        strcpy(myStruct.stringValue, inputString); // Copy the user's input string

        // Print the structure members
        printf("Integer: %d\n", myStruct.integerValue);
        printf("Double: %.2lf\n", myStruct.doubleValue);
        printf("String: %s\n", myStruct.stringValue);
    } else {
        fprintf(stderr, "Error reading input.\n");
        return 0;
    }

    return 0;
}
