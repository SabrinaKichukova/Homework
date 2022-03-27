#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include<inttypes.h>

void swapBytes(uint16_t*);

typedef union{
    uint16_t word;
    struct {
       uint16_t bit0:1;
       uint16_t bit1:1;
       uint16_t bit2:1;
       uint16_t bit3:1;
       uint16_t bit4:1;
       uint16_t bit5:1;
       uint16_t bit6:1;
       uint16_t bit7:1;
       uint16_t bit8:1;
       uint16_t bit9:1;
       uint16_t bit10:1;
       uint16_t bit11:1;
       uint16_t bit12:1;
       uint16_t bit13:1;
       uint16_t bit14:1;
       uint16_t bit15:1;
    };
}swap;
    

int main(){
uint16_t word;

printf("Please enter word:");
scanf("%hx",&word);

swapBytes(&word);

    return 0;
}

void swapBytes(uint16_t* word){

int temp;

swap swap1;
swap1.word = *word;
printf("Bit1:%d Bit15: %d\n",swap1.bit0,swap1.bit15);

temp = swap1.bit0;
swap1.bit0 = swap1.bit15;
swap1.bit15 = temp;

printf("Bit1:%d Bit15: %d\n",swap1.bit0,swap1.bit15);

}