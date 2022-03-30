#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void Reverse(char*);

int main(void){

char str[] = {"This is test!"};
Reverse(str);

printf("%s", str);
  
    return 0;
}

void Reverse(char* str1){

    int i = 0;
    int temp;
    int len = 0;

    while(str1[len]){
     len++;
    }

    for (i = 0; i < len/2; i++)  {

        temp = str1[i];  
        str1[i] = str1[len - i - 1];  
        str1[len - i - 1] = temp;  
    }
  
}
