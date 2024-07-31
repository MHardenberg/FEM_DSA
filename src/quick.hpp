#include <cstddef>
//#define SWAP(x, y) x = y ^ x; y = x ^ y; x = y ^ x
#define SWAP(x, y) {auto temp = x; x = y; y = temp;}


template<typename T>
static size_t partition(T* array, size_t lo, size_t hi) {
    const T pivot = array[hi];
    size_t idx = lo;

    for (size_t i = lo; i < hi; ++i) {
        if (array[i] <= pivot) {
            SWAP(array[idx], array[i]);
            ++idx;
        }
    }

    SWAP(array[idx], array[hi]);
    return idx;
}


template<typename T>
static void qs(T* array, size_t lo, size_t hi) {
    if (lo >= hi) {
        return;
    }

    const size_t pivotIdx = partition(array, lo, hi);
    if (pivotIdx > lo) {
        qs(array, lo, pivotIdx - 1);
    }
    qs(array, pivotIdx + 1, hi);
}


template<typename T>
void quickSort(T* array, size_t length) {
    size_t low = 0,
           high = length - 1;
    
    qs(array, low, high);
}
