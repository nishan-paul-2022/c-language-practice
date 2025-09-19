/*
 * Purpose: Demonstrates various C preprocessor directives with a function-based approach for better organization
 * Topic: Preprocessor Directives, Macros, Conditional Compilation, Header Guards
 */

#include <stdio.h>
#include <stdlib.h>

// Object-like macros
#define PI 3.14159
#define MAX_BUFFER_SIZE 1024
#define VERSION "1.0.0"

// Function-like macros
#define SQUARE(x) ((x) * (x))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define DEBUG_PRINT(x) printf("[DEBUG] %s = %d\n", #x, x)

// Conditional compilation based on defined constants
#define DEBUG_MODE

// Platform-specific code
#ifdef _WIN32
    #define PLATFORM "Windows"
#elif __linux__
    #define PLATFORM "Linux"
#elif __APPLE__
    #define PLATFORM "macOS"
#else
    #define PLATFORM "Unknown"
#endif

// Feature toggles
#define FEATURE_ADVANCED_MATH 1

// Header guard simulation
#ifndef CONFIGURATION_H
#define CONFIGURATION_H
    #define CONFIG_LOADED 1
#endif

// Function declarations
void demonstrate_object_macros();
void demonstrate_function_macros();
void demonstrate_conditional_compilation();
void demonstrate_platform_detection();
void demonstrate_feature_toggles();
void demonstrate_header_guards();
void demonstrate_macro_undefining();

// Object-like macro demonstration
void demonstrate_object_macros() {
    printf("1. Object-like Macros:\n");
    printf("   PI = %f\n", PI);
    printf("   MAX_BUFFER_SIZE = %d\n", MAX_BUFFER_SIZE);
    printf("   VERSION = %s\n\n", VERSION);
}

// Function-like macro demonstration
void demonstrate_function_macros() {
    printf("2. Function-like Macros:\n");
    int a = 5, b = 8;
    printf("   SQUARE(%d) = %d\n", a, SQUARE(a));
    printf("   MAX(%d, %d) = %d\n", a, b, MAX(a, b));
    printf("   Using DEBUG_PRINT macro: ");
    DEBUG_PRINT(a);
    printf("\n");
}

// Conditional compilation demonstration
void demonstrate_conditional_compilation() {
    printf("3. Conditional Compilation:\n");
    #ifdef DEBUG_MODE
        printf("   Debug mode is ENABLED\n");
        printf("   Debug value: %d\n", 42);
    #else
        printf("   Debug mode is DISABLED\n");
    #endif
    
    #ifndef RELEASE_MODE
        printf("   Not in release mode\n");
    #endif
    printf("\n");
}

// Platform detection demonstration
void demonstrate_platform_detection() {
    printf("4. Platform Detection:\n");
    printf("   Compiled on: %s\n\n", PLATFORM);
}

// Feature toggle demonstration
void demonstrate_feature_toggles() {
    printf("5. Feature Toggles:\n");
    #if FEATURE_ADVANCED_MATH
        printf("   Advanced math features are ENABLED\n");
        printf("   Calculating complex expression: %f\n", PI * SQUARE(3.0));
    #else
        printf("   Advanced math features are DISABLED\n");
    #endif
    printf("\n");
}

// Header guard demonstration
void demonstrate_header_guards() {
    printf("6. Header Guard Simulation:\n");
    #ifdef CONFIG_LOADED
        printf("   Configuration loaded successfully\n");
    #endif
    printf("\n");
}

// Macro undefining and redefining demonstration
void demonstrate_macro_undefining() {
    printf("7. Undefining Macros:\n");
    printf("   MAX_BUFFER_SIZE is defined: %d\n", MAX_BUFFER_SIZE);
    #undef MAX_BUFFER_SIZE
    printf("   MAX_BUFFER_SIZE has been undefined\n");
    // printf("   MAX_BUFFER_SIZE = %d\n", MAX_BUFFER_SIZE); // This would cause an error
    
    // Redefining macros
    #define MAX_BUFFER_SIZE 2048
    printf("   MAX_BUFFER_SIZE redefined as: %d\n", MAX_BUFFER_SIZE);
}

int main(void) {
    demonstrate_object_macros();
    demonstrate_function_macros();
    demonstrate_conditional_compilation();
    demonstrate_platform_detection();
    demonstrate_feature_toggles();
    demonstrate_header_guards();
    demonstrate_macro_undefining();
    
    return 0;
}