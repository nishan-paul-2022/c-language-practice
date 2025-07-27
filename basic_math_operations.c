/*
 * Purpose: To perform various basic math operations based on user choice.
 * Topic: Functions, Menu-driven programs
 */

#include <stdio.h>
#include <math.h>

void division() {
    float x, y, z, a;
    printf("\n\nEnter the values for x, y, and z for the expression x / (y - z):\n");
    scanf("%f %f %f", &x, &y, &z);
    if (y - z != 0) {
        a = x / (y - z);
        printf("The result is: %f\n", a);
    } else {
        printf("Error: Division by zero.\n");
    }
}

void celsius_to_fahrenheit() {
    float celsius, fahrenheit;
    printf("\n\nEnter the Celsius value: ");
    scanf("%f", &celsius);
    fahrenheit = (9.0 / 5.0 * celsius) + 32;
    printf("The Fahrenheit value is: %f\n", fahrenheit);
}

void fahrenheit_to_celsius() {
    float celsius, fahrenheit;
    printf("\n\nEnter the Fahrenheit value: ");
    scanf("%f", &fahrenheit);
    celsius = 5.0 / 9.0 * (fahrenheit - 32);
    printf("The Celsius value is: %f\n", celsius);
}

void triangle_area() {
    float a, b, c, s, area;
    printf("\n\nEnter the length of the three sides: ");
    scanf("%f %f %f", &a, &b, &c);
    s = (a + b + c) / 2;
    area = sqrt(s * (s - a) * (s - b) * (s - c));
    printf("Area of the triangle is: %f\n", area);
}

void distance_between_points() {
    float x1, y1, x2, y2, distance;
    printf("\n\nEnter the coordinates of the first point (x1 y1): ");
    scanf("%f %f", &x1, &y1);
    printf("Enter the coordinates of the second point (x2 y2): ");
    scanf("%f %f", &x2, &y2);
    distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    printf("The distance between the two points is: %f\n", distance);
}

int main() {
    int choice;
    do {
        printf("\n\nChoose a calculation:\n");
        printf("1. Division\n");
        printf("2. Celsius to Fahrenheit\n");
        printf("3. Fahrenheit to Celsius\n");
        printf("4. Triangle Area\n");
        printf("5. Distance between two points\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                division();
                break;
            case 2:
                celsius_to_fahrenheit();
                break;
            case 3:
                fahrenheit_to_celsius();
                break;
            case 4:
                triangle_area();
                break;
            case 5:
                distance_between_points();
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 0);

    return 0;
}
