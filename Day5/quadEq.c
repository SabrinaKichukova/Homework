/*
Author: Sabrina Kichukova
Putpose: This program calculate Quadratic equation
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int quadEq(double, double, double, double*, double*);

int main()
{
    double x1;
    double x2;
    double a,b,c;

printf("Please enter a, b and c:\n");
scanf("%lf %lf %lf",&a,&b,&c);

if (quadEq(a,b,c,&x1,&x2)==-1){

fprintf(stderr,"Error! 'a' must be bigger than 0!\n");

} else {

printf("\nx1 = %lf, x2 = %lf\n",x1,x2);

}

return EXIT_SUCCESS;
}


int quadEq(double a, double b, double c, double* x1, double* x2){

int D;

if (a==0){
            // "Error! 'a' must be bigger than 0!
return EXIT_FAILURE;


}

D=b*b-4*a*c;

if (D==0){

*x1  = (-b)/(2*a);
*x2  = (-b)/(2*a);

} else if (D>0){

*x1=((-b + sqrt(D))/(2*a));
*x2=((-b - sqrt(D))/(2*a));

} else{
    printf("No real root!");
}
return EXIT_SUCCESS;
}
