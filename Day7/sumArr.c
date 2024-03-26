#include <stdio.h>
#include <stdlib.h>

unsigned sumArrayDigits(const int* arr, size_t n);

int main()
{   
    const int arr[] = {12, 34, 5, 70 };

    printf("%d\n",sumArrayDigits(arr, 4));
    
    return 0;
}

unsigned sumArrayDigits(const int* arr, size_t n){

    int sum = 0;
    int rem = 0;

    for(int i = 0; i < n; i++){

        int num = *(arr + i);

        while(num){

        rem = num % 10;
        sum += rem;
        num = num /10;
    
        }
    
    }
    return sum;
}
