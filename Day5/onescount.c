/*
Author:  Sabrina Kichukova
Purpose: This program count how many 1 there are in the mask using variadic function.
*/

#include <stdio.h>
#include <stdarg.h>
#include <stdint.h>

unsigned onesCount(size_t,unsigned, ...);

int main()
{
   onesCount(4,3,0x10011101111,0x111010,0x11101110);

    return 0;
}

unsigned onesCount(size_t size,unsigned count, ...){

va_list args;
    va_start(args, count);
    for (int i = 0; i < count; i++){
        if((size<1)||(size>sizeof(int))){
        
            fprintf(stderr,"Incorrect size of mask!");
            return EXIT_FAILURE;

        } else {

             int bit = 1;
             int bitcount=0;
             int lastbit=0;

             int args1 = va_arg(args, int);

             while(args1!=0){

                 

                 lastbit = args1 & bit;

                 if (lastbit == 1){
                     bitcount++;
                 }

               args1 = args1 >> 1;

             }

            printf("Number of 1 in the mask are: %d\n",bitcount);
        }
    }
        va_end(args);
    
    return EXIT_SUCCESS;
}
