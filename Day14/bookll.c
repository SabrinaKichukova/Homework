#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define COUNT 5

typedef struct book{
    char name[150];
    char author[100];
    int  pages;
    double price;
    struct book* next;
} book;

double randDouble(double, double);
int randInt(int, int);
void printBook(book*);
void push(book**);
void freeList(book**);
struct book* SortedMerge(struct book* a, struct book* b);
void FrontBackSplit(struct book*, struct book**, struct book**);
void MergeSort(struct book**);

int main(void){
    book* head = NULL;
    srand(time(NULL)); 
    
    for (int i = 0; i < COUNT; i++){
        push(&head);
    }   
    
    MergeSort(&head);
    printBook(head);
    freeList(&head);
         
return 0;
}

double randDouble(double min, double max){
    return min + ((double)rand() / RAND_MAX) * (max - min);
}
int randInt(int min, int max){
    return min + rand() % (max -min + 1); // [min; max]
}

void printBook(book* head){

     while (head != NULL) {
    printf("Title: %s\n",head->name);
    printf("Author: %s\n",head->author);
    printf("Pages: %d\n",head->pages);
    printf("Price: %.2f\n",head->price);
    printf("\n");
    head = head->next;
    }    
}


void push(book** head){
book* books = malloc(sizeof(book));
if(!books){
     fprintf(stderr,"Error! Problem with memory allocation!");
     exit(-1);
}
books->next = (*head);

int name_length = 4 + rand() % 7;
for (int j = 0; j < name_length; j++)
    {
        char rand_lowercase = 'a' + rand() % ('z' - 'a' + 1);
        char rand_uppercase = 'A' + rand() % ('Z' - 'A' + 1);
        int random_bit = rand() % 2;
 
        if (random_bit)
        {
            books->name[j] = rand_lowercase;
        }
        else
        {
            books->name[j] = rand_uppercase;
        }    
    }
        books->name[name_length] = '\0';

int author_length = 4 + rand() % 7;
for (int j = 0; j < author_length; j++)
    {
        char rand_lowercase = 'a' + rand() % ('z' - 'a' + 1);
        char rand_uppercase = 'A' + rand() % ('Z' - 'A' + 1);
        int random_bit = rand() % 2;
 
        if (random_bit)
        {
            books->author[j] = rand_lowercase;
        }
        else
        {
            books->author[j] = rand_uppercase;
        }    
    }
    books->author[author_length] = '\0';
    books->pages = randInt(5,2000);   
    books->price = randDouble(1.0,1000);
    (*head) = books;   

}

void freeList(book** head){
    book* current = (*head);
    while (current != NULL){
        book* temp = current;
        current = current->next;
        free(temp);
    }
    *head = NULL;
}

void MergeSort(struct book** head)
{
    struct book* head1 = *head;
    struct book* a;
    struct book* b;
 
    if ((head1 == NULL) || (head1->next == NULL)) {
        return;
    }
 
    FrontBackSplit(head1, &a, &b);
 
    
    MergeSort(&a);
    MergeSort(&b);
 
   
    *head = SortedMerge(a, b);
}

struct book* SortedMerge(struct book* a, struct book* b)
{
    struct book* result = NULL;
 
    
    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);
 
    
    if (strcmp(a->name,b->name) <=0 ) {
        result = a;
        result->next = SortedMerge(a->next, b);
    }
    else {
        result = b;
        result->next = SortedMerge(a, b->next);
    }
    return (result);
}

void FrontBackSplit(struct book* head,struct book** frontRef, struct book** backRef)
{
    struct book* fast;
    struct book* slow;
    slow = head;
    fast = head->next;
 
    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }
 
    *frontRef = head;
    *backRef = slow->next;
    slow->next = NULL;
}
 