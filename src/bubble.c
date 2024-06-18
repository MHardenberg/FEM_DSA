#include "bubble.h"

void bubbleSort(int *array, size_t lenght) {
    while (lenght > 0){
        for (size_t pos = 0; pos < lenght - 1; ++pos){
            if (array[pos] > array[pos+1]){
                // XOR swap
                array[pos] = array[pos] ^ array[pos+1];
                array[pos+1] = array[pos] ^ array[pos+1];
                array[pos] = array[pos] ^ array[pos+1];
            }
        }
        --lenght;
    }
}
