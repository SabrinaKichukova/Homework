#include <stdio.h>
#include <stdlib.h>
#include <float.h>

union realtobit
{
    int32_t a;
    float b;
} real1;

int main()
{
    real1.a = 0;
   
    printf("Please enter real number:\n");
    scanf("%f", &real1.b);

    for (int i = 31; i >= 0; i--)
    {
        int k = real1.a >> i;
      
        if (k & 1)
            printf("1");
        else
            printf("0");
    }
    printf("\n");
    
    return 0;
}
