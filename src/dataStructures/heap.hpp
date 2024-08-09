#ifndef heap_H
#define heap_H

#include <cstddef>
#include <vector>

template<typename T>
struct MinHeap {
std::vector<T> data;
size_t length() {
    return this->data.size();
}

void insert(T value) {
    this->data.push_back(value);
    this->heapifyUp(this->length() - 1);
}

void pop(T& dest) {
    if (this->length() == 0) {
        return;
    }

    dest = this->data[0];
    if (this->length() == 1) {
        this->data.pop_back();
        return;
    }

    this->data[0] = this->data[this->length() - 1];
    this->data.pop_back();
    this->heapifyDown(0);
}

private:
     inline size_t parent(const size_t idx) const {
            return (idx - 1)/2;
     }
     inline size_t childLeft(const size_t idx) const {
            return 2 * idx + 1;
     }
     inline size_t childRight(const size_t idx) const {
            return 2 * idx + 2;
     }

     void heapifyUp(const size_t currentIdx) {
         if (currentIdx == 0) {
             return;
         }

         const T currentVal = this->data[currentIdx];

         const size_t parentIdx = this->parent(currentIdx);
         const T parentVal = this->data[parentIdx];

         if (parentVal > currentVal) {
            // swap node values
            this->data[currentIdx] = parentVal;
            this->data[parentIdx] = currentVal;

            heapifyUp(parentIdx);
         }
     }

     void heapifyDown(const size_t currentIdx) {
         if (currentIdx >= this->length()) {
            return;
         }

         const size_t lIdx = this->childLeft(currentIdx);
         if (lIdx >= this->length()) {
             return;
             // out of children!
         }
         const size_t rIdx = this->childRight(currentIdx);
         const T currentVal = this->data[currentIdx];



         T minValue;
         size_t minIdx;

         // check if right child exists
         //
         if (rIdx >= this->length()) {
             minValue = this->data[lIdx];
             minIdx = lIdx;
         }
         // if left child is the lesser 
         else if (
                 this->data[lIdx] <= this->data[rIdx]
                 ){
             minValue = this->data[lIdx];
             minIdx = lIdx;
         }
         // if right child is the lesser
         else {
             minValue = this->data[rIdx];
             minIdx = rIdx;

         }
            
         if (minValue < currentVal) {
             this->data[currentIdx] = minValue;
             this->data[minIdx] = currentVal;
            this->heapifyDown(minIdx);
         }
     }
};



#endif // !heap_H
