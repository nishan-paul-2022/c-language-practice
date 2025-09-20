/*
 * Purpose: Illustrates differences between structures and unions, and demonstrates typedef usage.
 * Topic: Structures, Unions, Typedef
 */

#include <stdio.h>

typedef struct {
    float i;
    float f;
} DataPair;

typedef union {
    float i;
    float f;
} SharedFloatData;

void demonstrate_struct(DataPair *s) {
    s->i = 10.0f;
    s->f = 3.1416f;

    printf("--- Structure Example ---\n");
    printf("Struct i: %.2f\n", s->i);
    printf("Struct f:   %.4f\n", s->f);
}

void demonstrate_union(SharedFloatData *u) {
    u->f = 2.71f;
    u->i = 20.0f;

    printf("\n--- Union Example ---\n");
    printf("Union i: %.2f\n", u->i);
    printf("Union f:   %.4f (may be unexpected)\n", u->f);
}

void demonstrate_typedef() {
    typedef float SalaryType;
    SalaryType employee_salary = 10000.45f;

    printf("\n--- Typedef Example ---\n");
    printf("Employee Salary: %.2f\n", employee_salary);
}

int main(void) {
    DataPair data_pair;
    SharedFloatData shared_floats;

    demonstrate_struct(&data_pair);
    demonstrate_union(&shared_floats);
    demonstrate_typedef();

    return 0;
}
