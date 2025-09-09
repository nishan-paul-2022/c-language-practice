/*
 * Purpose: Demonstrates the lifetime and behavior of static variables in C functions.
 * Topic: Variables, Scope, Lifetime, Static Keyword
 */

#include <stdio.h>

// Function 'f' demonstrates the use of a static variable.
void demonstrate_static_variable() {
    // 'local_var' is a regular local variable. It is initialized to 10
    // every time the function is called and its value is lost when the function exits.
    int local_var = 10; 
    
    // 'static_var' is a static local variable. It is initialized only once,
    // the first time the function is called. Its value persists across
    // subsequent calls to the function.
    static int static_var = 10; 

    // Increment both variables.
    local_var++; 
    static_var++;

    // Print the values of both variables.
    // local_var will always be 11 after the first call.
    // static_var will increment with each call (11, 12, 13, 14...).
    printf("Local variable: %d, Static variable: %d\n", local_var, static_var);
}

int main() {
    printf("Demonstrating static variable behavior:\n");
    
    // Call the function multiple times to observe the static variable's persistence.
    demonstrate_static_variable(); // Output: Local: 11, Static: 11
    demonstrate_static_variable(); // Output: Local: 11, Static: 12
    demonstrate_static_variable(); // Output: Local: 11, Static: 13
    demonstrate_static_variable(); // Output: Local: 11, Static: 14
    
    return 0;
}
