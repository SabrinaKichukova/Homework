#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double randomReal(double, double);

int main(void)
{   
    srand(time(NULL));
    int n;
    scanf("%d", &n);

    double* array = (double*) malloc(n * sizeof(double));
    //double* array = (double*) calloc(n, sizeof(double));

    if (array == NULL)
    {
        fprintf(stderr, "Error!Problem with memory alocation!");
        return EXIT_FAILURE;
    }

    for (int i = 0; i < n; i++)
    {
       array[i] = randomReal(0, 1);
    }
    int m;
    scanf("%d", &m);

    array = realloc(array, (n + m) * sizeof(double));

    if (array == NULL)
    {  
        fprintf(stderr, "Error!Problem with memory alocation!"); 
        return EXIT_FAILURE;    
    }   

    for (int i = n; i < n + m; i++)
    {
        array[i] = randomReal(1, 2);
    }
    
    int p;
    scanf("%d",&p);

    array = realloc(array, (n + m + p)* sizeof(double));

    if (array == NULL)
    {
        fprintf(stderr, "Error!Problem with memory alocation!");
        return EXIT_FAILURE;
    }

    for (int i = n + m; i < n + m + p; i++)
    {
        array[i] = randomReal(2,3);
    }

    for(int i = 0; i < n + m + p; i++)
    {
        printf("%.2lf ",array[i]);
    }
    putchar('\n');
    
    free(array);
    return EXIT_SUCCESS;
}

double randomReal(double min,double max)
{
    return min + ((double)rand() / RAND_MAX) * (max - min);
}


