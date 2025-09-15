/*
 * Purpose: To determine the type of a triangle based on its side lengths.
 * Topic: Conditional Statements, Basic I/O
 */

#include <stdio.h>

int read_int(const char *prompt) {
    int value;
    printf("%s", prompt);
    if (scanf("%d", &value) != 1) {
        printf("Invalid input. Please enter an integer.\n");
        return -1;
    }
    return value;
}

void check_triangle_type(int a, int b, int c, int case_num) {
    if ((a + b > c) && (a + c > b) && (b + c > a)) {
        if (a == b && b == c) {
            printf("Case %d: Equilateral\n", case_num);
        } else if (a == b || b == c || c == a) {
            printf("Case %d: Isosceles\n", case_num);
        } else {
            printf("Case %d: Scalene\n", case_num);
        }
    } else {
        printf("Case %d: Invalid\n", case_num);
    }
}

int read_triangle_sides_and_check(int case_num) {
    int a = read_int("Enter first side: ");
    int b = read_int("Enter second side: ");
    int c = read_int("Enter third side: ");

    if(a <= 0 || b <= 0 || c <= 0) {
        printf("Case %d: Invalid\n", case_num);
        return -1;
    }

    check_triangle_type(a, b, c, case_num);
    return 0;
}

int main(void) {
    int num_cases = read_int("Enter the number of test cases: ");
    if (num_cases < 1) {
        return 0;
    }

    for (int i = 1; i <= num_cases; i++) {
        read_triangle_sides_and_check(i);
    }

    return 0;
}
