#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <semaphore.h>
#include <signal.h>

#define COUNT 10
#define BUFFER 10
int ProducersN = 5;
int ConsumersN = 6;
 

int randInt(int, int);
double randDouble(double, double);

enum desc{Bulgaria, Greek, Turkey, Romania, Serbia};

typedef struct fruits {
    int barcode;
    enum desc origin;
    float price;
    struct fruits *next;
} fruits;

int buffer[BUFFER];
int i = 0;

sem_t freePos;
sem_t busyPos;
pthread_mutex_t mux;
fruts* head = NULL;


fruits* push(fruits** head){
    srand(time(NULL));
    enum desc ds = randInt(1,5);
    fruits* element = malloc(sizeof(fruits));
    element->barcode = randInt(1,50); 
    element->origin = ds;
    element->price = randDouble(0.5,10);
    element->next = *head;
    *head = element;
    return element;
}
fruits* deleteNth(fruits** list, size_t n){
    fruits* element = malloc(sizeof(fruits));
    element = list;

    if (*list == NULL){
        return;
    }
    if (n == 0){
        fruits* temp = *list;
        *list = (*list)->next;
        free(temp);
        return;
    }
    fruits* current = *list;
    fruits* prev = current;
    while (current && n--) {
        prev = current;
        current = current->next;
    }
    prev->next = current->next;
    free(current);
    return list;
}

void* producer(void* args){

    while (1){
        int x = rand() % 20;
        sleep(1);
        sem_wait(&freePos);
        pthread_mutex_lock(&mux);
        fruits* New = malloc(sizeof(fruits));
        New = push(&head);
        buffer[i++] = x;
        pthread_mutex_unlock(&mux);
        sem_post(&busyPos);
        printf("New product: Barcode: %d Origin: %d Price: %lf\n ", 
        New.barcode, New.origin, New.price);
        free(New);
    }
}

void* consumer(void* args){
    while(1){
        int x;
        sleep(1);
        sem_wait(&busyPos);
        pthread_mutex_lock(&mux);
        fruits* Nth = malloc(sizeof(fruits));
        Nth = deleteNth(&head,randInt(0,9));
        x = buffer[--i];
        pthread_mutex_unlock(&mux);
        sem_post(&freePos);
        printf("Bought product: Barcode: %d Origin: %d Price: %lf\n ",
        Nth.barcode, Nth.origin, Nth.price);
        free(Nth);
    }
}

void* writetofile(fruits** list){
    FILE *fp;
    fp = fopen("store.data", "wb");
    while(head) {
    fruits* fruit1 = malloc(sizeof(fruits));
    fwrite(&fruit1, sizeof(struct fruits), 1, fp);

}

int main(int argc, char *argv[]){

    for(int i = 0; i < COUNT; i++){
        push(&head);
    }
    sem_init(&freePos, 0, BUFFER);
    sem_init(&busyPos, 0, 0);
    pthread_mutex_init(&mux, NULL);
    pthread_t th[COUNT];
    for (int i = 0; i < ProducersN; i++){
            if (pthread_create(th + i, NULL, producer, NULL) != 0){
                perror("create");
                return EXIT_FAILURE;
            }
    }
    for (int i = 0; i < ConsumersN; i++){
            if (pthread_create(th + i, NULL, consumer, NULL) != 0){
                perror("create");
                return EXIT_FAILURE;
            }
    }

    for (int i = 0; i < COUNT; i++){
        if (pthread_join(th[i], NULL) != 0){
            perror("join");
            return EXIT_FAILURE;
        }    
    }
    signal(SIGINT,SIG_IGN);

    writetofile(&head);
 
    pthread_mutex_destroy(&mux);
    sem_destroy(&freePos);
    sem_destroy(&busyPos);
    
    return EXIT_SUCCESS;
}

int randInt(int min, int max){
    return min + rand() % (max -min + 1); // [min; max]
}
double randDouble(double min, double max){
    return min + ((double)rand() / RAND_MAX) * (max - min);
}