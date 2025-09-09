/*
 * Purpose: Determines if a given point is inside, outside, or on the circumference of a circle.
 * Topic: Geometry, Floating-point Arithmetic, Conditional Logic, Math Functions (sqrt)
 */

#include <stdio.h>
#include <math.h>

// A small epsilon value for floating-point comparisons
#define EPSILON 1e-9

int main() {
    int num_test_cases; // Number of test cases
    int i;

    // Read the number of test cases
    scanf("%d", &num_test_cases);

    // Process each test case
    for (i = 1; i <= num_test_cases; i++) {
        int center_x, center_y;     // Coordinates of the circle's center
        double radius;               // Radius of the circle
        int point_x, point_y;       // Coordinates of the point to check
        double distance_from_center; // Distance from the circle's center to the point

        // Read circle center (x, y), radius, and point (x, y)
        scanf("%d %d %lf %d %d", &center_x, &center_y, &radius, &point_x, &point_y);

        // Calculate the Euclidean distance between the center and the point
        distance_from_center = sqrt(
            (double)(center_x - point_x) * (center_x - point_x) +
            (double)(center_y - point_y) * (center_y - point_y)
        );

        // Determine the point's position relative to the circle
        // Using EPSILON for robust floating-point comparison
        if (distance_from_center < radius - EPSILON) {
            printf("Case %d: Inside\n", i);
        } else if (distance_from_center > radius + EPSILON) {
            printf("Case %d: Outside\n", i);
        } else {
            printf("Case %d: OnCircle\n", i);
        }
    }

    return 0;
}
