#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <string.h>
#define COUNT 10

int main(){

    int n; 
    printf("Please enter number:\n");
    scanf("%d", &n);
    srand(time(NULL));

    for (int i = 0; i < n; i++){
        pid_t pid = fork();
        if (0 == pid){

            char random[COUNT];

            for (int j = 0; j < COUNT; j++){
        
                char randstring = 'a' + rand() % ('z' - 'a' + 1);
                random[j] = randstring;
                random[COUNT] = '\0';
            }

            printf("%s\n",random);
         
             exit(EXIT_SUCCESS);
           }
          
    }
    for (int i = 0; i < n; i++){
        wait(NULL);
    }
    
    return EXIT_SUCCESS;
}

