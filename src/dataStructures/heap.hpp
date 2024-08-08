#ifndef heap_H
#define heap_H

#include <cstddef>
#include <vector>

template<typename T>
struct MinHeap {
 std::vector<T> data;
 size_t length() {
    return this->data.size();
 };

 void insert(T value);

 private:
     inline size_t parent(size_t idx) {
            return (idx - 1)/2;
     }
     inline size_t childLeft(size_t idx) {
            return 2 * idx + 1;
     }
     inline size_t childRight(size_t idx) {
            return 2 * idx + 2;
     }

     void heapifyUp() {

     }

     void heapifyDown() {

     }
};



#endif // !heap_H
