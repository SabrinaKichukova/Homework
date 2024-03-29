#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/wait.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

#define COUNT 10
pthread_mutex_t mux;
int cmpfunc (const void* a, const void* b);

void* sort(void* arg)
{   
    int* retval = malloc(sizeof(int));
    pthread_mutex_lock(&mux);
    FILE* srcfile = fopen((char*)arg, "rb");
    if (NULL == srcfile)
    {
        perror("error");
        *retval = -1;
        return retval;
    }
    int num = 0;
    int buff[COUNT];
    int j = 0;
    while (fread(&num, sizeof(int), 1, srcfile))
    {
        buff[j] = num;
        j++;              
    }
    fclose(srcfile);

    qsort(buff, sizeof(buff), sizeof(int), cmpfunc);

    FILE* destfile = fopen((char*)arg, "wb");
    if (NULL == srcfile)
    {
        perror("error");
        *retval = -1;
        return retval;
    }
    for (int i = 0; i < COUNT; i++)
    {
        fwrite(&buff[i], sizeof(int), 1, destfile);
    }
    pthread_mutex_unlock(&mux);
}
            
int main(int argc, char const *argv[])
{   
    pthread_mutex_init(&mux, NULL);
    if(argc == 1)
    {
        perror("Missing arguments!");
        return EXIT_FAILURE;
    }   
    pthread_t th[argc - 1];

    for (int i = 1; i < argc; i++) 
    {    
        pthread_create(th + i, NULL, &sort, &argv[i]);
    }
            
    for (int i = 1; i < argc; i++)
    {
        void* retval;
        if(pthread_join(th[i], &retval))
        {
            perror("join error");
            return EXIT_FAILURE;
            free(&retval);
        }
    }  
    
    return EXIT_SUCCESS;
} 

int cmpfunc (const void* a, const void* b) 
{
   return ( *(int*)a - *(int*)b );
}
