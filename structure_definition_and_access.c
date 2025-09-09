// Purpose: Demonstrates the definition and usage of a structure in C, including initializing and accessing its members.
// Topic: Structures

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

    // Initialize the structure members
    myStruct.integerValue = 1;
    myStruct.doubleValue = 3.1416;
    strcpy(myStruct.stringValue, "string"); // Use strcpy for string assignment

    // Print the structure members
    printf("Integer: %d\n", myStruct.integerValue);
    printf("Double: %.2lf\n", myStruct.doubleValue);
    printf("String: %s\n", myStruct.stringValue);

    return 0;
}
