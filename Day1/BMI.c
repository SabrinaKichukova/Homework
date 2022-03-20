/*
Author: Sabrina Kichukova
Purpose: This program calculate the Body Mass Index by two ways
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double bmi = 0.0;
    double bminew = 0.0;
    double const a = 1.3;
    double mass,height;

    printf("Please, enter your mass in kg:\n");
    scanf("%lf",&mass);

    printf("Please, enter height in meters:\n");
    scanf("%lf",&height);

    bmi = mass/(pow(height,2));
    bminew = (a*mass)/(pow(height,2.5));


    printf("Your body mass index is: %.2lf\n",bmi);

    printf("Your body mass index calculate by Trafeten's formula is: %.2lf\n",bminew);

    return EXIT_SUCCESS;
}