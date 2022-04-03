#include <stdio.h>
#include <stdlib.h>

 unsigned char CheckBit(u_int16_t);

int main(void){

    u_int16_t uValue;
    printf("Enter number:\n");
    scanf("%hx", &uValue);
    printf("%d\n",CheckBit(uValue));

    return 0;
 }

 unsigned char CheckBit(u_int16_t uValue){

    unsigned int count = 0;
    while (uValue) {
        count += uValue & 1;
        uValue >>= 1;
    }
    if (count == 1){

        return count;
    } else {
        return 0;
    }
 }


 