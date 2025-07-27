// Purpose: Illustrates the fundamental differences between structures (struct) and unions (union) in C,
//          highlighting how members are stored and accessed, and demonstrates the use of typedef.
// Topic: Structures, Unions, Typedef

#include <stdio.h>

// Define a structure named StructExample.
// Each member of a structure has its own unique memory location.
typedef struct {
    float integer_val; // Member to store a floating-point value (intended as integer part).
    float float_val;   // Member to store a floating-point value.
} StructExample;

// Define a union named UnionExample.
// All members of a union share the same memory location.
// The value of the last member written to is the one that is valid.
typedef union {
    float integer_val; // Member to store a floating-point value (intended as integer part).
    float float_val;   // Member to store a floating-point value.
} UnionExample;

int main() {
    // Declare an instance of the structure.
    StructExample struct_instance;

    // Assign values to the members of the structure.
    // Both members have separate memory, so both assignments are valid and retained.
    struct_instance.integer_val = 10.0f; // Assigning to integer_val
    struct_instance.float_val = 3.1416f; // Assigning to float_val

    // Declare an instance of the union.
    UnionExample union_instance;

    // Assign values to the members of the union.
    // Both members share the same memory. The last assignment determines the valid value.
    union_instance.float_val = 2.71f;   // Assigning to float_val
    // Now, assigning to integer_val will overwrite the memory used by float_val.
    union_instance.integer_val = 20.0f;

    // Print the values.
    // For the structure, both members retain their assigned values.
    // For the union, accessing float_val after assigning to integer_val will yield
    // the bit representation of 20.0f interpreted as a float.
    printf("--- Structure Example ---\n");
    printf("Struct integer_val: %.2f\n", struct_instance.integer_val);
    printf("Struct float_val:   %.4f\n", struct_instance.float_val);

    printf("\n--- Union Example ---\n");
    printf("Union integer_val: %.2f\n", union_instance.integer_val);
    // Note: The value printed for union_instance.float_val will likely be garbage
    // or the bit-representation of 20.0f interpreted as a float, not 2.71f.
    printf("Union float_val:   %.4f (Note: Value may be unexpected due to union behavior)\n", union_instance.float_val);

    // Demonstrate typedef for a custom type alias.
    typedef float SalaryType;
    SalaryType employee_salary = 10000.45f;

    printf("\n--- Typedef Example ---\n");
    printf("Employee Salary: %.2f\n", employee_salary);

    return 0; // Indicate successful execution.
}
