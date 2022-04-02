#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
    struct node* prev;
  
}nodeDeque;

void pushFirst(nodeDeque** head, int data);
void pushBack(nodeDeque** head, int data);
void popFirst(nodeDeque** head);
void popBack(nodeDeque** head);
void printDeque(nodeDeque* head);

int main(void){

nodeDeque* head = NULL;
pushFirst(&head, 5);
pushFirst(&head, 6);
pushFirst(&head, 7);
printDeque(head);
popFirst(&head);
printDeque(head);
pushBack(&head,8);
printDeque(head);
popBack(&head);
printDeque(head);
return 0;

}
void pushFirst(nodeDeque** head, int data){
nodeDeque* node = malloc(sizeof(nodeDeque));
if(!node){
     fprintf(stderr,"Error! Problem with memory allocation!");
     exit(-1);
}
node->data = data;
node->next = *head;
node->prev = NULL;
if(*head != NULL){
    (*head)-> prev = node;
}
*head = node;
}
void pushBack(nodeDeque** head, int data){
nodeDeque* node = malloc(sizeof(nodeDeque));
nodeDeque* current = *head;
nodeDeque* tail;
if(!node){
     fprintf(stderr,"Error! Problem with memory allocation!");
     exit(-1);
}
if (current == NULL) {
        *head = node;
    }
    else {
      
        while (current->next != NULL) {
            current = current->next;
        }
 
        current->next = node;
        node->prev = current;
        node->data = data;
        node->next = NULL;
    }
}

void printDeque(nodeDeque* head){
nodeDeque* current = head;

while (current != NULL)
{
    printf("%d\n",current->data);
    current = current->next;
}
putchar('\n');

}
void popFirst(nodeDeque** head){
    if (*head == NULL){
        return;
    }
    *head = (*head)->next;

    free((*head)->prev);

    (*head)->prev = NULL;   
}
void popBack(nodeDeque** head){
    nodeDeque* current = (*head);
    if (*head == NULL){
        return;
    }
    while (current->next != NULL) {
            current = current->next;
        };

    current->prev->next = NULL;
    free(current);
       
}