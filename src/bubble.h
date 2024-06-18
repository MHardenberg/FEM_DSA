#ifndef bubble_H

#include <stdlib.h>
#include <stdio.h>
static const size_t BUFF_SIZE = 1000;

static inline void printArray(int *array, size_t lenght) {
    for (size_t i = 0; i < lenght; ++i ){
            printf("%d ", array[i]);
        }
        printf("\n");
}

void bubbleSort(int *array, size_t lenght);

#endif // !bubble_H
#define bubble_H
