#include <cstddef>
#include <cstdlib>
#include <stdio.h>
#include <string.h>


struct RingBuffer {
 void *data;
 size_t capacity, elementSize, length;
 void *head_ptr, *tail_ptr;

};

struct RingBuffer createRingBuffer(size_t capacity, size_t elementSize) {
    if (capacity < 3) {
        fprintf(stderr, "%s\n", "Buffer capacity too small.");
        capacity = 10;
    }
    
    void *data = malloc(capacity * elementSize);
    // convert to ptr of byte sized and increment by elementSize.
    void *head_ptr = (char *)data + elementSize * capacity/3;

    struct RingBuffer rb = {
        .data = data,
        .capacity = capacity,
        .elementSize = elementSize,
        .length = 0,
        .head_ptr = head_ptr,
        .tail_ptr = head_ptr,
    };


    return rb;
}


void freeRingBuffer(struct RingBuffer *rb) {
    free(rb->data);
    free(rb);
}


int resizeRingBuffer(struct RingBuffer *rb, size_t growBy) {
    size_t newCapacity = rb->capacity + growBy;
    void *newData = malloc(newCapacity * rb->elementSize);
    void *newHead = (char *)newData + newCapacity/3 * rb->elementSize;
    if (!newData) {
        fprintf(stderr, "%s\n", "Allocation Error in resizeRingBuffer");
        return 1;
    }

    memcpy(newHead, rb->head_ptr, rb->length * rb->elementSize);
    free(rb->data);

    rb->data = newData;
    rb->head_ptr = newHead;
    rb->tail_ptr = (char *)newHead + rb->length*rb->elementSize;
    rb->capacity = newCapacity;
    return 0;
}

