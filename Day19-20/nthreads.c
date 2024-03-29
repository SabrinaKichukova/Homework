#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>

#define COUNT 10

void* func(void* arg)
{ 
    char random[COUNT];

    for (int j = 0; j < COUNT; j++)
    {    
        char randstring = 'a' + rand() % ('z' - 'a' + 1);
        random[j] = randstring;
        random[COUNT] = '\0';
    }
    printf("%s\n",random);
    sleep(1);
}

int main(int argc, char const *argv[])
{   
    int n = atoi(*(argv + 1));

    for (int i = 0; i < n; i++) 
    {
        srand(time(NULL));
        pthread_t th[i];
        pthread_create(&th[i], NULL, &func, NULL);
        pthread_join(th[i], NULL);
    }
    return 0;
}
