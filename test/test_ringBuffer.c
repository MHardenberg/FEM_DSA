#include <stdio.h>
#include "../src/ringBuffer.h"

#define LOG(fmt, x) (fprintf(stderr, fmt, x))



int main (int argc, char *argv[]) {
    LOG("%s\n", "Hello!");
    return 0;
}
