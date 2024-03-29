#include <stdio.h>  
#include <string.h>  

unsigned int BinSearch(unsigned int *, unsigned int, unsigned int);   

int main()  
{  
    unsigned int Array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    unsigned int uArraySize = sizeof(Array);
    unsigned int uValue = 8;

    unsigned int result = BinSearch(Array, uArraySize, uValue);

    if (result == -1)
    {
        fprintf (stderr, ("There is no such value!")); 
    }
    else
    {
        printf("The index of element is: %d", result);
    }
    
    return 0;
}  

unsigned int BinSearch(unsigned int *pArray, unsigned int uArraySize, unsigned int uValue)
{
    int right = uArraySize;
    int left = *pArray;

    while(left <= right)
    {
        int middle = (left + (right - left) / 2);
        
        if (uValue == middle)
        {
            return middle;
        } 
        else if(uValue > middle)
        {
            left = middle + 1;
        }
        else 
        {
            right = middle - 1;
        }    
    }
    return -1;   
}
