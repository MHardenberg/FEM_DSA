#include <stdio.h>
#include "../src/queue.h"


int main() {
    struct Queue *queue_ptr = createQueue();

    printf("Queue:\n");
    printQueue(queue_ptr);

    printf("Enqueue (Should be same):\n");
    for (size_t i = 0; i < 12; ++i) {
        QueueEnqueue(queue_ptr, i);
        printf("%li, ", i);
    }

    printf("\n\nPeek (Should be same):\n");
    for (size_t i = 0; i < 12; ++i) {
        int *item = QueuePeek(queue_ptr);
        if (item) {
            printf("%i, ", *item);
        }
    }

    printf("\n Queue:\n");
    printQueue(queue_ptr);

    printf("\nPeek (Should be same):\n");
    int *item;
    do {
        item = QueueDeque(queue_ptr);
        if (item) {
            printf("%i, ", *item);
        }
        free(item);

    } while (item);

    printf("\n Queue:\n");
    printQueue(queue_ptr);

    freeQueue(queue_ptr);
    return 0;
}
