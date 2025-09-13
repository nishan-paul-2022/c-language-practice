/*
 * Purpose: Demonstrates pointer arithmetic with various data types, showing how incrementing
 * a pointer moves it forward by the size of its base type.
 * Topic: Pointers, Pointer Arithmetic, Data Types, Memory Addresses
 */

#include <stdio.h>

void print_initial_addresses(short int *s, int *i, long int *l, long long *ll, char *c,
                             float *f, double *d, long double *ld) {
    printf("Initial addresses:\n");
    printf("ptr_to_short: %p (size: %zu)\n", (void *)s, sizeof(short int));
    printf("ptr_to_int: %p (size: %zu)\n", (void *)i, sizeof(int));
    printf("ptr_to_long: %p (size: %zu)\n", (void *)l, sizeof(long int));
    printf("ptr_to_long_long: %p (size: %zu)\n", (void *)ll, sizeof(long long));
    printf("ptr_to_char: %p (size: %zu)\n", (void *)c, sizeof(char));
    printf("ptr_to_float: %p (size: %zu)\n", (void *)f, sizeof(float));
    printf("ptr_to_double: %p (size: %zu)\n", (void *)d, sizeof(double));
    printf("ptr_to_long_double: %p (size: %zu)\n", (void *)ld, sizeof(long double));
    printf("\n");
}

void print_incremented_addresses(short int *s, int *i, long int *l, long long *ll, char *c,
                                 float *f, double *d, long double *ld) {
    printf("Addresses after incrementing each pointer:\n");
    printf("ptr_to_short: %p\n", (void *)s);
    printf("ptr_to_int: %p\n", (void *)i);
    printf("ptr_to_long: %p\n", (void *)l);
    printf("ptr_to_long_long: %p\n", (void *)ll);
    printf("ptr_to_char: %p\n", (void *)c);
    printf("ptr_to_float: %p\n", (void *)f);
    printf("ptr_to_double: %p\n", (void *)d);
    printf("ptr_to_long_double: %p\n", (void *)ld);
}

int main(void) {
    short int s;
    int i;
    long int l;
    long long ll;
    char c;
    float f;
    double d;
    long double ld;

    short int *ps = &s;
    int *pi = &i;
    long int *pl = &l;
    long long *pll = &ll;
    char *pc = &c;
    float *pf = &f;
    double *pd = &d;
    long double *pld = &ld;

    print_initial_addresses(ps, pi, pl, pll, pc, pf, pd, pld);

    ps++;
    pi++;
    pl++;
    pll++;
    pc++;
    pf++;
    pd++;
    pld++;

    print_incremented_addresses(ps, pi, pl, pll, pc, pf, pd, pld);

    return 0;
}
