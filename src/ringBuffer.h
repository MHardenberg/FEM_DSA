#ifndef RingBuffer_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct RingBuffer {
 void *data;
 size_t capacity, elementSize, length,
        head_idx, tail_idx;
};


struct RingBuffer *createRINGBUFFER(size_t capacity, size_t elementSize);

void free_RINGBUFFER(struct RingBuffer *rb);

int resize_RINGBUFFER(struct RingBuffer *rb, size_t growBy);

int RINGBUFFER_add(struct RingBuffer *rb, void *elem);

void RINGBUFFER_peek(struct RingBuffer *rb, void *elemBuffer);

void RINGBUFFER_pop(struct RingBuffer *rb, void *elemBuffer);

#endif // !RingBuffer_H
#define RingBuffer_H

