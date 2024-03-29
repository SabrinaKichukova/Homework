#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include<errno.h>

#define COUNT 5

typedef struct book
{
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

int main(int argc, char** argv)
{    
    book* books = NULL;

    FILE* fp = fopen(argv[1], "r");
    if (NULL == fp)
    {
        perror("Error: \n");
        return EXIT_FAILURE;
    }
    for (int i = 0; i < COUNT; i++)
    {
        fread(&books, sizeof(book), COUNT, fp);
        book *books = malloc(sizeof(book));
        push(&books);
        printBook(books);
    }

    fclose(fp);
    printBook(books);
    return 0;
}

void printBook(book* head)
{
    while (head != NULL) 
    {
        printf("Title: %s\n", head->name);
        printf("Author: %s\n", head->author);
        printf("Pages: %d\n", head->pages);
        printf("Price: %.2f\n", head->price);
        printf("\n");
        head = head->next;
    }    
}

void push(book** head)
{
    book* books = malloc(sizeof(book));
    if (!books)
    {
         fprintf(stderr, "Error! Problem with memory allocation!");
         exit(-1);
    }
    books->next = (*head);
    strcpy(books->name, (*head)->name);
    strcpy(books->author, (*head)->author);
    books->pages = (*head)->pages;
    books->price = (*head)->price;
    (*head) = books;
}

void freeList(book** head)
{
    book* current = (*head);
    while (current != NULL)
    {
        book* temp = current;
        current = current->next;
        free(temp);
    }
    *head = NULL;
}
