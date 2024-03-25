/*
Author: Sabrina Kichukova
Purpose: This program calculate XOR in 2 modes for 2 and 3 digit.
*/

#include<stdio.h>
#include<stdlib.h>

int main()
{
    int a,b,c;
    int mode;
    int result;

    printf("\nFor 2 digits XOR mode enter 2, for 3 XOR mode enter 3.\n");
    scanf("%d",&mode);

    if ((mode != 2) & (mode != 3))
    {
        fprintf(stderr,"Invalid mode!");
        return EXIT_FAILURE;
    }

    if(mode == 2)
    {
        printf("\nEnter two numbers: 0 or 1\n");
        scanf("%d %d",&a,&b);

        if ((a!=0) && (b!=0) && (a!=1) && (b!=1))
        {
            fprintf(stderr,"Invalid numbers!\n");
            return EXIT_FAILURE;
        }
        else
        {
            result = ((a & ~b) || (~a & b));
            printf ("%d\n", result);
        }
    }

    if (mode ==3)
    {
        printf("Enter three numbers: 0 or 1\n");
        scanf("%d %d %d",&a,&b,&c);

        if (((a!=0) && (b!=0) && (c!=0)) && ((a!=1) && (b!=1) && (c!=1)))
        {
            fprintf(stderr, "Invalid numbers!\n"); // Error!
            return EXIT_FAILURE;
        }
        else
        {
            result = ((a & ~b & ~c) | (~a & b & ~c) | (~a & ~b & c) | (a & b & c));
            printf ("%d\n", result);
        }
    }

    return EXIT_SUCCESS;
}
