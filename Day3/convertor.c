/*
Author:  Sabrina Kichukova
Purpose: Convertor - works for base: 2 ,8 and 10.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

int checkForErr(int, int, int);


int main()
{
  int number;
  int inputbase;
  int outputbase;
  int a,b,c;
 

  printf("Please, enter number:");
  scanf("%d",&number);
  
  printf("Please, enter current base of the number:");
  scanf("%d",&inputbase);

  printf("Please, enter desired base of the number:");
  scanf("%d",&outputbase);

  isalnum(a);
  isalnum(b);
  isalnum(c);

  checkForErr(number,inputbase,outputbase);

  if((inputbase ==2)&&(outputbase==8)){

    printf("OCT: %o\n", number);
  
  } else if((inputbase ==2)&&(outputbase==10)){

    int dec = 0, i = 0, rem;

  while (number!=0) {
    rem = number % 10;
    number /= 10;
    dec += rem * pow(2, i);
    ++i;
  }
    printf("DEC: %d\n", dec);

  } else if((inputbase ==2)&&(outputbase==16)){

    int rem;
    int hex = 0;
    int i = 1;

    while (number != 0){
      rem = number % 10;
      hex = hex + rem * i;
      i = i * 2;
      number = number / 10;
   }

    printf("HEX: %x\n", hex);
  

  } else if((inputbase == 10)&&(outputbase==2)){

    int bin = 0;
    int rem;
    int i = 1;

  while (number!=0) {
    rem = number % 2;
    number /= 2;
    bin += rem * i;
    i *= 10;
  }
  printf("DEC: %d\n", bin);
  
  } else if((inputbase == 8)&&(outputbase==10)){

    int dec = 0;
    int i = 0;
 
  while (number != 0) {
    
    dec += (number%10) * (pow(8,i));
    ++i;
    number/=10;

    }

  printf("DEC: %d\n", dec); 

  } else if((inputbase == 8)&&(outputbase==2)){

    //First we converting octal to decimal
    int dec = 0;
    int i=0;

  while (number != 0) {
    

    dec += (number % 10) * (pow(8, i));
    ++i;
    number /= 10;
    
    }
    printf("BIN: %d\n", dec );
    //Next converting decimal to binary
    i = 1;
    int bin;

    while (dec != 0) {

    bin += (dec % 2) * i;
    dec /= 2;
    i *= 10;
    
    }
    printf("BIN: %d\n", bin );
  
    } else if((inputbase == 8)&&(outputbase==16)){

    printf("HEX: %x\n", number);


   } else if((inputbase == 16)&&(outputbase==10)){

    printf("DEC: %d\n", number );
    
    } else if((inputbase == 16)&&(outputbase==8)){

    printf("OCT: %o\n", number );
  
  } else {

    fprintf(stderr,"Not correct input data!");

  }

    return 0;
}


int checkForErr(int number, int inputbase, int outputbase){

if ((isalnum(number) && isalnum(inputbase) && isalnum(outputbase)) != 0 ){

  fprintf(stderr,"Not correct input data!");

  return -1;

}
if(((inputbase || outputbase)<=2) || ((inputbase || outputbase)>32)){

  fprintf(stderr,"Error! Not correct base!");

  return -1;

}

}


/*
  
  Bin to hex and hex to bin are not done yet. 

 if((inputbase == 8)&&(outputbase==16)){

   int i=0;
   
   char hex[]=&number;

   while(hex[i])  
   {  
       switch(hex[i])  
       {  
           case '0':  
           printf("0000");  
           break;  
           case '1':  
           printf("0001");  
           break;  
           case '2':  
           printf("0010");  
           break;  
           case '3':  
           printf("0011");  
           break;  
           case '4':  
           printf("0100");  
           break;  
           case '5':  
           printf("0101");  
           break;  
           case '6':  
           printf("0110");  
           break;  
           case '7':  
           printf("0111");  
           break;  
           case '8':  
           printf("1000");  
           break;  
           case '9':  
           printf("1000");  
           break;  
           case 'A':  
           printf("1010");  
           break;  
           case 'a':  
           printf("1010");  
           break;  
           case 'B':  
           printf("1011");  
           break;  
           case 'b':  
           printf("1011");  
           break;  
           case 'C':  
           printf("1100");  
           break;  
           case 'c':  
           printf("1100");  
           break;  
           case 'D':  
           printf("1101");  
           break;  
           case 'd':  
           printf("1101");  
           break;  
           case 'E':  
           printf("1110");  
           break;  
           case 'e':  
           printf("1110");  
           break;  
           case 'F':  
           printf("1111");  
           break;  
           case 'f':  
           printf("1111");  
           break;  
       }  
       i++;  
   }}  
    printf("HEX: %x\n", number );
    */