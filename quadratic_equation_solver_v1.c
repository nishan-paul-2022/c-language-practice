/*
 * Purpose: Calculates and prints the roots of a quadratic equation (ax^2 + bx + c = 0).
 *          Handles cases for real and distinct, real and equal, and complex roots.
 * Topic: Conditional Statements, Mathematical Functions (sqrt), Floating-point Arithmetic
 */

#include <stdio.h>
#include <math.h>

int main(void) {
    float a, b, c;
    float discriminant;
    float root1, root2;
    float real_part, imag_part;

    printf("Enter the coefficients a, b, and c (e.g., 1.0 5.0 6.0): ");
    scanf("%f %f %f", &a, &b, &c);

    if (a == 0) {
        printf("'a' cannot be zero for a quadratic equation.\n");
    } else {
        discriminant = b * b - 4 * a * c;

        if (discriminant > 0) {
            root1 = (-b + sqrt(discriminant)) / (2 * a);
            root2 = (-b - sqrt(discriminant)) / (2 * a);

            printf("The roots are real and distinct.\n");
            printf("Root 1 = %.3f\n", root1);
            printf("Root 2 = %.3f\n", root2);
        } else if (discriminant == 0) {
            root1 = -b / (2 * a);

            printf("The roots are real and equal.\n");
            printf("Root 1 = Root 2 = %.3f\n", root1);
        } else {
            real_part = -b / (2 * a);
            imag_part = sqrt(-discriminant) / (2 * a);
            
            printf("The roots are complex and conjugate.\n");
            printf("Root 1 = %.3f + %.3fi\n", real_part, imag_part);
            printf("Root 2 = %.3f - %.3fi\n", real_part, imag_part);
        }
    }

    return 0;
}
