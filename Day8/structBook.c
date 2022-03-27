#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define COUNT 5

typedef struct {
    char name[150];
    char author[100];
    int  pages;
    double price;
} book;

void printInfo(book);
void bubbleSort(void* , size_t, size_t, int (*comp)(const void*,const void*));
double randDouble(double, double);
int randInt(int, int);
int strCompName(const void* , const void*);
void swapg (void *, void *, size_t);
int strCompAuthor(const void* , const void*);
int compareInt(const void*, const void*);
int compareDouble(const void* , const void*);
void *lsearch(void* , size_t, void*, size_t, int (*comp)(const void*, const void*));
int binarySearch(int* , size_t, int);


int main(){
    
    srand(time(NULL)); 
    const char names[][10] = {"HarryP","Inferno","Origin","TheHobbit","Thesecret"};
    const char authors[][10] = { "Tolkien","Alex","DanBrown","Rowling","Vazov"};
    book books[COUNT]; 
    for (int i = 0; i < COUNT; i++){    
        strcpy(books[i].name, names[i]);  
        strcpy(books[i].author, authors[i]);  
        books[i].pages = randInt(345,351);   
        books[i].price = randDouble(22.0,2.68);    
    }
   //int (*comp[4])(const void*,const void*) = {strCompName, strCompAuthor,compareInt,compareDouble};
        int option;
        printf("Enter option:\n");
        printf("\n1.Sort by title:\n");
        printf("\n2.Sort by author:\n");
        printf("\n3.Sort by pages:\n");
        printf("\n4.Sort by price:\n");
        printf("\n5.Books information:\n");
        printf("\n6.Search by price:\n");
        printf("\n7.Search by number of pages:\n");
        scanf("%d",&option);


            if(option == 1){
               
                bubbleSort( books, COUNT, sizeof(book), strCompName);
                for (int j = 0; j < COUNT; j++){
                printInfo(books[j]);
                }
            }    
            if(option == 2){
                
                bubbleSort( books, COUNT, sizeof(book), strCompAuthor);
                for (int j = 0; j < COUNT; j++){
                printInfo(books[j]);

                }
            }
            if(option == 3){
                
                bubbleSort( books, COUNT, sizeof(book), compareInt);
                for (int j = 0; j < COUNT; j++){
                printInfo(books[j]);

                }
            }
            if(option == 4){

                bubbleSort( books, COUNT, sizeof(book), compareDouble);
                for (int j = 0; j < COUNT; j++){
                printInfo(books[j]);

                }
            }
            if(option == 5){

                for (int i = 0; i < COUNT; i++){
                printInfo(books[i]);
            }
            }
            if(option == 6){
                book forSearch;
                forSearch.price = 22.5;

                book *booksl = (book*)lsearch(&forSearch, COUNT, books, sizeof(book),compareDouble);
                 if (booksl == NULL){
                printf("Not found!\n");
                } else {
                 printf("\n\nFound:\n");
                printInfo(*booksl);
                }
            }   
            if(option == 7){
                book forSearch;
                forSearch.pages = 350;

                bubbleSort( books, COUNT, sizeof(book), compareInt);

                for (int j = 0; j < COUNT; j++){
                printInfo(books[j]);
                } 

                book *books1 = bsearch(&forSearch, books, COUNT, sizeof(book), compareInt);

                if (books1 == NULL){
                printf("Not found!\n");
                } else {
                 printf("\n\nFound:\n");
                printInfo(*books1);
                }   
            }    

    return 0;
}

double randDouble(double min, double max){
    return min + ((double)rand() / RAND_MAX) * (max - min);
}
int randInt(int min, int max){
    return min + rand() % (max -min + 1); // [min; max]
}
void printInfo(book books){
   
    printf("Name:   %s,     ", books.name);
    printf("Author: %s,     ", books.author);
    printf("Pages:  %d,     ", books.pages);
    printf("Price:  %.2lf\n", books.price);
}
void bubbleSort(void* arr, size_t n, size_t size, int (*comp)(const void*,const void*)){
   for (int i = 0; i < n; i++){
       for (int j = 0; j < (n-i-1) * size; j += size){
           if (comp(arr + j, arr + j + size) > 0){
              swapg(arr + j, arr + j + size, size);
             
           }
       }
   }
}
int strCompName(const void* book1, const void* book2){
    book* bookn = (book*)book1;
    book* bookm = (book*)book2;
    char name1 = *bookn->name;
    char name2 = *bookm->name;

    if (name1 == name2) {
        return 0;
    } else if (name1 < name2){
        return 1;
    } else {
        return -1;
    }

}
int strCompAuthor(const void* book1, const void* book2){
    book* bookn = (book*)book1;
    book* bookm = (book*)book2;
    char author1 = *bookn->author;
    char author2 = *bookm->author;

    if (author1 == author2) {
        return 0;
    } else if (author1 > author2){
        return 1;
    } else {
        return -1;
    }
}
int compareInt(const void* book1, const void* book2){
    book* bookn = (book*)book1;
    book* bookm = (book*)book2;
    int  pages1 = bookn->pages;
    int  pages2 = bookm->pages;

    if (pages1 == pages2) {
        return 0;
    } else if (pages1 > pages2){
        return 1;
    } else {
        return -1;
    }
}
int compareDouble(const void* book1, const void* book2){
    book* bookn = (book*)book1;
    book* bookm = (book*)book2;
    double price1 = bookn->price;
    double price2 = bookm->price;

    if (fabs((price1-price2) < 0.001)) {
        return 0;
    } else if (price1 > price2){
        return 1;
    } else {
        return -1;
    }
}
void swapg (void *book1, void *book2, size_t size){
    u_int8_t arr[size];
    memmove(arr, book1, size);
    memmove(book1, book2, size);
    memmove(book2, arr, size);
}
void *lsearch(void *key, size_t count, void* arr, size_t size, int (*comp)(const void* a, const void* b)){
    for (int i = 0; i < (size*COUNT); i+=size){
        if (comp(arr+i,key) == 0){
            return arr + i;
        }
    };
    return NULL;
}
