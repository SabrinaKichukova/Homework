#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>


void bubbleSort(void*, size_t, size_t size, int (*)(const void*, const void*));
void (*getSorting(char*))(void*, size_t, size_t, int(*)(const void*, const void*));
int comp(const void*, const void* );
void swapg (void *, void*, size_t);


int main()
{   
    size_t size = 8;
    char* arr[] = {"dog", "cat", "frog", "bird", "fox", "lion", "horse", "fly"};
    
    //getSorting("qsort")(arr,size,sizeof(arr),comp);
    getSorting("bubbleSort")(arr, size, sizeof(arr), comp);

    for (int i = 0; i < size; i++)
    {
         printf("Sorted: %s\n", arr[i]);
    }        
    return 0;
}

void (*getSorting(char* fname))(void*, size_t, size_t, int(*)(const void*,const void*))
{
    if ((strcmp(fname, "bubbleSort")) == 0)
    {
        return bubbleSort;
    }
    if((strcmp(fname, "qsort")) == 0)
    {
        return qsort;
    }

}
 
void bubbleSort(void* arr, size_t size, size_t n, int (*comp)(const void*, const void*))
{
   for (int i = 0; i < n - 1; i++)
   {
       for (int j = 0; j < (n - i - 1) * size; j += size)
       {
           if (comp(arr + j, arr + j + size) < 0)
           {
              swapg(arr + j, arr + j + size, size);
           }
       }
   }
}

int comp(const void* str1, const void* str2)
{
    char* string1;
    char* string2;

    strcpy(string1, str1);
    strcpy(string2, str2);

    if (string1 == string2)
    {
        return 0;
    } 
    else if (string1 < string2)
    {
        return 1;
    } 
    else 
    {
        return -1;
    }
}

void swapg (void* str1, void* str2, size_t size)
{
    u_int8_t arr[size];
    memmove(arr, str1, size);
    memmove(str1, str2, size);
    memmove(str2, arr, size);
}
