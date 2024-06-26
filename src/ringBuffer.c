#include "ringBuffer.h"


struct RingBuffer *createRINGBUFFER(size_t capacity, size_t elementSize) {
    if (capacity < 3) {
        fprintf(stderr, "%s\n", "Buffer capacity too small.");
        capacity = 10;
    }

    void *data = malloc(capacity * elementSize);
    if (!data) {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    
    struct RingBuffer *rb = (struct RingBuffer *) malloc(sizeof(struct RingBuffer));
    if (!rb) {
        free(data);
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }

    rb->data = data;
    rb->capacity = capacity;
    rb->elementSize = elementSize;
    rb->length = 0;
    rb->head_idx = 0;
    rb->tail_idx = 0;

    return rb;
}


void free_RINGBUFFER(struct RingBuffer *rb) {
    if (rb) {
        free(rb->data);
        free(rb);
    }
}


int resize_RINGBUFFER(struct RingBuffer *rb, size_t growBy) {
    size_t newCapacity = rb->capacity + growBy;
    void *newData = malloc(newCapacity * rb->elementSize);
    if (!newData) {
        fprintf(stderr, "%s\n", "Allocation Error in resizeRINGBUFFER");
        return 1;
    }


    for (size_t i = 0; i < rb->length; i++) {
        size_t idx = (rb->head_idx + i) % rb->capacity;
        memcpy((char *)newData + i * rb->elementSize,
                (char *)rb->data + idx * rb->elementSize,
                rb->elementSize);
    }
    free(rb->data);
    rb->data = newData;
    rb->capacity = newCapacity;
    rb->head_idx = 0;
    rb->tail_idx = rb->length;

    return 0;
}


int RINGBUFFER_add(struct RingBuffer *rb, void *elem) {
    if (!elem) {return 1;}
    if (rb->length == rb->capacity) {
        if (resize_RINGBUFFER(rb, rb->length)) {return 1;}   
    }

    memcpy(
        (char *)rb->data + rb->tail_idx * rb->elementSize,
        elem,
        rb->elementSize
        );

    rb->tail_idx = (rb->tail_idx + 1) % rb->capacity;
    rb->length++;
    return 0;
}


void RINGBUFFER_peek(struct RingBuffer *rb, void *elemBuffer) {
    if (rb->length == 0) {return;}
    if (!elemBuffer) {
        fprintf(stderr, "No element buffer provied\n");
    }

    memcpy(
        elemBuffer,
        (char *)rb->data + rb->head_idx * rb->elementSize,
        rb->elementSize
        );
}


void RINGBUFFER_pop(struct RingBuffer *rb, void *elemBuffer) {
    if (rb->length == 0) {return;}
    if (!elemBuffer) {
        fprintf(stderr, "No element buffer provied\n");
        return;
    }

    memcpy(
        elemBuffer,
        (char *)rb->data + rb->head_idx * rb->elementSize,
        rb->elementSize
        );

    rb->head_idx = (rb->head_idx + 1) % rb->capacity;
    rb->length--;
}
