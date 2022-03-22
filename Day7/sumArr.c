#include<stdio.h>
#include<stdlib.h>

unsigned sumArrayDigits(const int* arr, size_t n);

int main()
{   
    const int arr[] = {50,25,7,3,66};
    printf("%d\n",sumArrayDigits(arr, 5));
    
    return 0;
}

unsigned sumArrayDigits(const int* arr, size_t n){

    int sum = 0;

    for(int i = 0; i<n; i++){
        sum += arr[i];
    }
    return sum;
}