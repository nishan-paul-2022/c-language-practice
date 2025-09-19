/*
 * Purpose: Calculates the total cost of given quantities of rice and sugar.
 * Topic: Basic I/O, Floating-point Arithmetic
 */

#include <stdio.h>

int main(void) {
    float rice_quantity_kg; 
    float sugar_quantity_kg;

    printf("Enter the amount of rice and sugar in KG (e.g., 2.5 1.0): ");
    if (scanf("%f %f", &rice_quantity_kg, &sugar_quantity_kg) != 2) {
        printf("Invalid input. Please enter two numbers separated by a space.\n");
        return 0;
    }

    double rice_cost_per_kg = 16.75;
    double total_rice_cost = rice_quantity_kg * rice_cost_per_kg;
    printf("Total cost for %.2f KG of rice at %.2f per KG: %.2f\n",
           rice_quantity_kg, rice_cost_per_kg, total_rice_cost);

    double sugar_cost_per_kg = 15.00;
    double total_sugar_cost = sugar_quantity_kg * sugar_cost_per_kg;
    printf("Total cost for %.2f KG of sugar at %.2f per KG: %.2f\n",
           sugar_quantity_kg, sugar_cost_per_kg, total_sugar_cost);

    float total_cost = total_rice_cost + total_sugar_cost;
    printf("Total cost: %.2f\n", total_cost);

    return 0;
}
