/* 
Author: Sabrina Kichukova
Purpose: This program sorting 3 numbers in descending order.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, c;
    int max;

    scanf("%d %d %d", &a, &b, &c);

    if ((a > b) && (a > c))
    {
        max = a;
        if (b > c)
        {
            printf("%d %d %d\n", max, b, c);
        }
        else
        {
            printf("%d %d %d\n", max, c, b);
        }
    }
    else if ((b > a) && (b > c))
    {
        max = b;
        if (a > c)
        {
            printf("%d %d %d\n", max, a, c);
        }
        else 
        {
            printf("%d %d %d\n", max, c, a);  
        }
    }
    else if ((c > a) && (c > b))
    {
        max = c;
        if (a > b)
        {
            printf("%d %d %d\n", max, a, b);
        }
        else
        {
            printf("%d %d %d\n", max, b, a);
        }
    }
    
    return EXIT_SUCCESS;
}
