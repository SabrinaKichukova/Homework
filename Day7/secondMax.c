#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdint.h>

#define COUNT 5


int secondMax(const int* arr, size_t n, int* secMax);


int main()
{
    int arr[COUNT] = {12, 34, 5, 70, 46 };
 //   int arr[COUNT] = {0, 0, 0, 5, 0 };
    int secMax;

    secondMax(arr, COUNT, &secMax);
      
    return 0;
}

int secondMax(const int* arr, size_t n,int* secMax){

    int max = *arr;
    *secMax = *arr;
    int zerocnt = 0;
    int maxcnt = 0;
    int oneVal = 0;

    for(int i = 1; i<n; i++){
    if (*(arr+i)==0){
        zerocnt++;
        if(zerocnt == n){
            fprintf(stderr,"The array's countain only zeros.\n");
             return -1;
        }
     } else {

        oneVal++;   
    
     }
    
    if(max == *(arr+i)){
        maxcnt++;
        if(maxcnt == n){
        fprintf(stderr,"The array's countain equals values.\n");
        return -1;
        }
    }
    
    if(*(arr+i)>max){
        max = *(arr+i);
        
    }
    if ((max > *(arr+i)) && *(arr+i) > *secMax){
        *secMax = *(arr+i);
        
    }
    }
    if(oneVal == 1){
            fprintf(stderr,"The array's countain only one value.\n");
            return -1;
        }
    printf("%d\n",*secMax);
    return *secMax;
}
