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
    struct book* next;
    
} book;

void printBook(book*);
void push(book**);
void freeList(book**);
struct book* SortedMerge(struct book* a, struct book* b);
void FrontBackSplit(struct book*, struct book**, struct book**);
void MergeSort(struct book**);

int main(int argc, char** argv){
    
    book* books = NULL;

    FILE* fp = fopen(argv[1],"r");
    if(NULL == fp){
        perror("Error: \n");
        return EXIT_FAILURE;
    }
        for(int i = 0; i < COUNT; i++){
            fread(&books,sizeof(book),COUNT,fp);
            book *books = malloc(sizeof(book));
            push(&books);
            printBook(books);
        }
 
    
    fclose(fp);
   
   // MergeSort(&head);
     printBook(books);
   // freeList(&head);



return 0;
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
    strcpy(books->name, (*head)->name);
    strcpy(books->author, (*head)->author);
    books->pages = (*head)->pages;
    books->price = (*head)->price;
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
/*
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
 */