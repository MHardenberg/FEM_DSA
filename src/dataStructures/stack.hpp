#include <cstdlib>

template<typename T>
struct Node {
    T data;
    Node<T> *prev_ptr;
};


template<typename T>
struct Stack {
    Node<T> *head_ptr = nullptr;
    Node<T> *tail_ptr = nullptr;
    size_t length = 0;

    Stack() {};

    ~Stack() {
        Node<T> *node = this->tail_ptr;
        while (node) {
            Node<T> *current = node;
            if (node->prev_ptr) {
                node = node->prev_ptr;
            }

            delete current;
            // length will be discraded either way
        }
    }

    void push(T data) {
        Node<T> *node_ptr = new Node<T>();
        // previous to last tail
        node_ptr->prev_ptr = this->tail_ptr;
        node_ptr->data = data;

        // update tail
        this->tail_ptr = node_ptr;
        if (!this->head_ptr) {
            // if this is the first node
            head_ptr = node_ptr;
        }

        this->length++;
    }

    T pop() {
        // extract current tail
        Node<T> *lastTail_ptr = this->tail_ptr;
        T data;

        if (lastTail_ptr) {
           data = lastTail_ptr->data;
        }

        // update tail
        this->tail_ptr = this->tail_ptr->prev_ptr;
        if (!this->tail_ptr) {
            this->head_ptr = nullptr;
        }

        // release previous tail
        delete lastTail_ptr;
        this->length--;

        return data;
    }

    const T *peek() const {
        if (this->tail_ptr) {
            return &this->tail_ptr->data;
        }

        return nullptr;
    }
};
