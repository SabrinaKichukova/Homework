/*
Author: Sabrina Kichukova
Purpose: This program calculates the Volume of Horizontal Cylinder
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double area = 0.0;
    double volume = 0.0;
    double l, r, h;

    printf("Please, enter l:\n");
    scanf("%lf", &l);

    printf("Please, enter r:\n");
    scanf("%lf", &r);

    printf("Please, enter h:\n");
    scanf("%lf", &h);

    area = (acos((r - h) / r) * r * r) - ((r - h) * sqrt((2 * r * h) - (h * h)));
    volume = area * l;


    printf("The volume is: %lf\n", volume);

    return EXIT_SUCCESS;
}
