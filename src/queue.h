#ifndef queue_H
#define queue_H
#include <stdio.h>
#include "llist.h"


struct Queue {
    struct Node *head_ptr;
    struct Node *tail_ptr;
    size_t number;
};

static inline void printQueue(struct Queue *queue_ptr) {
    printLList((struct LList*) queue_ptr);
}

struct Queue *createQueue();

void freeQueue(struct Queue *queue_ptr);

int QueueEnqueue(struct Queue *queue_ptr, int item);

int* QueuePeek(struct Queue *queue_ptr);

int* QueueDeque(struct Queue *queue_ptr);



#endif // !queue_H
