#include <stdio.h>
#include "../src/ringBuffer.h"

#define LOG(fmt, x) (fprintf(stderr, fmt, x))



char chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main (int argc, char *argv[]) {
    struct RingBuffer *rb = createRINGBUFFER(10, sizeof(char));
    char *elem = malloc(sizeof(char));


    for (size_t i = 0; i < 14; ++i) {
        RINGBUFFER_add(rb, &chars[i]);
        RINGBUFFER_peek(rb, elem);
        LOG("peek: %c\t\t", *elem);
        LOG("length: %li\t\t", rb->length);
        LOG("cap: %li\t\t", rb->capacity);

        LOG("head: %li\t\t", rb->head_idx);
        LOG("tail: %li\n", rb->tail_idx);

    }
    LOG("%s\n", "-------------------------");


    for (size_t i = 0; i < 14; ++i) {
        if(RINGBUFFER_pop(rb, elem)) {*elem = ' ';};

        LOG("pop: %c\t\t", *elem);
        if(RINGBUFFER_peek(rb, elem)) {*elem = ' ';};
        LOG("peek: %c\t\t", *elem);
        LOG("length: %li\t\t", rb->length);
        LOG("cap: %li\t\t", rb->capacity);

        LOG("head: %li\t\t", rb->head_idx);
        LOG("tail: %li\n", rb->tail_idx);
    }


    free_RINGBUFFER(rb);
    free(elem);
    return 0;
}
