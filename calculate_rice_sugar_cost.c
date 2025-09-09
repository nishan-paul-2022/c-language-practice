/*
 * Purpose: Calculates the total cost of given quantities of rice and sugar.
 * Topic: Basic I/O, Floating-point Arithmetic
 */

#include <stdio.h>

int main() {
    float rice_quantity_kg; // Quantity of rice in kilograms
    float sugar_quantity_kg; // Quantity of sugar in kilograms
    float rice_cost_per_kg = 16.75; // Price of rice per kilogram
    float sugar_cost_per_kg = 15.00; // Price of sugar per kilogram
    float total_rice_cost; // Total cost of rice
    float total_sugar_cost; // Total cost of sugar

    // Prompt user for input
    printf("Enter the amount of rice and sugar in KG (e.g., 2.5 1.0): \n");
    scanf("%f %f", &rice_quantity_kg, &sugar_quantity_kg);

    // Calculate total cost for rice and sugar
    total_rice_cost = rice_quantity_kg * rice_cost_per_kg;
    total_sugar_cost = sugar_quantity_kg * sugar_cost_per_kg;

    // Print the calculated total costs, formatted to two decimal places
    printf("Total cost for rice: %.2f\n", total_rice_cost);
    printf("Total cost for sugar: %.2f\n", total_sugar_cost);

    return 0;
}
