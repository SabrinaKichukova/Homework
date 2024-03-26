#include <stdio.h>
#define TERMS 7

float sine(int);
int fact(int);
float power(float, int);

int main()
{   
    int deg;
    scanf ("%d", &deg);
    printf("%f", sine(deg));
    return 0;
}
    
float sine(int deg)
{
    double pi = 3.14159;
    deg %= 360;
    float rad = deg * pi / 180;
    float sin = 0;

    int i;
    for (i = 0; i < TERMS; i++)
    { 
        sin += power(-1, i) * power(rad, 2 * i + 1) / fact(2 * i + 1);
    }
    return sin;
}

float power(float base, int exp)
{
    if (exp < 0) 
    {
        if (base == 0)
        {
            fprintf(stderr,"Error! Base = 0!")   
            return -1; 
        }
        return 1 / (base * power(base, (-exp) - 1));
    }
    if (exp == 0)
    {
        return 1;
    }
    if (exp == 1)
    {
        return base;
    }
    return base * power(base, exp - 1);
}

int fact(int n) 
{
    return n <= 0 ? 1 : n * fact(n - 1);
}
