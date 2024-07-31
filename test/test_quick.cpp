#include <iostream>
#include "../src/quick.hpp"

#define LOG(x) std::cout << x
#define LOGLN(x) std::cout << x << std::endl
#define LOGARRAY(array, length) for (size_t i = 0; i < length; ++i)\
{LOG(array[i]); LOG(", ");} LOG(std::endl)


int main (int argc, char *argv[]) {
    int arr[12] = {3, 4, 1, 2, 6, 8, 1, 0, 11, 15, 5, 7};
    LOGARRAY(arr, 12);
    quickSort(arr, 12);
    LOGARRAY(arr, 12);
    return 0;
}
