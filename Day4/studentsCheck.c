#include <stdio.h>
#include <stdint.h>
int main()
{
    uint32_t attendance = 0b11111111111111111;
    int option;
    int student;
    int i = 0;
    int p;
    
        
        while (1)
     {
        printf("1. Set attendance\n");
        printf("2. Clear attendance\n");
        printf("3. Attendance info\n");
        printf("4. Change attendance\n");
        printf("5. Exit\n");

        scanf("%d", &option);

            switch (option)
            {
            case 1:
              printf("Student number:\n");
              scanf("%d",&student);

              attendance |= (1 << student-1);
              break;

            case 2:
              printf("Student number:\n");
              scanf("%d",&student);
              attendance &= ~(1 << student-1);
              break;

            case 3:
              for(i = 1 ;i<=32;i++){   
              p = !!(attendance & (1 << i));
              printf("Student number:%d - %d\n",p,i);
              }
              break;
            case 4:
              printf("Student number:\n");
              scanf("%d",&student);
              attendance ^= (1 << student-1);
              break;
            case 5:
              printf("Exit");
              return 0;
              break;
            }
      
     }
    return 0;
     }
