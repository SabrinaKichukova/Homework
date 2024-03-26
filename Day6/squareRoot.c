#include <stdio.h>

double SqrRoot(int*);

int main()
{   
    int n = 145;
    printf ("Square root of %d is : %lf\n", n, SqrRoot(&n));

    return 0;
}

double SqrRoot(int* n)
{
    double a = *n;
    double b = 0.1;
    double e = 0.000001;

    while ((a - b) > e)
    {
        a = (a + b) / 2;
        b = *n / a;
    }
    return a;
}
