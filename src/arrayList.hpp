#ifndef arrayList
#include <cstring>
#include <cstdlib>
#include <cmath>


template<typename T>
struct ArrayList {
    T *data;
    size_t lenght;
    size_t capacity;

    ArrayList(size_t capacity = 10) {
        this->lenght = 0;
        this->capacity = capacity;
        data = (T*) malloc(this->capacity * sizeof(T));
    }

    ~ArrayList() {
        free(this->data);
    };

    int grow(size_t growBy) {
            T* newData = (T*) malloc((this->capacity + growBy) * sizeof(T));

            if (!newData) {return 1;}

            memcpy(newData, data, sizeof(T) * this->lenght);
            free(data);
            this->capacity += growBy;
            this->data = newData;

            return 0;
        }

    int push(T x) {
        if (this->lenght >= this->capacity) {
            if(this->grow(1 + sqrt(this->lenght))) {
                return 1;
            };
        }

        this->data[this->lenght] = x;
        this->lenght++;
        return 0;
    }

    T* operator[](size_t i) {
       if (i < lenght) {
            return this->data + i;
       } 
       return NULL;
    }
};

#endif // !arrayList
#define arrayList
