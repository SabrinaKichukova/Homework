#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include<errno.h>

#define COUNT 5

typedef struct book{
    char name[150];
    char author[100];
    int  pages;
    double price;
   
} book;

double randDouble(double, double);
int randInt(int, int);
void printBook(book*);

int main(int argc, char** argv){

srand(time(NULL));

book books[COUNT]; 

for (int i = 0; i < COUNT; i++){

    int name_length = 4 + rand() % 7;
    for (int j = 0; j < name_length; j++){
        char rand_lowercase = 'a' + rand() % ('z' - 'a' + 1);
        char rand_uppercase = 'A' + rand() % ('Z' - 'A' + 1);
        int random_bit = rand() % 2;
 
        if (random_bit){
            books[i].name[j] = rand_lowercase;
        }
        else {
            books[i].name[j] = rand_uppercase;
        }    
    }
        books[i].name[name_length] = '\0';

        int author_length = 4 + rand() % 7;

    for (int j = 0; j < author_length; j++){
        char rand_lowercase = 'a' + rand() % ('z' - 'a' + 1);
        char rand_uppercase = 'A' + rand() % ('Z' - 'A' + 1);
        int random_bit = rand() % 2;
 
        if (random_bit){
            books[i].author[j] = rand_lowercase;
        }
        else{
            books[i].author[j] = rand_uppercase;
        }    
    }
    books[i].author[author_length] = '\0';

    books[i].pages = randInt(5,2000);   
    books[i].price = randDouble(1.0,1000);
}
    
    FILE* fp = fopen(argv[1],"w");
    if(NULL == fp){
        perror("Error: \n");
        return EXIT_FAILURE;
    }
    fwrite(&books,sizeof(book),COUNT,fp);
    fclose(fp);

         
return 0;
}

double randDouble(double min, double max){
    return min + ((double)rand() / RAND_MAX) * (max - min);
}
int randInt(int min, int max){
    return min + rand() % (max -min + 1); // [min; max]
}
