/*
 * Purpose: Calculates an employee's total salary based on sales, commission, and bonus.
 * Topic: Basic I/O, Floating-point Arithmetic
 */

#include <stdio.h>

int main(void) {
    float num_computers_sold; // Number of computers sold by the employee
    float computer_price;     // Price of a single computer
    float total_sales_money;  // Total money generated from sales
    float commission_amount;  // Commission earned (2% of total sales)
    float bonus_amount;       // Bonus earned (200 per computer sold)
    float base_salary = 1500.0; // Fixed base salary
    float total_salary;       // Employee's total calculated salary

    // Prompt user for input: number of computers sold
    printf("Enter the number of computers sold: ");
    scanf("%f", &num_computers_sold);

    // Prompt user for input: price of a computer
    printf("Enter the price of one computer: ");
    scanf("%f", &computer_price);

    // Calculate total money from sales
    total_sales_money = num_computers_sold * computer_price;

    // Calculate commission (2% of total sales)
    commission_amount = (total_sales_money * 2) / 100;

    // Calculate bonus (200 per computer sold)
    bonus_amount = num_computers_sold * 200;

    // Calculate total salary (base + bonus + commission)
    total_salary = base_salary + bonus_amount + commission_amount;

    // Print the calculated total salary
    printf("The total salary should be: %.2f\n", total_salary);

    return 0;
}
