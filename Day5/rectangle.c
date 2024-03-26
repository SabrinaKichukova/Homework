#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h> 

int rectangle(double, double, double*, double*);

int main()
{
    double area;
    double p;
    double a,b;
    int n;
    
    printf("\nPlease, enter a, b:\n");

    while (scanf("%lf %lf", &a, &b) != EOF)
    {
        if((a || b) <= 0)
        {
            fprintf(stderr,"Invalid rectangle sides!");
        }
        else
        {
            rectangle(a, b, &p, &area);
            printf("\nThe area is: %lf\n", area);
            printf("The perimeter is: %lf\n", p);
        }
    }
    return EXIT_SUCCESS;
}

int rectangle(double a, double b, double* p, double* area)
{   
    *p = 2 *(a + b);
    *area = a * b;

    return EXIT_SUCCESS;
}
    
