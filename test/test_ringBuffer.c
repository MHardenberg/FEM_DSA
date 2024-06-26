#include <stdio.h>
#include "../src/ringBuffer.h"

#define LOG(fmt, x) (fprintf(stderr, fmt, x))

char chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main (int argc, char *argv[]) {
    struct RingBuffer *rb = createRINGBUFFER(10, sizeof(char));
    for (size_t i = 0; i < 14; ++i) {
        RINGBUFFER_add(rb, &chars[i]);
        LOG("length: %li\t", rb->length);
        LOG("cap: %li\n", rb->capacity);
    }
    LOG("%s\n", "-------------------------");


    char *elem = malloc(sizeof(char));
    for (size_t i = 0; i < 14; ++i) {
        RINGBUFFER_pop(rb, elem);
        LOG("elem: %c\t", *elem);
        LOG("length: %li\t", rb->length);
        LOG("cap: %li\n", rb->capacity);
    }
    free(elem);
    free_RINGBUFFER(rb);
    return 0;
}
