#include "queue.h"
#include "llist.h"

struct Queue *createQueue() {
    struct Queue *queue_ptr = (struct Queue*)createLList();
    return queue_ptr;
}

void freeQueue(struct Queue *queue_ptr) {
    freeLList((struct LList*) queue_ptr);
}

int QueueEnqueue(struct Queue* queue_ptr, int item) {
    if (queue_ptr == NULL){
        fprintf(stderr, "Error: NULL pointer\n");
        return 1;
    }
    return LListAppendNode((struct LList*) queue_ptr, item);
}


int* QueuePeek(struct Queue* queue_ptr) {
    int *item = NULL;
    if (queue_ptr == NULL){
        fprintf(stderr, "Error: NULL pointer\n");
        return NULL;
    }

    struct Node *node = LListGetItem((struct LList*) queue_ptr, 0);
    item = &node->data;
    return item;
}


int* QueueDeque(struct Queue* queue_ptr) {
    int *peek = QueuePeek(queue_ptr);
    if (peek == NULL) {
        return NULL;
    }
    
    int *item = malloc(sizeof(peek));
    if (item == NULL) {
        return NULL;
    }

    // copy data
    *item = *peek;
    LListDeleteNode((struct LList*) queue_ptr, 0);

    return item;
}
