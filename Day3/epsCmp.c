#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int compare1(double a, double b)
{
    if (a == b)
    {
        return 0;
    }
    else 
    {
        return -1;
    }
}

int compare2(double a, double b)
{
    if (fabs(a - b) < __FLT_EPSILON__)
    {
        return 0;
    }
    else
    {
        return -1;
    }
}


int compare3(double a, double b)
{
    double EPS = 0.001;
    if (fabs(a - b) < EPS)
    {
        return 0;
    }
    else 
    {
        return -1;
    }
}

int compare4(double a, double b)
{
    if (fabs(a - b) < __FLT_EPSILON__ * fmax(fabs(a), fabs(b)))
    {
        return 0;
    }
    else
    {
        return -1;
    }
}
double RandomReal(double low, double high)
{
  double d;

  d = (double) rand() / ((double) RAND_MAX + 1);
  return (low + d * (high - low));
}  

int main()
{
    double low = 2.00000;
    double high = 2.00001;
    double a, b;
    int count1 = 0;
    int count2 = 0;
    int count3 = 0;
    int count4 = 0;

    for (int i = 0; i < 80; i++){

        a = RandomReal(low, high);
        b = RandomReal(low, high);

        printf("low: %.30lf - high: %.30lf\n", a, b);

        if (compare1(a, b) == 0)
        {
            count1++;
        }
        if (compare2(a, b) == 0)
        {
            count2++;
        }
        if (compare3(a, b) == 0)
        {
            count3++;
        }
        if (compare4(a, b) == 0)
        {
            count4++;
        }
        a = 0;
        b = 0;

    }
    printf("Compare 1 - %d\n", count1);
    printf("Compare 2 - %d\n", count2);
    printf("Compare 3 - %d\n", count3);
    printf("Compare 4 - %d\n", count4);

    return 0;
}

