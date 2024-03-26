#include <stdio.h>
#include <stdlib.h>

void quicksort(int arr[10], int first, int last);

int main()
{   
    int count = 10;
    int arr[] = {15, 95, 48, 63, 75, 55, 2, 9, 64, 3};
    
    quicksort(arr, 0, count-1);
    
    for (int i = 0; i < count; i++)
        {
            printf(" %d",arr[i]);
        }    
    return 0;
}

void quicksort(int arr[10], int first, int last)
{
    int i;
    int j;
    int pivot;
    int temp;
    
    if (first<last)
    {
        pivot = first;
        i = first;
        j = last;
    
        while (i < j)
        {
    
            while ((arr[i] <= arr[pivot]) && (i < last))
                i++;
    
            while (arr[j] > arr[pivot])
                j--;
    
            if (i < j)
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j]=temp;
            }
        }
    
        temp = arr[pivot];
        arr[pivot] = arr[j];
        arr[j] = temp;
        quicksort(arr, first, j - 1);
        quicksort(arr, j + 1, last);
    }
}


