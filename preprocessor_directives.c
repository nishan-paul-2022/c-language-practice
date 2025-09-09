// Purpose: Demonstrates various C preprocessor directives like #define, #ifdef, #undef, #else.
// Topic: Preprocessor Directives, Macros, Conditional Compilation

#include <stdio.h> // Required for puts()

// Define a macro 'x'. This will be used by #ifdef.
// If this line is commented out, the #else block will be executed.
#define x puts("nishan paul\n") ;

int main() {

    // Example of conditional compilation using #if, #elif, #else.
    // This block is currently commented out.
    /*
    #if 20 > 20
        puts("one"); // This would execute if 20 > 20 were true.
    #elif (20 == 20)
        puts("two"); // This would execute because 20 == 20 is true.
    #else
        puts("third"); // This would execute if all preceding conditions were false.
    #endif
    */

    // Check if macro 'x' is defined.
    #ifdef x
    {
        // If 'x' is defined, undefine it and redefine it.
        // This demonstrates that macros can be redefined.
        #undef x
        #define x puts("cuet cse 16 batch") ;
    }
    #else
        // If 'x' is not defined, execute this block.
        puts("ok");
    // The following #ifndef is commented out, so it won't affect execution.
    /*
    #ifndef x
        puts("not ok");
    #endif
    */
    #endif

    // Execute the macro 'x'.
    // Since 'x' was defined and potentially redefined, this will execute the last definition.
    x

    return 0;
}
