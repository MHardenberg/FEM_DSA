#include <iostream>
#include "../src/dataStructures/heap.hpp"
#define LOG(x) (std::cout << x)
#define LOGLN(x) (std::cout << x << std::endl)



int main (int argc, char *argv[]) {

    MinHeap<int> heap;
    for (size_t i = 15; i > 0; i--) {
        heap.insert(i);
    }
    
    for (auto x: heap.data) {
        LOG(x);
        LOGLN("");
    }

    LOGLN("------------------");
    int dest;
    while(heap.length()) {
        for (auto x: heap.data) {
            LOG(x);
            LOGLN("");
        }

        heap.pop(dest);
        LOG("Popped: ");
        LOGLN(dest);
    }

    return 0;
}
