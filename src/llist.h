#ifndef llist_H
#define llist_H

#include "stdlib.h"
#include <memory.h>
#include <stdio.h>

struct Node {
    int data;
    struct Node* next;
};

struct LList {
    struct Node *head_ptr;
    struct Node *tail_ptr;
    size_t length;
};

static inline void printLList(struct LList *list_ptr) {
    struct Node *node_ptr = list_ptr->head_ptr;
    while (node_ptr != NULL) {
        printf("%d ", node_ptr->data);
        node_ptr = node_ptr->next;
    }
    printf("No. items: %li\n", list_ptr->length);
    printf("\n");
}

struct LList *createLList();

struct Node *LListGetItem(struct LList *list_ptr, size_t pos);

int LListAppendNode(struct LList *list_ptr, int data);

int LListInsertNode(struct LList *list_ptr, size_t pos, int data);

int LListDeleteNode(struct LList *list_ptr, size_t pos);

void freeLList(struct LList *list_ptr);

#endif // !llist_H
