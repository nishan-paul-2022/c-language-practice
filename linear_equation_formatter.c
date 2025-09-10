/*
 * Purpose: Reads three integers and formats them into a linear equation string.
 * Topic: Input/Output, Basic Formatting
 */

#include <stdio.h>
#include <math.h>

int main() {
    int x, y, z;
    printf("ENTER THE VALUE : \n");
    scanf("%d %d %d", &x, &y, &z);
    printf("\n%da + %db + %d = 0", x, y, z);
    return 0;
}