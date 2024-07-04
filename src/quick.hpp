#include <cstddef>
#include <iostream>
#define LOG(x)(std::cout << x)
#define LOGLN(x)(std::cout << x << std::endl)



template<typename T>
size_t partition(T* array, size_t lo, size_t hi) {
    const T pivot = array[hi];
    size_t idx = lo;

    for (size_t i = lo; i < hi; ++i) {
        if (array[i] <= pivot) {
            array[idx] = array[i] ^ array[idx];
            array[i] = array[idx] ^ array[i];
            array[idx] = array[i] ^ array[idx];

            ++idx;
        }
    }

    array[hi] = array[idx];
    array[idx] = pivot;


    return idx;
}


template<typename T>
int quickSort(T* array, size_t length) {
    
    
    size_t pivot = length/2,
           low = 0,
           high = length - 1;









    for (size_t i = 0; i < length; ++i) {
        LOG(array[i] << " ");
    }
    LOG(std::endl);
    return 0;
}
