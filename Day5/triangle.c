#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int triangle(double, double, double, double* ,double*);

int main()
{
    double area;
    double p;
    double a, b, c;
    int n;
    
    printf("\nPlease, enter a, b, c:\n");

    while (scanf("%lf %lf %lf", &a, &b, &c) != EOF)
    {
        if (triangle(a, b, c, &p, &area) == 0)
        {
            printf("\nThe area is: %lf\n", area);
            printf("The perimeter is: %lf\n", p);
        }
    }    
    return EXIT_SUCCESS;
}

int triangle(double a, double b, double c, double* p, double* area)
{
    if ((a + b <= c) || (a + c <= b) || (c + b <= a))
    {
        fprintf(stderr, "\nInvalid triangle sides!\n");
        return EXIT_FAILURE;
    } 
    else
    {
        double sp;
        *p = a + b + c;
        sp = *p / 2;
        *area = sqrt(sp * (sp - a) * (sp - b) * (sp - c));
    }
    return EXIT_SUCCESS;
}
