#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double *movingAverage(double* x, size_t len, size_t window);

int main(void)
{

    double x[] = {1.2, 2.2, 3.5, 4.5, 5, 4.3, 3.2, 2.1, 1.6, 1};
    int len = 10;
    double mvgArr[];
    memmove(mvgArr,*movingAverage(x, len, 3);

    for (int i = 0; i < len; i++)
    {
        printf("%lf ",mvgArr[i]);
    }
    return 0;
}

double *movingAverage(double* x, size_t len, size_t window)
{
    double* array = malloc(len * sizeof(double));
    if (NULL == array)
    {
        fprintf(stderr, "Memory allocation problem\n");
        EXIT_FAILURE;
    }
    int n = window / 2;
    double sum, sum1, sum2;

    for (int i = 0; i < len; i++)
    {
        for (int j = 0 ; j < n; n++)
        {
            sum1 = *(x + i) + *(x + (i - n));
            sum2 += *(x + (i + n));
            sum = sum1 + sum2;
        }
    double avrg = sum / window;
    array[i] = avrg;
    avrg = 0; 
    }
    return array;
}
