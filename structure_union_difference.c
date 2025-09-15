/*
 * Purpose: Illustrates differences between structures and unions, and demonstrates typedef usage.
 * Topic: Structures, Unions, Typedef
 */

#include <stdio.h>

typedef struct {
    float integer_val;
    float float_val;
} StructExample;

typedef union {
    float integer_val;
    float float_val;
} UnionExample;

void demonstrate_struct(StructExample *s) {
    s->integer_val = 10.0f;
    s->float_val = 3.1416f;

    printf("--- Structure Example ---\n");
    printf("Struct integer_val: %.2f\n", s->integer_val);
    printf("Struct float_val:   %.4f\n", s->float_val);
}

void demonstrate_union(UnionExample *u) {
    u->float_val = 2.71f;
    u->integer_val = 20.0f;

    printf("\n--- Union Example ---\n");
    printf("Union integer_val: %.2f\n", u->integer_val);
    printf("Union float_val:   %.4f (may be unexpected)\n", u->float_val);
}

void demonstrate_typedef() {
    typedef float SalaryType;
    SalaryType employee_salary = 10000.45f;

    printf("\n--- Typedef Example ---\n");
    printf("Employee Salary: %.2f\n", employee_salary);
}

int main(void) {
    StructExample s_instance;
    UnionExample u_instance;

    demonstrate_struct(&s_instance);
    demonstrate_union(&u_instance);
    demonstrate_typedef();

    return 0;
}
