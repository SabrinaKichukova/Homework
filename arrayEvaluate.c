#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void arrayEvaluate(int* arr, size_t n, int(*f)(int*,int));
int sum(int* arr, int n);

int main()
{   
    int arr[] = {50,25,7,3,66};

    size_t n = 5;

    arrayEvaluate(arr,n,sum);

    return 0;

}

int sum (int* arr, int n){

    int sum = 0;

    for(int i = 0; i <n ; i++){

        sum += arr[i];
    }

    return sum;

}
void arrayEvaluate(int* arr, size_t n, int(*f)(int*,int)){

printf("%d\n", f(arr,n)); 

}
    