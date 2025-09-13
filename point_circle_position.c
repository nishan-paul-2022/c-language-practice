/*
 * Purpose: Determines if a given point is inside, outside, or on the circumference of a circle.
 * Topic: Geometry, Floating-point Arithmetic, Conditional Logic, Math Functions (sqrt)
 */

#include <stdio.h>
#include <math.h>

#define EPSILON 1e-9

double calculate_distance(int x1, int y1, int x2, int y2) {
    return sqrt((double)(x1 - x2) * (x1 - x2) + (double)(y1 - y2) * (y1 - y2));
}

void check_point_position(int case_num, int cx, int cy, double r, int px, int py) {
    double dist = calculate_distance(cx, cy, px, py);

    if (dist < r - EPSILON) {
        printf("Case %d: Inside\n", case_num);
    } else if (dist > r + EPSILON) {
        printf("Case %d: Outside\n", case_num);
    } else {
        printf("Case %d: OnCircle\n", case_num);
    }
}

int main(void) {
    int num_cases;
    scanf("%d", &num_cases);

    for (int i = 1; i <= num_cases; i++) {
        int cx, cy, px, py;
        double r;
        scanf("%d %d %lf %d %d", &cx, &cy, &r, &px, &py);
        check_point_position(i, cx, cy, r, px, py);
    }

    return 0;
}
