/*
Author:  Sabrina Kichukova
Purpose: Command calculator
*/

#include <stdio.h>
int main()
{
             double a;
             double b;
             double c;
             char operation;
            
             
            while(scanf("%lf %c %lf",&a, &operation, &b)!= EOF){


            switch (operation)
            {
            case '+':
              c=a+b;
              printf("%lf\n",c);
              break;
            case '-':
              c=a-b;
              printf("%lf\n",c);
              break;
            case '*':
              c=a*b;
              printf("%lf\n",c);
              break;
            case '/':
              c=a/b;
              printf("%lf\n",c);
              break;
          
            default: fprintf(stderr,"Error! Invalid operation!");
            }
            }
    return EXIT_SUCCESS;
}
