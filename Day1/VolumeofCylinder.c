/*
Author: Sabrina Kichukova
Purpose: This program calculate the Volume of Cylinder
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double volume = 0.0;
    double const pi = 3.14;
    double r, h;

    printf("Please, enter r:\n");
    scanf("%lf", &r);

    printf("Please, enter h:\n");
    scanf("%lf", &h);

    volume = pi * r * r * h;

    printf("The volume is: %.2lf\n", volume);

    return EXIT_SUCCESS;
}
